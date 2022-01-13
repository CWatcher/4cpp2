#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

void	compareDivision(Fixed x, Fixed y)
{
	std::cout << "Fixed:     " << std::setw(12)
	          << x << " / " << y << " = " << x / y << std::endl;
	std::cout << "toFloat(): " << std::setw(12)
	          << x.toFloat() << " / " << y.toFloat()
	          << " = " << x.toFloat() / y.toFloat() << std::endl;
	std::cout << std::endl;
}
void	compareMultiplication(Fixed fx, Fixed fy)
{
	std::cout << "Fixed:      " << std::setw(12)
	          << fx << " * " << fy << " = " << fx * fy << std::endl;
	std::cout << "toDouble(): " << std::setw(12)
	          << fx.toDouble() << " * " << fy.toDouble()
	          << " = " << fx.toDouble() * fy.toDouble() << std::endl;
	std::cout << std::endl;
}
void	test()
{
	std::streamsize prec = std::cout.precision();
	std::cout << std::setprecision(30);
	Fixed	x(1), y(128);
	compareDivision(x, y);
	x.setRawBits(1);
	y.setRawBits(128);
	compareDivision(x, y);
	compareDivision(x, y);
	compareDivision(127, 128);
	compareDivision(999999, 1000000);
	compareDivision(7777777, 8000000);
	compareDivision(1, 1);
	compareDivision(3, 2);
	compareDivision(6, 2);

	compareMultiplication(7777777, 0.5);
	compareMultiplication(7777777, 0.3);
	std::cout.precision( prec );
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
