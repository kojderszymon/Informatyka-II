#include <iostream>
using namespace std;

void my_swap(int &number1, int *number2) {
    int temp = number1;
    number1 = *number2;
    *number2 = temp;
}

int main(int argc, char *argv[]) {

    int number1 = 41, number2 = 96;

    cout << "Przed zamiana:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    my_swap(number1, &number2);

    cout << "Po zamianie:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    return 0;
}