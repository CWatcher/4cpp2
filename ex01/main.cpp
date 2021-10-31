#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <climits>

void compareOutput(int n)
{
	static Fixed f;
	f.setRawBits( n );
	std::cout << std::setprecision(20);
	std::cout << (long double)f.getRawBits() /  (1 << 8) << std::endl;
	std::cout << f << std::endl;
	std::cout << std::endl;
}

void test()
{
	for (int i = 0; i < 256; i += 64)
		compareOutput(INT_MAX - i);
}

int main( int, char* argv[] )
{
	if (argv[1]) {
		test();
		return 0;
	}
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
