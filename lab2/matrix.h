#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    unsigned int m;
    unsigned int n;
    int** data;

public:
    Matrix(unsigned int rows, unsigned int cols);
    ~Matrix();

    void fillRandom();

    int* operator[](unsigned int index) const;
    int& operator()(unsigned int row, unsigned int col);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif // MATRIX_H
