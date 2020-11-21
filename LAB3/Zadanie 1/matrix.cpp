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

//Matrix::Matrix(std::string filename) {

//}

Matrix::~Matrix() {
    for(int i = 0; i < row; i++)
        delete [] value[i];
    delete [] value;
}

void Matrix::set(int n, int m, double val) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(1);
    }
    value[n][m] = val;
}

double Matrix::get(int n, int m) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(2);
    }
    return value[n][m];   
}

Matrix Matrix::add(Matrix matrix_2) {
    if((row != matrix_2.row) || (col != matrix_2.col)) {
        std::cout << "Niepoprawne dane" << std::endl;
        exit(3);
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
        exit(3);
    }
    Matrix result(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result.value[i][j] = value[i][j] - matrix_2.value[i][j];
    return result;
}

Matrix Matrix::multiply(Matrix matrix_2) {
    row =row;
    return matrix_2;
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
    std::fstream file;
    file.open(filename, std::ios::out);
    if(file.good() == true ) {
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++)
                file << value[i][j] << " ";
            file << std::endl;
        }
        file.close();
    }
}

int Matrix::main() {
    return row;
}