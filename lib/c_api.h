#pragma once
#include <lib/export.h>

#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif


typedef double real;

#ifdef _cplusplus
{
extern "C"
#endif

typedef struct Matrix Matrix;
Matrix* MATRIXLIB_EXPORT math_createMatrix (int rows, int cols);
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix* M);
real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col);
void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real value);
Matrix* MATRIXLIB_EXPORT math_add(const Matrix*A, const Matrix* B);
Matrix* MATRIXLIB_EXPORT math_subtract(const Matrix*A, const Matrix* B);
Matrix* MATRIXLIB_EXPORT math_dot(const Matrix*A, const Matrix* B);
void MATRIXLIB_EXPORT math_print(const Matrix* M);
void MATRIXLIB_EXPORT math_addAssign(Matrix* A, const Matrix* B);
void MATRIXLIB_EXPORT math_subtractAssign(Matrix* A, const Matrix* B);
void MATRIXLIB_EXPORT math_multiplyAssignScalar(Matrix* A, int scalar);
void MATRIXLIB_EXPORT math_printMatrix(const Matrix* M);
void MATRIXLIB_EXPORT math_readMatrix(Matrix* M);

#ifdef _cplusplus
}
#endif