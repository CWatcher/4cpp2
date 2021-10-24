#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int	Fixed::_nFractionalBits = 8;
const int	Fixed::_nFractionalCapacity = 1 << _nFractionalBits;

Fixed::Fixed( void ): _rawBits( 0 )
{}
Fixed::Fixed( const Fixed& x )
{
	*this = x;
}
Fixed::Fixed( const int x )
{
	_rawBits = x << _nFractionalBits;
}
Fixed::Fixed( const float x )
{
	_rawBits = roundf(x * _nFractionalCapacity);
}
Fixed::~Fixed( void )
{}

int		Fixed::getRawBits( void ) const
{
	return _rawBits;
}
void 	Fixed::setRawBits( int x )
{
	_rawBits = x;
}
Fixed& 	Fixed::operator=( const Fixed& x )
{
	_rawBits = x.getRawBits();
	return *this;
}
int 	Fixed::toInt( void ) const
{
	return _rawBits >> _nFractionalBits;
}
double 	Fixed::toDouble( void ) const
{
	return ( double )_rawBits / _nFractionalCapacity;
}
float 	Fixed::toFloat( void ) const
{
	return ( float )_rawBits / _nFractionalCapacity;
}
std::ostream&	operator<<( std::ostream& os, const Fixed& x )
{
	os << x.toDouble();
	return os;
}
