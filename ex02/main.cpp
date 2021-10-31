#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

void	compareDivision(Fixed x, Fixed y)
{
	std::cout << std::setprecision(20);
	std::cout << "Fixed:     " << std::setw(12)
	          << x << " / " << y << " = " << x / y << std::endl;
	std::cout << "toFloat(): " << std::setw(12)
	          << x.toFloat() << " / " << y.toFloat()
	          << " = " << x.toFloat() / y.toFloat() << std::endl;
	std::cout << std::endl;
}
void	test()
{
	Fixed	x(1), y(128);
	compareDivision(x, y);
	x.setRawBits(1);
	y.setRawBits(128);
	compareDivision(x, y);
	compareDivision(x, y);
	x.setRawBits(127);
	y.setRawBits(128);
	compareDivision(127, 128);
	compareDivision(999999, 1000000);
}
int 	main( int argc, char** )
{
	if (argc > 1) {
		test();
		return 0;
	}
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
