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

std::cout<<std::endl<<"Multiplication of m and m1: " << std::endl;
math::Matrix m4 = m * m1;
m4.print();
std::cout << std::endl;

std::cout<<std::endl<<"+= of m4 and m1: " << std::endl;
m4 += m;
m4.print();
std::cout << std::endl;

std::cout<<std::endl<<"-= of m4 and m1: " << std::endl;
m4 -= m;
m4.print();
std::cout << std::endl;

std::cout<<std::endl<<"*= of m4 and const int: " << std::endl;
int A = 3;
m4 *= A;
m4.print();
std::cout << std::endl;

std::cout<<std::endl<<"<< for m4" << std::endl;
std::cout << m4; // Используем перегруженный оператор << для вывода

std::cout<<std::endl<<"<< for m4" << std::endl;
std::cin >> m4; // Используем перегруженный оператор >> для ввода
std::cout<<std::endl<<"<<New m4" << std::endl;
std::cout << m4; // Используем перегруженный оператор << для вывода

return 0;
}