#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class Matrix
{
  public:
    Matrix(unsigned int m, unsigned int n) : m(m), n(n)
    {
        data = new int* [m];
        for (unsigned int i = 0; i < m; i++)
        {
            data[i] = new int[n];
        }
    }

    ~Matrix()
    {
        for (unsigned int i = 0; i < m; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    int* operator[](unsigned int index)
    {
        return data[index];
    }

    void fillRandom()
    {
        srand(time(NULL));
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                data[i][j] = rand() % 10;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (unsigned int i = 0; i < matrix.m; i++)
        {
            for (unsigned int j = 0; j < matrix.n; j++)
            {
                os << std::setw(2) << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix& operator+=(const Matrix& rhs)
    {
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                data[i][j] += rhs.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& rhs) const
    {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& rhs)
    {
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                data[i][j] -= rhs.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& rhs) const
    {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                result.data[i][j] = data[i][j] - rhs.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& rhs) const
    {
        if (n != rhs.m)
        {
            throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
        }

        Matrix result(m, rhs.n);
        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < rhs.n; j++)
            {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; k++)
                {
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix& rhs) const
    {
        if (m != rhs.m || n != rhs.n)
        {
            return false;
        }

        for (unsigned int i = 0; i < m; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                if (data[i][j] != rhs.data[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool operator!=(const Matrix& rhs) const
    {
        return !(*this == rhs);
    }

  private:
    int** data;
    unsigned int m;
    unsigned int n;
};

void main() {

}