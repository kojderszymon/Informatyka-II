#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printRecord(int matrix[2][3], int record){
    cout << " | ";
    for(int i = 0; i < 3; i++)
        cout << matrix[record][i] << " ";
    cout << "| ";
}

int main(int argc, char *argv[]) {

    int matrix_1[2][3];
    int matrix_2[2][3];
    int result[2][3];

    srand(time(NULL));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            matrix_1[i][j] = rand() % 40 + 10;
            matrix_2[i][j] = rand() % 40 + 10;
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
    
    printRecord(matrix_1, 0);
    cout << "+";
    printRecord(matrix_2, 0);
    cout << "=";
    printRecord(result, 0);
    cout << endl;
    printRecord(matrix_1, 1);
    cout << " ";
    printRecord(matrix_2, 1);
    cout << " ";
    printRecord(result, 1);
    cout << endl;

    return 0;
}