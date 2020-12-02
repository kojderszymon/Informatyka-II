#ifndef MATRICES_HPP
#define MATRICES_HPP
#include <iostream>
#include <fstream>

class Matrix {
    private:
        int row; //numer wiersza - N (0 - n-1)
        int col; //numer kolumny - M (0 - m-1)
        double **value; //wartosci rzeczywiste
    public:
        bool set(int n, int m, double val);
        double get(int n, int m);
        Matrix add(Matrix matrix_2);
        Matrix substract(Matrix matrix_2);
        Matrix multiply(Matrix matrix_2);
        int cols();
        int rows();
        void print();
        bool store(std::string filename, std::string path);

    Matrix(int x);
    Matrix(int x, int y);
    Matrix(std::string filename);
    ~Matrix();
};
#endif