/*
 se eu nao tiver o ifndef e o define, caso eu inclua 2x o mesmo .h em algum lugar, dara erro de redefinição
    aqui está sendo verificado: se nao foi definido o Date, entao defina, isso evita erros, mesmo que seja feito o include duas vezes

uma outra opção é o pragma once -> basicamente faz a mesma coisa, mas com uma unica instrução
    atencao: pode ser que nao funcione em algum compilador
 */


#ifndef DATE_H
#define DATE_H

class Date {
  public:
    Date() = default;
    Date(short dia, short mes, short ano);

    void change(short dia, short mes, short ano);
    void print() const; //const só é permitido para funcoes que sao membro de algo, seja class ou struct, nao funcoes globais

  private:
    bool _isValid {false};
    short _dia;
    short _mes;
    short _ano;
};


#endif // DATE_H
