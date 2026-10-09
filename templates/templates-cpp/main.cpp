#include <iostream>

using namespace std;

/*
 * antes eu precisava criar uma funcao para cada tipo de dado que eu queira comparar
 */
// short maximum(short a, short b) {
//     return a > b ? a : b;
// }

/*
 * agora eu troco tudo que for o tipo por um  nome generico (T)
 * e toda classe, ou tipo, que tiver a definicao do operador >, vai passar a funcionar com a mesma funcao
 */
template <class T>
T maximum_old( T a, T b) {
    return a > b ? a : b;
}

/*
 * ao inves da palavra class, posso usar o typename, tem o mesmo resultado
 * fica estranho usar "class", visto que é a palavra reservada para criar classes
 * o efeito é o mesmo
 */
template <typename T>
T maximum( T a, T b) {
    return a > b ? a : b;
}

int main() {

    float x = 11, y = 10;
    float r = maximum(x, y);
    cout << "max: " << r << endl;

    /*
     * usando o mesmo caso em que acontece erro na macro do C
     * nesse caso, retorna 11, de forma correta
     * isso acontece porque o template é resolvido em tempo de compilação, e nao pré-compilação
     */
    float x2 = 11, y2 = 10;
    float r2 = maximum(x2, ++y2);
    cout << "max: " << r2 << endl;

    return 0;
}
