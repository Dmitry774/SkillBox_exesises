#pragma once
#include <vector>
#include <iostream>
#include <cassert>

// Определяем макрос для экспорта/импорта
#ifdef _WIN32
    #ifdef MATRIXLIB_EXPORTS
        #define MATRIXLIB_API __declspec(dllexport)  // Экспорт при сборке библиотеки
    #else
        #define MATRIXLIB_API __declspec(dllimport)  // Импорт при использовании библиотеки
    #endif
#else
    #define MATRIXLIB_API  // На Linux/macOS макрос пустой
#endif

namespace math {
    typedef double real;

    class MATRIXLIB_API Matrix {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;
    public:
        Matrix() {};
        Matrix(int rows, int cols);

        real& operator()(int row, int col);
        real operator()(int row, int col) const;

        void print() const;

        // Экспортируемые friend функции
        friend MATRIXLIB_API Matrix operator+(const Matrix& A, const Matrix& B);
        friend MATRIXLIB_API Matrix operator-(const Matrix& A, const Matrix& B);
        friend MATRIXLIB_API Matrix operator*(const Matrix& A, const Matrix& B);
        friend MATRIXLIB_API Matrix operator+=(Matrix& A, const Matrix& B);
        friend MATRIXLIB_API Matrix operator-=(Matrix& A, const Matrix& B);
        friend MATRIXLIB_API Matrix operator*=(Matrix& A, const int B);
        friend MATRIXLIB_API std::ostream& operator<<(std::ostream& stream, const Matrix& A);
        friend MATRIXLIB_API std::istream& operator>>(std::istream& is, Matrix& A);
    };
}