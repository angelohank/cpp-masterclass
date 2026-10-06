#include "date.h"
#include <stdio.h>

Date::Date(short dia, short mes, short ano) {
    change(dia, mes, ano);
}

void Date::change(short dia, short mes, short ano) { // :: chama-se "operador de resolucao de escopo"
    _ano = ano;
    _mes = mes;
    _dia = dia;

    validate();

}

void Date::print() const {
    if (_isValid) {
        printf("%02d/%02d/%d\n", _dia, _mes, _ano);
    } else {
        printf("Data invalida\n");
    }
}

short Date::dia() const {
    return _dia;
}

short Date::mes() const {
    return _mes;
}

short Date::ano() const {
    return _ano;
}

short Date::lastDayOfMonth() const {
    return 31;
}

bool Date::isLeapYear() const {
    /*
     *um ano é bisesexto quando ele é divisivel por 400
     *ou entao quando é divisivel por 4, mas nao por 100
     *exemplos:
     *2000: ano bissexto, pois eh divisivel por 400
     *1996: bissexto, pois, embora nao seja divisivel por 400, divide por 4 mas nao por 100
     *1800: nao-bissexto pois nao eh divisivel por 400 e, embora seja divisivel por 4, tambem eh divisivel por 100
     */

    const bool dividePor400 = _ano % 400 == 0;
    const bool dividePor4 = _ano % 4 == 0;
    const bool dividePor100 = _ano % 100 == 0;

    return (dividePor4 && !dividePor100) || dividePor400;
}

void Date::validate() {
    _isValid = (_dia >= 1 && _dia <= lastDayOfMonth()) && (_mes >= 1 && _mes <= 12) && (_ano >= MIN_YEAR && _ano <= MAX_YEAR);
}
