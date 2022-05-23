#include <iostream>

#include "Matrix.cpp"

Matrix t1();

int main()
{
    Matrix t1(2, 2);
    Matrix t2(2, 2);
    Matrix t4();
    //t1.add(3).subtract(2).multiply(6).divide(2).printMatrix();
    t1.at(0, 0) = 1;
    t1.at(0, 1) = 2;
    t1.at(1, 0) = 3;
    t1.at(1, 1) = 4;
    t1.printMatrix();

    t2.at(0, 0) = 5;
    t2.at(0, 1) = 6;
    t2.at(1, 0) = 7;
    t2.at(1, 1) = 8;
    t2.printMatrix();

   Matrix t3 = t1.add(t2);
   t2.divide(2).printMatrix();
    // t1.printMatrix();
    //  t2.printMatrix();
    // t3.at(0, 0);
    // t3.at(0, 1);
    // t3.at(1, 1);
    // t3.at(1, 0);
    t3.printMatrix();
    return 0;
}