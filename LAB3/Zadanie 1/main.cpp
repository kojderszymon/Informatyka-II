#include "matrix.cpp"

int main(int argc, char *argv[]) {
    std::cout << "Tworze macierz 4x4 (matrix_1)" << std::endl;
    Matrix matrix_1 = Matrix(4);
    matrix_1.print();
    std::cout << "Tworze macierz 4x5 (matrix_2)" << std::endl;
    Matrix matrix_2 = Matrix(4, 5);
    matrix_2.print();
    matrix_1.set(2, 2, 5);
    std::cout << "Ustawiam wartosc w komorce (2, 2) (matrix_1) na " << matrix_1.get(2, 2) << std::endl;
    matrix_1.print();
    std::cout << "Tworze kolejna macierz 4x4 (matrix_3)" << std::endl;
    Matrix matrix_3 = Matrix(4);
    matrix_3.print();
    std::cout << "Sume macierzy 1 i 3 zapisze do nowej zmiennej (matrix_4) i pliku" << std::endl;
    Matrix matrix_4 = Matrix(4);
    //matrix_4 = matrix_1.add(matrix_3);
    matrix_4.print();
    matrix_4.store("tekst.txt", "./Files/");
    std::cout << "Roznice macierzy 1 i 3 zapisze do zmiennej (matrix_4)" << std::endl;
    matrix_4 = matrix_1.substract(matrix_3);
    matrix_4.print();
    matrix_1.set(1, 1, 3);
    std::cout << "Ustawiam wartosc w komorce 1x1 (matrix_1) na " << matrix_1.get(1, 1) << std::endl;
    matrix_1.print();
    std::cout << "Iloczyn macierzy 1 i 2 zapisze do zmiennej nowej (matrix_5)" << std::endl;
    Matrix matrix_5 = Matrix(4, 5);
    matrix_5 = matrix_1.multiply(matrix_2);
    matrix_5.print();
    std::cout << "Iloczyn ma " << matrix_5.rows() << " wiersz/-e/-y i " << matrix_5.cols() << " kolumn/-e/-y" << std::endl;
    std::cout << "Do nowej zmiennej zapisze macierz zapisana w pliku (matrix_6)" << std::endl;
    Matrix matrix_6 = Matrix("./Files/tekst.txt");
    matrix_6.print();
    return 0;
}