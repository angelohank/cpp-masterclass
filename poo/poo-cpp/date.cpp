#include "date.h"
#include <stdio.h>

Date::Date(short dia, short mes, short ano) {
    change(dia, mes, ano);
}

void Date::change(short dia, short mes, short ano) { // :: chama-se "operador de resolucao de escopo"
    _ano = ano;
    _mes = mes;
    _dia = dia;

    _isValid = false;
    if ((_dia >= 1 && _dia <= 31) && (_mes >= 1 && _mes <= 12)) {
        _isValid = true;
    }
}

void Date::print() const {
    if (_isValid) {
        printf("%02d/%02d/%d\n", _dia, _mes, _ano);
    } else {
        printf("Data invalida\n");
    }
}
