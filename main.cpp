#include <matrix.h>
#include <iostream>
int main()
{
math::Matrix m (3, 3);
m.print();

std::cout << "Element at pos (1,1) = "<< m(1, 1) << std::endl;
m(1,1) = 12.0;

std::cout << std::endl;
m.print();

return 0;
}