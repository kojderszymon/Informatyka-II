#include <iostream>
using namespace std;

void my_swap(int *number1, int *number2) {
    if(*number1 > *number2) {
        int temp = *number1;
        *number1 = *number2;
        *number2 = temp;
    }
}

int main(int argc, char *argv[]) {

    int number1 = 13, number2 = 54;

    cout << "Przed zamiana:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    my_swap(&number1, &number2);

    cout << "Po zamianie:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    number1 = 63, number2 = 38;

    cout << endl << "Przed zamiana:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    my_swap(&number1, &number2);

    cout << "Po zamianie:" << endl;
    cout << "Liczba 1: " << number1 << endl;
    cout << "Liczba 2: " << number2 << endl;

    return 0;
}