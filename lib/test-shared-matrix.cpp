#include <lib/export.h>
#include <iostream>
struct Matrix;

#ifdef _cplusplus
extern "C"
{
#endif

extern Matrix* MATRIXLIB_EXPORT math_createMatrix(int, int);
extern void MATRIXLIB_EXPORT math_set(Matrix*, int, int, double);
extern void MATRIXLIB_EXPORT math_print(const Matrix*);
extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix*);
extern void MATRIXLIB_EXPORT math_addAssign(Matrix*, const Matrix*);
extern void MATRIXLIB_EXPORT math_subtractAssign(Matrix* A, const Matrix* B);
void MATRIXLIB_EXPORT math_multiplyAssignScalar(Matrix* A, int scalar);
void MATRIXLIB_EXPORT math_printMatrix(const Matrix* M);
void MATRIXLIB_EXPORT math_readMatrix(Matrix* M);

#ifdef _cplusplus
}
#endif

int main()

{
 // Проверяем работу экспортируемых в библиотеку функций. Аналогичная проверка библиотечных функций в независимом проекте CMake.

    Matrix* m = math_createMatrix(3,3);
    math_set(m, 0,0,1.);
    math_set(m, 1,1,1.);
    std::cout<<"Matrix m is:"<<std::endl;
    math_print(m);


    Matrix* m1 = math_createMatrix(3,3);
    math_set(m1, 0,0,1.);
    math_set(m1, 1,1,1.);
    std::cout<<"Matrix m1 is"<<std::endl;
    math_print(m1);

    std::cout<<"addAssign m1 and m2 is"<<std::endl;
    math_addAssign(m1,m);
    math_printMatrix(m1);

    std::cout<<"multiplyAssignScalar m1 and int 5 is"<<std::endl;
    math_multiplyAssignScalar(m1, 5);
    math_printMatrix(m1);

    std::cout<<"subtractAssign m1 and m is"<<std::endl;
    math_subtractAssign(m1, m);
    math_printMatrix(m1);

    std::cout<<"Read matrix m1. Enter numbers:"<<std::endl;
    math_readMatrix(m1);
    math_printMatrix(m1);

    math_deleteMatrix(m);
    return 0;
}