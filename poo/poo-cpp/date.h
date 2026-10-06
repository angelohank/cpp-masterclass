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
