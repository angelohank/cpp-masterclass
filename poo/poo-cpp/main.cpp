#include <stdio.h>

// se as variaveis andam em conjunto, faz sentido englobar eles em um mesmo escopo
// para isso se usam as structs

/* limitacoes da emulaçao de POO em C
 * 1 - nao tem como forçar a inicialaçao, entao ele pode chamar um print antes de inicializar, vai imprimir lixo
 * 2 - todas as propriedades sao publicas
 * 3 - as funcoes sao como outras quaisquer, nao estao ligadas diretamente à struct
 * 4 - repete a palavra Struct sempre (c++ nao precisa)
 * 5 - c++ permite o uso de referencias ao inves de endereços
 * 6 - valid tem que ser short ao inves de bool
 */

struct Data {
    // o tamanho da struct é a soma das propriedades dela
    // 3 inteiros = 12 bytes

    void init() { this->isValid = false; }

    void change(int dia, int mes, int ano) {
        this->ano = ano;
        this->mes = mes;
        this->dia = dia;

        isValid = false;
        if ((this->dia >= 1 && this->dia <= 31) && (this->mes >= 1 && this->mes <= 12)) {
            isValid = true;
        }
    }

    void print() const {
        if (isValid) {
            printf("%02d/%02d/%d\n", dia, mes, ano);
        } else {
            printf("Data invalida\n");
        }
    }

  private:
    bool isValid;
    short dia;
    short mes;
    short ano;
};

int main() {

    struct Data dt;
    // initData(&dt);
    // change(&dt, 21, 3, 2001);

    printf("size: %llu\n", sizeof(dt));
    dt.print();
}
