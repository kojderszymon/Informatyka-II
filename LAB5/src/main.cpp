#include "matrix.cpp"

int main(int argc, char *argv[]) {

    Matrix matrix_1 = Matrix(4);
    Matrix matrix_2 = Matrix(4);
    matrix_1.set(0, 0, 4);
    matrix_2.set(1, 1, 5);
    try {
        Matrix matrix_3 = matrix_1+matrix_2;
        matrix_3.print();
        std::cout << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "Blad dodawania macierzy: " << e.what() << std::endl;
    }
    try {
        Matrix matrix_4 = matrix_1-matrix_2;
        matrix_4.print();
        std::cout << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "Blad odejmowania macierzy: " << e.what() << std::endl;
    }
    try {
        Matrix matrix_5 = matrix_1*matrix_2;
        matrix_5.print();
        std::cout << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "Blad odejmowania macierzy: " << e.what() << std::endl;
    }
    ++matrix_1;
    matrix_1.print();
    std::cout << std::endl;
    --matrix_2;
    matrix_2.print();
    std::cout << std::endl;
    std::cout << (matrix_1==matrix_2) << std::endl;
	std::cout << (matrix_1!=matrix_2) << std::endl;
    return 0;
}