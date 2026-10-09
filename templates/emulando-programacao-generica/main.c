#include <stdio.h>

/*
 * usando essa macro, resolvemos o problema de ter que definir uma funcao para cada tipo
 * visto que o C nao permite sobrecarga de funcoes com outros tipos de parametros
 *
 * mas tem o problema do bug quando usamos um incremento
 */
#define MAXIMUM(a, b) a > b ? a : b

int main() {

    int x = 11, y = 10;
    int r = MAXIMUM(x, y); //dessa forma funciona perfeitamente
    printf("max: %d\n", r);

    //-----------------------------------------------------------

    int x2 = 11, y2 = 10;
    /*
     * o pre compilador transforma a linha em:
     * int r2 = x > ++y ? x : ++y
     *
     * tudo que for y, ele troca por ++y, entao incrementa o 10 uma vez (virando 11), e quando cai do else, incrementa novamente
     */
    int r2 = MAXIMUM(x2, ++y2); //dessa forma retorna 12, sendo que nem tem uma variavel 12
    printf("max: %d\n", r2);


    return 0;
}
