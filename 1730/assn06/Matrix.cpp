#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

#include "Matrix.h"

using namespace std;
typedef unsigned int uint;

class Matrix
{
private:
    uint x = 0, y; // x = rows y = cols
    double **o;    //order

public:
    Matrix() : o{new double *[x]}
    {
        x = 0;
        y = 0;
    } // default constructor

    Matrix(uint rows, uint cols)
    {
        x = rows;
        y = cols;
        o = new double *[x];
        for (int i = 0; i < x; i++)
        {
            o[i] = new double[y];
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                o[i][j] = 0;
            }
        }
    } // constructor (all elements initialized to 0)

    Matrix(double **values, int w, int h)
    {
        x = (uint)w;
        y = (uint)h;
        o = new double *[w];
        for (int i = 0; i < w; i++)
        {
            o[i] = new double[h];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                o[i][j] = values[i][j];
            }
        }
    } // constructor (must make a copy of the passed in array)

    Matrix(const Matrix &m)
    {
        double a = m.x;
        double b = m.y;

        o = new double *[x];
        for (int i = 0; i < x; i++)
        {
            o[i] = new double[y];
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                o[i][j] = m.o[i][j];
            }
        }
    } // copy constructor

    ~Matrix()
    {
        for (int i = 0; i < x; i++)
        {
            delete[] o[i];
        }
        delete[] o;
    } //Destructor

    double &at(uint row, uint col)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i == row && j == col)
                {
                    return o[row][col];
                }
            }
        }
        return o[0][0];
    } // get/set element at row,col

    
    const double &at(uint row, uint col) const
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i == row && j == col)
                {
                    return o[row][col];
                }
            }
        }
        return o[row][col];
    } // get element at row,col (when using a const object)

    void printMatrix()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cout << o[i][j] << "  ";
            }
            cout << endl;
        }
    } //printMatrix function

    const uint numRows() const
    {
        return x;
    } // returns the number of rows

    const uint numCols() const
    {
        return y;
    } // returns the number of cols

    Matrix add(double s) const
    {
        Matrix temp = Matrix(o, x, y);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                temp.at(i, j) += s;
            }
        }
        return temp;
    } // add scalar to this matrix

    Matrix add(const Matrix &m) const
    {
        Matrix sum = Matrix(x, y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                sum.o[i][j] = o[i][j] + m.o[i][j];
            }
        }
     return sum;
    } // add this matrix and another matrix

    Matrix subtract(double s) const
    {
        Matrix temp = Matrix(o, x, y);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                temp.at(i, j) -= s;
            }
        }
        return temp;
    } // subtract scalar from this matrix

    Matrix subtract(const Matrix &m) const
    {
     Matrix sum = Matrix(x, y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                sum.o[i][j] = o[i][j] - m.o[i][j];
            }
        }
     return sum;
    } // subtract another matrix from this matrix

    Matrix multiply(double s) const
    {
        Matrix temp = Matrix(o, x, y);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                temp.at(i, j) *= s;
            }
        }
        return temp;
    } // multiply this matrix by a scalar

    Matrix multiply(const Matrix &m) const
    {
        Matrix sum = Matrix(x, y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                sum.o[i][j] = o[i][j] * m.o[i][j];
            }
        }
     return sum;
    } // multiply this matrix by another matrix

    Matrix divide(double s) const
    {
        Matrix temp = Matrix(o, x, y);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                temp.at(i, j) /= s;
            }
        }
        return temp;
    } // divide this matrix by a scalar

    Matrix t() const
    {
        double **transpose = new double *[numRows()];
        for (int i = 0; i < numRows(); i++)
        {
            transpose[i] = new double[numCols()];
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                transpose[j][i] = o[i][j];
            }
        }
        return Matrix(transpose, x, y);
    }
}; //Matrix
#endif