#include "matrix.h"
#include <cstdlib>
#include <ctime>

Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    data = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n]();
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrix::fillRandom() {
    srand(time(NULL));
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 10;
        }
    }
}

int* Matrix::operator[](unsigned int index) const {
    return data[index];
}

int& Matrix::operator()(unsigned int row, unsigned int col) {
    return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(m, other.n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < other.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] += other.data[i][j];
        }
    }
    return (*this);
}

Matrix& Matrix::operator-=(const Matrix& other) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] -= other.data[i][j];
        }
    }
    return (*this);
}

bool Matrix::operator==(const Matrix& other) const {
    if (m != other.m || n != other.n) {
        return false;
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}
#include <iostream>
#include "matrix.h"

int main() {
    // Создание двух матриц размером 2x2
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    // Заполнение матриц случайными значениями
    mat1.fillRandom();
    mat2.fillRandom();

    // Вывод содержимого матриц
    std::cout << "Matrix 1:\n" << mat1;
    std::cout << "Matrix 2:\n" << mat2;

    // Примеры использования операторов класса Matrix
    Matrix mat3 = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:\n" << mat3;

    mat3 = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:\n" << mat3;

    Matrix mat4 = mat1 * mat2;
    std::cout << "Matrix 1 * Matrix 2:\n" << mat4;

    // Пример использования операторов сравнения
    if (mat1 == mat2) {
        std::cout << "Matrix 1 is equal to Matrix 2\n";
    } else {
        std::cout << "Matrix 1 is not equal to Matrix 2\n";
    }

    return 0;
}
