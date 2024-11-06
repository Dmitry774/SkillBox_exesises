#include <matrix.h>
#include <iostream>
using namespace math;

real& Matrix::operator () (int row, int col) {
    
    if (row >= this->rows_)
        {
        std::cerr << "Matrix: row number out of bouds" << std::endl;
       // return 0;
        };

    if (col >= this->cols_)
        {
        std::cerr << "Matrix: col number out of bouds" << std::endl;
       // return 0;
        };

    int pos {0};

    pos = cols_*row + col;

    return this->mvec_.at(pos);
}

void Matrix::print()
{
    for (int i = 0 ; i < this->rows_; ++i)
    {
        for (int j = 0 ; j < this->cols_; ++j)
        {
            std::cout << this->mvec_.at(cols_*i + j) << " ";
        }
        std::cout << std::endl;
    }
}