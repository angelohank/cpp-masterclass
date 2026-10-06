#include <stdio.h>
#include <iostream>
#include "date.h"
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

/*
 struct X class

struct: tem todos os seus membros publicos por padrao (precisa dos blocos explicitos para ser privado)
class: tem todos os seus membros privados por padrao (precisa dos blocos explicitos para ser publico)
 */
using namespace std;
int main() {

    Date dt1(31, 01, 2001); //valido
    dt1.print();

    dt1.change(29, 02, 2001); //invalido | nao eh bissexto
    dt1.print();

    dt1.change(29, 02, 1997); //invalido | nao eh bissexto
    dt1.print();

    dt1.change(29, 02, 1996); //valido
    dt1.print();

    dt1.change(29, 02, 2000); //valido
    dt1.print();

    dt1.change(31, 06, 2001); //invalido | mes tem 30 dias
    dt1.print();

    dt1.change(31, 07, 2001); //valido
    dt1.print();

    dt1.change(31, 8, 2001); //valido
    dt1.print();

    dt1.change(31, 9, 2001); //invalido | mes tem 30 dias
    dt1.print();

    dt1.change(31, 12, 2001); //valido
    dt1.print();
}

