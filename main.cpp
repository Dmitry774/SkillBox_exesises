#include <matrix.h>
#include <iostream>
int main()
{
math::Matrix m (3, 3);
m(0,0) = 1.;
m(1,1) = 1.;
math::Matrix m1(3,3);
m1(0,0) = 5.;
m1(1,1) = 5.;

std::cout << "Matrix m is: " << std::endl;
m.print();
std::cout << std::endl;

std::cout << "Matrix m1 is: " << std::endl;
m1.print();
std::cout << std::endl;

math::Matrix m2 = m1 + m;
std::cout << "Sum of matrices m and m1 is: " << std::endl;
m2.print();
std::cout << std::endl;

math::Matrix m3 = m1 - m;
std::cout << "Substract of matrices m and m1 is: " << std::endl;
m3.print();
std::cout << std::endl;

std::cout<<std::endl<<"Multiplication of m andd m1: " << std::endl;
math::Matrix m4 = m * m1;
m4.print();
std::cout << std::endl;

return 0;
}