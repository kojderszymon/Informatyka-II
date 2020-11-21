#include "matrix.hpp"

Matrix::Matrix(int n) {
    row = n;
    col = n;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [n];
        for(int j = 0; j < n; j++)
            value[i][j] = 0,0;
    }
}

Matrix::Matrix(int n, int m) {
    row = n;
    col = m;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [m];
        for(int j = 0; j < m; j++)
            value[i][j] = 0,0;
    }
}

Matrix::Matrix(std::string filename) {

}

Matrix::~Matrix() {
    for(int i = 0; i < row; i++)
        delete [] value[i];
    delete [] value;
}

void Matrix::set(int n, int m, double val) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col))
        std::cout << "Niepoprawne dane" << std::endl;
    else
        value[n][m] = val;
}

double Matrix::get(int n, int m) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col))
        std::cout << "Niepoprawne dane" << std::endl;
    else
        return value[n][m];
}

Matrix Matrix::add(Matrix matrix_2) {

}

Matrix Matrix::substract(Matrix matrix_2) {

}

Matrix Matrix::multiply(Matrix matrix_2) {

}

int Matrix::cols() {

}

int Matrix::rows() {

}

void Matrix::print() {

}

void Matrix::store(std::string filename, std::string path) {

}

int Matrix::main() {

}