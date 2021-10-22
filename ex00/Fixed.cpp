#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ): _rawBits( 0 )
{}
Fixed::Fixed( const Fixed& x ): _rawBits( x.getRawBits() )
{}
Fixed::~Fixed( void )
{}
int Fixed::getRawBits() const
{
	return _rawBits;
}
void Fixed::setRawBits( int x )
{
	_rawBits = x;
}
