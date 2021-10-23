#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_nFractionalBits = 8;

Fixed::Fixed( void ): _rawBits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed& x )
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = x.getRawBits();
}
Fixed::Fixed( const int x )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = x << _nFractionalBits;
}
Fixed::	Fixed( const float x )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = ( int )x << _nFractionalBits;
	float fraction = x - ( int )x;
	_rawBits += fraction * (1 << _nFractionalBits);
}
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

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
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = x.getRawBits();
	return *this;
}
int 	Fixed::toInt( void ) const
{
	return _rawBits >> _nFractionalBits;
}
double 	Fixed::toDouble( void ) const
{
	unsigned fractionalAntiMask = ~( unsigned )0 << 8;
	unsigned fractionalMask = ~fractionalAntiMask;
	unsigned fractionalBits = _rawBits & fractionalMask;
	unsigned fractionSize = 1 << _nFractionalBits;
	double fractional = ( double )fractionalBits / fractionSize;
	return toInt() + fractional;
}
float 	Fixed::toFloat( void ) const
{
	unsigned fractionalAntiMask = ~( unsigned )0 << 8;
	unsigned fractionalMask = ~fractionalAntiMask;
	unsigned fractionalBits = _rawBits & fractionalMask;
	unsigned fractionSize = 1 << _nFractionalBits;
	float fractional = ( float )fractionalBits / fractionSize;
	return toInt() + fractional;
}
std::ostream&	operator<<( std::ostream& os, const Fixed& x )
{
	os << x.toDouble();
	return os;
}
