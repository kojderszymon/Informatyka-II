#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    float height, weight; // masa_ciala [kg], wzrost [m]
    float bmi;

    cout << "Podaj wage [kg]: ";
    cin >> height;

    cout << "Podaj wzrost [m]: ";
    cin >> weight;

    bmi = (height) / (weight * weight);

    if(bmi < 16)
        cout << "Wyglodzenie - BMI = " << bmi << endl;
    else if(bmi >= 16 && bmi < 17)
        cout << "Wychudzenie - BMI = " << bmi << endl;
    else if(bmi >= 17 && bmi < 18.5)
        cout << "Niedowaga - BMI = " << bmi << endl;
    else if(bmi >= 18.5 && bmi < 25)
        cout << "Wartosc prawidlowa - BMI = " << bmi << endl;
    else if(bmi >= 25 && bmi < 30)
        cout << "Nadwaga - BMI = " << bmi << endl;
    else if(bmi >= 30 && bmi < 35)
        cout << "I stopien otylosci - BMI = " << bmi << endl;
    else if(bmi >= 35 && bmi < 40)
        cout << "II stopien otylosci - BMI = " << bmi << endl;
    else if(bmi >= 40)
        cout << "Skrajna otylosc - BMI = " << bmi << endl;
    
    return 0;
}