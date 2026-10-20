#include <iostream>
#include <array>
#include <ranges>

using namespace std;

template <typename T, size_t Size>
class Array {
public:
    //criando "apelidos" para as coisas que vamos usar
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;

    Array() = default;

    template <typename... Values>
    constexpr Array(Values... values) {
        /*
         * static_assert serve para indicar alguns erros na hora de compilar, deixando mais claras as condicoes
         * sintaxe: static_assert(condicao esperada, mensagem de erro)
         */
        static_assert(sizeof ... (Values) <= Size, "To many initializers"); //aponta erro quando mais elementos do que o indicado sao passados
        static_assert((std::is_constructible_v<Values, T && ...), "All values must be T"); //aponta erro caso seja passado um tipo que nao pode ser convertido
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
    std::array<float, 5> ages2{12,19,17,95.5, "52"};

    const auto res = maxElement(ages);
    cout << res;

    return 0;
}