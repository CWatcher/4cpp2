#include "Fixed.hpp"
#include <iostream>

void null_int(int& x)
{
	x = 0;
}
void assignment_test()
{
	int a = 1;
	int b = 10;
	int c = 100;
	std::cout << (a=b=c) << std::endl;
	null_int(a=c);
	std::cout << a << std::endl;
}
int main( void )
{
	assignment_test();
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
