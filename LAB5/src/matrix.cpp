#include "..\include\LAB4\matrix.hpp"

Matrix::Matrix(int n) {
    row = n;
    col = n;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [n];
        for(int j = 0; j < n; j++)
            value[i][j] = 0;
    }
}

Matrix::Matrix(int n, int m) {
    row = n;
    col = m;
    value = new double * [n];
    for(int i = 0; i < n; i++) {
        value[i] = new double [m];
        for(int j = 0; j < m; j++)
            value[i][j] = 0;
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
    else
        throw std::runtime_error("Matrix: Blad pliku");
}

Matrix::~Matrix() {
    for(int i = 0; i < row; i++)
        delete [] value[i];
    delete [] value;
}

bool Matrix::set(int n, int m, double val) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col))
        return false;
    value[n][m] = val;
    return true;
}

double Matrix::get(int n, int m) {
    if((n < 0) || (n >= row) || (m < 0) || (m >= col)) {
        throw std::runtime_error("get: Niepoprawne argumenty");
    }
    return value[n][m];   
}

Matrix Matrix::operator+(Matrix &matrix_2) {
    if((row != matrix_2.rows()) || (col != matrix_2.cols())) {
        throw std::runtime_error("operator + : niepoprawne dane");
    }
    Matrix result = Matrix(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            (result.value)[i][j] = value[i][j] + (matrix_2.value)[i][j];
    return result;
}

Matrix Matrix::operator-(Matrix &matrix_2) {
    if((row != matrix_2.row) || (col != matrix_2.col)) {
        throw std::runtime_error("operator - : niepoprawne dane");
    }
    Matrix result = Matrix(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            (result.value)[i][j] = value[i][j] - (matrix_2.value)[i][j];
    return result;
}

Matrix Matrix::operator*(Matrix &matrix_2) {
    if(col != matrix_2.rows()) {
        throw std::runtime_error("operator * : niepoprawne dane");
    }
    Matrix result = Matrix(row, matrix_2.col);
    double sum;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < matrix_2.col; j++) {
            sum = 0;
            for(int k = 0; k < col; k++)
                sum += value[i][k] * (matrix_2.value)[k][j];
            (result.value)[i][j] = sum;
        }
    return result;
}

void Matrix::operator++() {
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            set(i, j, (get(i, j) + 1));
}

void Matrix::operator--() {
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            set(i, j, (get(i, j) - 1));
}

bool Matrix::operator==(Matrix &matrix_2) {
    if(row == matrix_2.rows() && col == matrix_2.cols()) {
        for (int i = 0; i < col; i++)
            for (int j = 0; j < row; j++)
                if(value[i][j] != matrix_2.get(i, j))
                    return false;
    }
    else 
        return false;
    return true;
}

bool Matrix::operator!=(Matrix &matrix_2) {
    if(row == matrix_2.rows() && col == matrix_2.cols()) {
        for (int i = 0; i < col; i++)
            for (int j = 0; j < row; j++)
                if(value[i][j] != matrix_2.get(i, j))
                    return true;
    }
    else 
        return true;
    return false;
}

int Matrix::cols() {
    return col;
}

int Matrix::rows() {
    return row;
}

void Matrix::print() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            std::cout << value[i][j] << " ";
    std::cout << std::endl;
    }
}

bool Matrix::store(std::string filename, std::string path) {
    std::fstream file;
    file.open((path + filename).c_str(), std::ios::out);
    if(file.good()) {
        file << row << " " << col << std::endl;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++)
                file << value[i][j] << " ";
            file << std::endl;
        }
        file.close();
        return true;
    }
    else
        return false;
}