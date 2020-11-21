#include <iostream>

class Matrix {
    private:
        int row; //numer wiersza - N (0 - n-1)
        int col; //numer kolumny - M (0 - m-1)
        double **value; //wartosci rzeczywiste
    public:
        void set(int n, int m, double val);
        double get(int n, int m);
        Matrix add(Matrix matrix_2);
        Matrix substract(Matrix matrix_2);
        Matrix multiply(Matrix matrix_2);
        int cols();
        int rows();
        void print();
        void store(std::string filename, std::string path);
        int main();

    Matrix(int x);
    Matrix(int x, int y);
    Matrix(std::string filename);
    ~Matrix();
};