#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ): _rawBits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed& x )
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = x.getRawBits();
}
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}
void Fixed::setRawBits( int x )
{
	_rawBits = x;
}
