#include <fstream>
#include "matrix.hpp"

Matrix::Matrix(int n) {
    row = n;
    col = n;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [n];
        for(int j = 0; j < n; j++)
            value[i][j] = 0.0;
    }
}

Matrix::Matrix(int n, int m) {
    row = n;
    col = m;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [m];
        for(int j = 0; j < m; j++)
            value[i][j] = 0.0;
    }
}

Matrix::Matrix(std::string filename) {
    std::fstream file;
    file.open(filename, std::ios::in);
    if(file.good()) {
        file >> row;
        file >> col;
        value = new double * [row];
            for(int i = 0; i < row; i++) {
                value[i] = new double [col];
                for(int j = 0; j < col; j++)
                    file >> value[i][j];
            }
        file.close();
    }
    else {
        std::cout << "Tworzenie zmiennej nie powiodlo sie" << std::endl;
        exit(1);
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < row; i++)
        delete [] value[i];
    delete [] value;
}

void Matrix::set(int n, int m, double val) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(2);
    }
    value[n][m] = val;
}

double Matrix::get(int n, int m) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(3);
    }
    return value[n][m];   
}

Matrix Matrix::add(Matrix matrix_2) {
    if((row != matrix_2.row) || (col != matrix_2.col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(4);
    }
    Matrix result(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result.value[i][j] = value[i][j] + matrix_2.value[i][j];
    return result;
}

Matrix Matrix::substract(Matrix matrix_2) {
    if((row != matrix_2.row) || (col != matrix_2.col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(5);
    }
    Matrix result(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result.value[i][j] = value[i][j] - matrix_2.value[i][j];
    return result;
}

Matrix Matrix::multiply(Matrix matrix_2) {
    if(col != matrix_2.row) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(6);
    }
    Matrix result(row, matrix_2.col);
    double sum;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < matrix_2.col; j++) {
            sum = 0;
            for(int k = 0; k < col; k++) {
                sum += value[i][k] * matrix_2.value[k][j];
                result.value[i][j] = sum;
            }
        }
    return result;
}

int Matrix::cols() {
    return col;
}

int Matrix::rows() {
    return row;
}

void Matrix::print() {
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++)
            std::cout << value[i][j] << " ";
    std::cout << std::endl;
    }
}

void Matrix::store(std::string filename, std::string path) {
    char *fullpath;
    sprintf(fullpath, "%s%s", path, filename);
    std::fstream file;
    file.open(fullpath, std::ios::out);
    if(file.good()) {
        file << row << " " << col << std::endl;
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++)
                file << value[i][j] << " ";
            file << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Zapis do pliku nie powiodl sie" << std::endl;
        exit(7);
    }
}

int Matrix::main() {
    std::cout << "Tworze macierz 3x3" << std::endl;
    Matrix matrix_1(3);
    matrix_1.print();
    std::cout << "Tworze macierz 4x3" << std::endl;
    Matrix matrix_2(4, 3);
    matrix_2.print();
    matrix_1.set(2, 2, 5);
    std::cout << "Ustawiam wartosc w komorce 2x2 na " << matrix_1.get(2, 2) << std::endl;
    matrix_1.print();
    std::cout << "Tworze kolejna macierz 3x3" << std::endl;
    Matrix matrix_3(3);
    matrix_3.print();
    std::cout << "Sume macierzy 1 i 3 zapisze do nowej zmiennej i pliku" << std::endl;
    Matrix matrix_4(3);
    matrix_4 = matrix_1.add(matrix_3);
    matrix_4.print();
    matrix_4.store("tekst.txt", "");
    std::cout << "Roznice macierzy 1 i 3 zapisze do 4 zmiennej" << std::endl;
    matrix_4 = matrix_1.substract(matrix_3);
    matrix_4.print();
    matrix_1.set(1, 1, 3);
    std::cout << "Ustawiam wartosc w komorce 1x1 na " << matrix_1.get(1, 1) << std::endl;
    matrix_1.print();
    std::cout << "Iloczyn macierzy 1 i 2 zapisze do 4 zmiennej" << std::endl;
    matrix_4 = matrix_1.multiply(matrix_2);
    matrix_4.print();
    std::cout << "Iloczyn ma " << matrix_4.rows() << " wierszy i " << matrix_4.cols() << " kolumn" << std::endl;
    std::cout << "Do nowej zmiennej zapisze macierz zapisana w pliku" << std::endl;
    Matrix matrix_5("tekst.txt");
    return 0;
}