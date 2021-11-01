#include "Fixed.hpp"
#include <iostream>
#include <climits>

void	showSetGet(int i)
{
	static Fixed f;

	f.setRawBits( i );
	std::cout << "setRawBits(     " << i << " )" << std::endl;
	i = f.getRawBits();
	std::cout << "getRawBits() == " << i << std::endl;
	std::cout << std::endl;
}
void	test()
{
	showSetGet( -1234567890 );
	showSetGet( INT_MAX );
	showSetGet( INT_MIN );
} 
int 	main( int argc, char** )
{
	if ( argc > 1 )
	{	test();
		return 0;
	}
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
