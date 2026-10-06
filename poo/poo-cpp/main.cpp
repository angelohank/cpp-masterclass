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

/*
 struct X class

struct: tem todos os seus membros publicos por padrao (precisa dos blocos explicitos para ser privado)
class: tem todos os seus membros privados por padrao (precisa dos blocos explicitos para ser publico)
 */

struct Data {
    // o tamanho da struct é a soma das propriedades dela
    // 3 inteiros = 12 bytes
    Data(int dia, int mes, int ano) {
        change(dia, mes, ano);
    }

    //C++ 03 é necessário usar o contrutor declarado sem parametros
    Data() = default; //versao mais performatica que criar o construtor sem parametros, a partir do C++ 11
    /*
        se nao for ter nada no construtor, basta usar o default, é bem mais performatico (usado godbolt para comparar)
     */

    void change(int dia, int mes, int ano) {
        _ano = ano;
        _mes = mes;
        _dia = dia;

        _isValid = false;
        if ((_dia >= 1 && _dia <= 31) && (_mes >= 1 && _mes <= 12)) {
            _isValid = true;
        }
    }

    void print() const {
        if (_isValid) {
            printf("%02d/%02d/%d\n", _dia, _mes, _ano);
        } else {
            printf("Data invalida\n");
        }
    }

  private:
    bool _isValid;
    short _dia;
    short _mes;
    short _ano;
};

int main() {

    struct Data dt;
    dt.change(21, 3, 2026);

    Data dt2;

    printf("size: %llu\n", sizeof(dt));
    dt.print();
}
