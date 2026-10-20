#include <iostream>
#include <array>
#include <list>
#include <ranges>
#include <vector>
#include <list>
using namespace std;

template <typename T, size_t Size>
class ArrayConstIterator {
public:
    using iterator_category = std::contiguous_iterator_tag; //usado para identicar o iterator de forma continua
    using value_type = T;
    using difference_type = std::ptrdiff_t; //usado para encontrar a distancia entre determinados elementos dentro de um array
    using pointer = const T*;
    using const_reference = const T&;
    using reference = T&;

    constexpr ArrayConstIterator() noexcept  = default;

    constexpr explicit ArrayConstIterator(pointer ptr, size_t offset = 0) noexcept : _ptr(ptr), _offset(offset) {

    }

    [[nodiscard]]constexpr const_reference operator*() const noexcept {
        return _ptr[_offset];
    }

    //pre-fixado -> eh mais performatico que o pos-fixado, pois nao cria temporarios
    constexpr ArrayConstIterator& operator++() noexcept {
        ++_offset;
        return *this;
    }

    //pos-fixado -> menos performatico
    //menos performatico pq sempre vai ter uma copia
    constexpr ArrayConstIterator operator++(int) noexcept {
        ArrayConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    constexpr ArrayConstIterator& operator+=(difference_type offset) noexcept {
        _offset += offset;
        return *this;
    }

    [[nodiscard]]constexpr auto operator<=>(const ArrayConstIterator& other) noexcept {
        return _offset <=> other._offset;
    }

    [[nodiscard]]constexpr bool operator==(const ArrayConstIterator& other) noexcept {
        return *this <=> other == 0;
    }

protected:
    pointer _ptr {nullptr};
    size_t _offset {0};
};

template <typename T, size_t Size>
class Array {
public:
    //criando "apelidos" para as coisas que vamos usar
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = const T*;
    using const_iterator = ArrayConstIterator<T, Size>;

    Array() = default;

    template <typename... Values>
    constexpr Array(Values... values) {
        /*
         * static_assert serve para indicar alguns erros na hora de compilar, deixando mais claras as condicoes
         * sintaxe: static_assert(condicao esperada, mensagem de erro)
         */
        static_assert(sizeof ... (Values) <= Size, "To many initializers"); //aponta erro quando mais elementos do que o indicado sao passados
        static_assert((std::is_constructible_v<Values, T> && ...), "All values must be T"); //aponta erro caso seja passado um tipo que nao pode ser convertido
        const std::array<T, sizeof...(Values)> temp = {values...};
        std::copy(temp.begin(), temp.end(), _elementos);
    }

    //atributo que informa, para quem chamar a função marcada, que nao se deve descartar o retorno dela
    [[nodiscard]] constexpr size_type size() const noexcept {
        return Size;
    }

    constexpr bool empty() const noexcept {
        return Size == 0;
    }

    /*
     * preciso dessa segunda versao do operador por conta de:
     * como o array é passado como const para a maxElement, se nao tiver esse const, ele entende que sera alterado o ponteiro this
     *
     * preciso dessa versao, sem o const, para poder atributir valor às posicoes do array
     */
    [[nodiscard]] constexpr reference operator[](size_type posicao) noexcept {
        return _elementos[posicao];
    }

    /*
     * preciso dessa segunda versao do operador por conta de:
     * como o array é passado como const para a maxElement, se nao tiver esse const, ele entende que sera alterado o ponteiro this
     * e ele é usado para pegar o valor de uma determinada posicao do array, sem atribuir valor, por isso const
     */
    [[nodiscard]] constexpr const_reference operator[](size_type posicao) const noexcept {
        return _elementos[posicao];
    }

    const_iterator begin() const noexcept {
        return const_iterator(_elementos);
    }
    const_iterator end() const noexcept {
        return const_iterator(_elementos, Size);
    }

private:
    T _elementos[Size] {};
};


template <typename T>
auto maxElement( const T& array ) {
    if (array.empty()) {
        throw std::runtime_error("empty array");
    }

    auto maiorElemento = array[0];
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] > maiorElemento) {
            maiorElemento = array[i];
        }
    }

    return maiorElemento;
}

int main() {

    Array<float, 5> ages{12,19,17,95.5,52};
    // std::array<float, 5> ages2{12,19,17,95.5, "52"};
    std::vector<float> ages3{12,19,17,95.5,52};
    std::list<float> ages4{12,19,17,95.5,52}; //list nao tem o operador [] sobrecarregado, entao nao conseguimos obter o valor pelo indice

    const auto res = maxElement(ages4);
    cout << res;

    return 0;
}