#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vec[3]; //criando um array com 3 inteiros

    cout << sizeof(vec); //12 -> tamanho de um inteiro * 3

    //pode ser redimensionado
    //faz alocação dinamica na heap

    /*
     *
     * PUSH_BACK
    melhor tempo: O(1)
    pior tempo: O(n) -> quando precisa fazer realocação

    quando faz uma realocação, o vector reserva 2 espaços (o dobro do que ele precisa), então, quando é feito um segundo push,
    ele nao realoca novamente, apenas usa a memoria que já alocou anteriormente
    */
    std::vector<int> vector;
    vector.reserve(3);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    cout << vector.size() << endl;

    /*
     * Para evitar toda essa realocação no push_back, pode-se usar o RESERVE
     * que ja deixa o tamanho ok para o que precisa, evitando realocação de memoria, e sempre faz as alocações em tempo O(1)
    */

    return 0;
}
