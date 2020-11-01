#include <iostream>
using namespace std;

int my_calc(int number1, int number2, int *result) {
    *result = number1 + number2;
    return number1 * number2;
}

int main(int argc, char *argv[]) {

    int number1 = 12, number2 = 5, result;

    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;
    cout << "Iloczyn: " << my_calc(number1, number2, &result) << endl;
    cout << "Suma: " << result << endl;

    return 0;
}