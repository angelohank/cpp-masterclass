export module date;

import std; //disponivel apenas a partir do c++ 23

export class Date { //se nao for exportado, sera visivel APENAS dentro do modulo, ninguem de fora consegue
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
    Date(short dia, short mes, short ano) {
        change(dia, mes, ano);
    }

    void change(short dia, short mes, short ano) { // :: chama-se "operador de resolucao de escopo"
        _ano = ano;
        _mes = mes;
        _dia = dia;

        validate();

    }

    void print() const {
        if (_isValid) {

            std::cout.fill(0); //preenche 0 à esquerda
            std::cout.width(2); //define o tamanho da proxima impressao
            std::cout << _dia << '/'; // printa o dia e a barra
            std::cout.width(2); //defino que a proxima impressao tera tamanho 2 tambem
            std::cout << _mes << '/' << _ano << std::endl;
        } else {
            std::cout << "Data invalida" << std::endl;
        }
    }

    short lastDayOfMonth() const {
        /*
         * janeiro a julho: meses pares tem 30 dias, impares tem 31
         * fevereiro: 28 ou 29 dias, se for bissexto
         * agosto a dezembro: meses pares tem 31 dias dias, impares tem 30
         */

               //eh possivel otimizar isso, deixando em apenas um if ternario

        /*
         * se for fevereiro, segue a regra de somar com isLeapYear
         * se nao for, segue a seguinte regra:
            XOR só retorna 1 se as entradas forem diferentes, portanto, será retornado sempre 30 + 0 ou 30 + 1

             exemplos:

              mes 1:
              (1 & 1) ^ (1 > 7)
              1       ^    0    (entradas diferentes)

             retorno: 30 + 1

              --------------

             mes 6:
             (6 & 1) ^ (6 > 7)
             0       ^    0    (entradas iguais)

              retorno: 30 + 0
              ----------------

             mes 10:
             (10 & 1) ^ (10 > 7)
             0        ^    1    (entradas diferentes)

              retorno: 30 + 1

         */
        return _mes != FEB ? (30 + (_mes & 1) ^ (_mes > JULY)) :// operador XOR
                   (28 + isLeapYear());


        if(_mes == FEB) {
            //se for falso, sera 28 + 0
            //se for true, sera 28 + 1
            return 28 + isLeapYear();
        }

        return _mes <= JULY ? 30 + (_mes & 1) : 31 - (_mes & 1);
    }

    short dia() const {
        return _dia;
    }

    short mes() const {
        return _mes;
    }
    short ano() const {
        return _ano;
    }

    bool isLeapYear() const {
        /*
         *um ano é bisesexto quando ele é divisivel por 400
         *ou entao quando é divisivel por 4, mas nao por 100
         *exemplos:
         *2000: ano bissexto, pois eh divisivel por 400
         *1996: bissexto, pois, embora nao seja divisivel por 400, divide por 4 mas nao por 100
         *1800: nao-bissexto pois nao eh divisivel por 400 e, embora seja divisivel por 4, tambem eh divisivel por 100
         */


        /*
         * eh possivel fazer resto de divisao com &, mas só funciona com potencia de 2
         * a regra eh n-1
         *          * (4 & 1) -> isso retorna se o resto eh 0 ou 1  (nesse caso, 0)
         * (3 & 1) -> 1
         *          * 1 [0001] & 1 [0001] -> 0001 == 1
         * 2 [0010] & 1 [0001] -> 0000 == 0
         * 3 [0011] & 1 [0001] -> 0001 == 1
         * 4 [0100] & 1 [0001] -> 0000 == 0
         *          * eh basicamente uma comparacao de true e false bit a bit
         */
        const bool dividePor400 = _ano % 400 == 0;
        const bool dividePor4 = _ano % 4 == 0;
        const bool dividePor100 = _ano % 100 == 0;

        return (dividePor4 && !dividePor100) || dividePor400;
    }

    void validate() {
        _isValid = (_dia >= 1 && _dia <= lastDayOfMonth()) && (_mes >= 1 && _mes <= 12) && (_ano >= MIN_YEAR && _ano <= MAX_YEAR);
    }

    auto operator<=>(const Date& otherDate) const {
        //strong_ordering -> precisa do header COMPARE
        if( const auto cmp = _ano <=> otherDate.ano(); cmp != 0 ) { //spaceship comparation, 3-way-comparation
             return cmp;
        }

        if( const auto cmp = _mes <=> otherDate.mes(); cmp != 0 ) {
            return cmp;
        }

        return _dia <=> otherDate.dia();
    }

    bool operator==(const Date& otherDate) const {
        return (*this <=> otherDate ) == 0;
    }

  private:
    bool _isValid {false};
    short _dia;
    short _mes;
    short _ano;
};
