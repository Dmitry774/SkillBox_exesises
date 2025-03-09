//#include <matrix.h>
//#include <c_api.h>





#include <export.h>
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

#ifdef _cplusplus
}
#endif


int main()

{
    Matrix* m = math_createMatrix(3,3);
    math_set(m, 0,0,1.);
    math_set(m, 1,1,1.);
    std::cout<<"Matrix m2 is"<<std::endl;
   math_print(m);

    math_deleteMatrix(m);
    return 0;
}