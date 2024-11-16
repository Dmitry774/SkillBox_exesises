#pragma once
#include <vector>
#include <iostream>
#include <cassert>
namespace math 
{
    typedef double real;
    
    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector <real> mvec_;
    public:
        Matrix() {};

        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows*cols)) {};
    
    real& operator() (int row, int col);

    real operator()(int row, int col) const;

    void print();
    friend Matrix operator+(const Matrix& A, const Matrix& B);
    friend Matrix operator-(const Matrix& A, const Matrix& B);
    friend Matrix operator*(const Matrix& A, const Matrix& B);
    friend Matrix operator+=(Matrix &A, const Matrix &B);
    friend Matrix operator-=(Matrix &A, const Matrix &B);
    friend Matrix operator*=(Matrix &A, const int B);

  
    // геттеры для строк и столбцов
    int rows() const { return rows_; }
    int cols() const { return cols_; }

    friend std::ostream& operator<<(std::ostream &stream, const Matrix &A);
    friend std::istream& operator>>(std::istream &is, Matrix &A);

   // friend Matrix& operator<<(std::ostream &os, const Matrix &A);
    };
}

