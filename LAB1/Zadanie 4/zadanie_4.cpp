#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    int number_1 = atoi(argv[1]);
    int number_2 = atoi(argv[2]);

    if(number_1 > 1 && number_2 > 1) {
        int sum_1 = 0, sum_2 = 0;

        for(int i = 1; i * i <= number_1; i++)
            if (number_1 % i == 0)
                sum_1 += i + (number_1 / i);

        for(int i = 1; i * i <= number_2; i++)
            if (number_2 % i == 0)
                sum_2 += i + (number_2 / i);

        if(sum_1 ==  sum_2)
            cout << "Podane liczby: " << number_1 << ", " << number_2 << " sa liczbami skojarzonymi" << endl;
        else
            cout << "Podane liczby: " << number_1 << ", " << number_2 << " nie sa liczbami skojarzonymi" << endl;
    }
    else   
        cout << "Podane liczby nie sa poprawne" << endl;
    
    return 0;
}