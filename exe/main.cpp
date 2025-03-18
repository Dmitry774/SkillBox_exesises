#include <iostream>
#include <limits>


#ifdef _cplusplus
extern "C"
{
#endif
struct Matrix;

extern Matrix* math_createMatrix(int, int);
extern void math_set(Matrix*, int, int, double);
extern void math_print(const Matrix*);
extern void math_printMatrix(const Matrix*);
extern void math_deleteMatrix(Matrix*);
extern void math_addAssign(Matrix*, const Matrix*);
extern void math_subtractAssign(Matrix*, const Matrix*);
extern void math_multiplyAssignScalar(Matrix*, int);
extern void math_printMatrix(const Matrix*);
extern void math_readMatrix(Matrix*);
extern Matrix * math_add(const Matrix*, const Matrix*);
extern Matrix * math_subtract(const Matrix*, const Matrix*);
extern Matrix * math_dot(const Matrix*, const Matrix*);


#ifdef _cplusplus
}
#endif


int main()

{
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
    return 0;
}