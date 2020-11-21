#include "matrix.cpp"

int main(int argc, char *argv[]) {
    Matrix m1(3);
    m1.set(2, 1, 3.1);
    std::cout << m1.get(1, 1) << std::endl;
    m1.store("tekst.txt", "");
    return 0;
}