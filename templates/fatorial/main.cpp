#include <cstdint>
#include <iostream>
#include <cstdint>

/*
 * usando constexpr reduz consideravelmente o codigo gerado em assembly
 * essa funcao tem uma complexidade linear -> O(n)
 * usar o constexpr é melhor pois ele é resolvido em tempo de compilaçao, nao em tempo de execuçao
 * dessa forma, quando executar, ele ja tem o resultado correto, sem precisar chamar toda a execuçao da funcao
 *
 * entretando, ele só consegue realizar essa pre compilaçao, caso seja passado um valor literal (como o 5, por exemplo)
 * ou uma constante
 *
 * se for passada uma variavel, ele nao consegue resolver em pre-compilaçao, entao acaba ficando igual
 */
constexpr uint64_t factorial(int num) noexcept {
    uint64_t result = 1;

    for (int i = num; i > 1; i--) {
        result *= i;
    }

    return result;
}

int main() {
    return factorial(5);
}