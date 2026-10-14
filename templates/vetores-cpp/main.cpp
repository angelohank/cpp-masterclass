#include <iostream>

int main() {
    //int age1, age2, age3, age4, age5;
    int age[50] {}; //inicializando com vazio, tem o mesmo comportamento do for, evitando que os espaços nao populados armazenem lixo

    //evita que as posicoes que nao foram populadas do vetor, armazenem lixo de memoria
    // for (size_t i = 0; i < 50; i++) {
    //     age[i] = 0;
    // }

    age[0] = 12;
    age[1] = 19;
    age[2] = 95;
    age[3] = 52;
    age[4] = 17;

    /*
     * start: 0
     * end: tamanho - 1
     */
    for (size_t i = 0; i < 50; i++) {
        std::cout << age[i] << std::endl;
    }

    return 0;
}