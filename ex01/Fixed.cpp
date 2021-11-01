#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int	Fixed::_nFractionalBits = 8;
const int	Fixed::_nFractionalCapacity = 1 << _nFractionalBits;

Fixed::Fixed( void ): _rawBits( 0 )
{	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed& x )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = x;
}
Fixed::Fixed( const int x )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = x << _nFractionalBits;
}
Fixed::	Fixed( const float x )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(x * _nFractionalCapacity);
}
Fixed::~Fixed( void )
{	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{	return _rawBits;
}
void 	Fixed::setRawBits( int x )
{	_rawBits = x;
}
Fixed& 	Fixed::operator=( const Fixed& x )
{
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = x.getRawBits();
	return *this;
}
int 	Fixed::toInt( void ) const
{	return _rawBits >> _nFractionalBits;
}
double 	Fixed::toDouble( void ) const
{	return ( double )_rawBits / _nFractionalCapacity;
}
float 	Fixed::toFloat( void ) const
{	return ( float )_rawBits / _nFractionalCapacity;
}
std::ostream&	operator<<( std::ostream& os, const Fixed& x )
{
	os << x.toDouble();
	return os;
}
