#include <iostream>
#include <limits>
#include <array>

using namespace std;

template <typename T>
auto maxElement( const T* array, const size_t size ) {
    if (!array || size == 0) {
        return std::numeric_limits<T>::min();
    }

    auto maiorElemento = array[0];
    for (size_t i = 1; i < size; ++i) {
        if (array[i] > maiorElemento) {
            maiorElemento = array[i];
        }
    }

    return maiorElemento;
}

template <typename T>
auto maxElement( const T& array ) {
    if (array.empty()) {
        throw std::runtime_error("empty array");
    }

    auto maiorElemento = array[0];
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] > maiorElemento) {
            maiorElemento = array[i];
        }
    }

    return maiorElemento;
}

int main() {

    float age[5] {};

    age[0] = 12;
    age[1] = 19;
    age[2] = 95.2;
    age[3] = 52;
    age[4] = 17;

    cout << maxElement( age, 5 ) << endl;

    //---------------------------------------

    std::array<float, 0> age2; //permite que usemos as funcoes empty e size
    // age2[0] = 12;
    // age2[1] = 19;
    // age2[2] = 95.2;
    // age2[3] = 52;
    // age2[4] = 17;

    try {
        cout << maxElement( age2 ) << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "unknown exception" << endl;
    }

    return 0;
}