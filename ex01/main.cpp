#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

void compareOutput(int n)
{
	static Fixed f;
	f.setRawBits( n );
	std::streamsize prec = std::cout.precision();
	std::cout.precision(16);
	std::cout << "Number stored " << ( double )f.getRawBits() / (1 << 8)
	          << std::endl;
	std::cout << "Number output " << f << std::endl;
	std::cout << std::endl;
	std::cout.precision( prec );
}
void	compareToInt( double x )
{
	static Fixed f;
	f.setRawBits( x * 256 );
	std::cout << "Fixed:            " << f << ".toInt()  " << " = " <<        f.toInt()   << std::endl;
	std::cout << "toFloat(): ( int )" << f << ".toFloat()" << " = " << ( int )f.toFloat() << std::endl;
	std::cout << std::endl;
}

void test()
{
	compareOutput( std::numeric_limits< int >::max() );
	compareOutput( std::numeric_limits< int >::min() + 21 );

	compareToInt(.75);
	compareToInt(-1);
	compareToInt(-.75);
	compareToInt(-1.25);
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
