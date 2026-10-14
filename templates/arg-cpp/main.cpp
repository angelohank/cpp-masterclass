#include <iostream>
#include <stdarg.h>
#include <stdint.h>
using namespace std;
/*
 * funcao criada para acumular valores, recebendo como primeiro argumento a quntatidade de parametros
 */
template <typename T>
T accumulate_old(int nParams, ...) {
    va_list list;
    va_start(list, nParams);
    T result = 0;
    for( int i = 0; i < nParams; i++ ) {
        result += va_arg(list, T);
    }
    va_end(list);
    return result;
}

/*
 * funcao auxiliar
 * retorna o proprio T
 */
template <typename T>
auto accumulate(T value) {
    return value;
}

/*
 * nova funcao, criada para que eu nao precise passar o numero de parametros como primeiro argumento
 * usa a função auxiliar para acumular o valor
 * essa funcionalidade se chama "variadic templates", disponivel a partir do c++ 11
 */
template<typename T, typename... Args>
auto accumulate(T first, Args... args) {
    return first + accumulate(args...);
}


int main() {

    //auto -> deduz o tipo da variavel de acordo com a inicialização

    //nesse caso, se nao for usado o auto no template, ele vai entender que eh um retorno do tipo
    //uint8_t, e nao retorna a soma correta
    auto r = accumulate(uint8_t(1), 1000, 1000, 500, 500, 1000);

    cout << "result: " << r << endl;

    return 0;
}
