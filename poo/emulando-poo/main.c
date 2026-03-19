#include <stdio.h>

//se as variaveis andam em conjunto, faz sentido englobar eles em um mesmo escopo
//para isso se usam as structs

/* limitacoes da emulaçao de POO em C
 * 1 - nao tem como forçar a inicialaçao, entao ele pode chamar um print antes de inicializar, vai imprimir lixo
 * 2 - todas as propriedades sao publicas
 * 3 - as funcoes sao como outras quaisquer, nao estao ligadas diretamente à struct
 */

struct Data {
  //o tamanho da struct é a soma das propriedades dela
  //3 inteiros = 12 bytes
  short dia;
  short mes;
  short ano;
  short isValid;

  // essa struct precisa de funcoes especificas pra ela, como tratamentos que limitam o mes, o dia, etc
} Data;

void initData(struct Data* dt) {
    dt->isValid = 0; // false
}

void change(struct Data* dt, int dia, int mes, int ano) {
    dt->ano = ano;
    dt->mes = mes;
    dt->dia = dia;

    dt->isValid = 0;
    if ((dt->dia >= 1 && dt->dia <= 31) && (dt->mes >= 1 && dt->mes <= 12)) {
        dt->isValid = 1;
    }
}

void printData(const struct Data* dt) {
    if (dt->isValid) {
        printf("%02d/%02d/%d\n", dt->dia, dt->mes, dt->ano);
    } else {
        printf ("Data invalida\n");
    }
}

int main()
{

    struct Data dt;
    // initData(&dt);
    // change(&dt, 21, 3, 2001);

    printf("size: %llu\n", sizeof(dt));

    printData(&dt);
}
