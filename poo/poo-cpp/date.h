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

    enum {
        MIN_YEAR = 1900,
        MAX_YEAR = 2100,
    };

    enum {
        FEB = 2,
        JULY = 7
    };

    Date() = default;
    Date(short dia, short mes, short ano);

    void change(short dia, short mes, short ano);
    void print() const; //const só é permitido para funcoes que sao membro de algo, seja class ou struct, nao funcoes globais

    //essas funcoes poderiam ser inline, mas prefiro deixar definidas no cpp para nao poluir, visto que temos memoria sobrando, e a otimizacao nao é tao relevante nesse caso
    //alem disso, toda funcao que eh definida dentro do .h, automaticamente eh inline, sem precisar do especificador "inline"
    short dia() const;
    short mes() const;
    short ano() const;

    short lastDayOfMonth() const;

    //tambem poderia ser inline
    bool isLeapYear() const; //verifica se o ano é bisexto

    void validate();

  private:
    bool _isValid {false};
    short _dia;
    short _mes;
    short _ano;
};


#endif // DATE_H
