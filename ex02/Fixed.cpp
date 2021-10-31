#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int	Fixed::_nFractionalBits = 8;
const int	Fixed::_nFractionalCapacity = 1 << _nFractionalBits;

Fixed::Fixed( void ): _rawBits( 0 )
{}
Fixed::Fixed( const Fixed& x ) {
	*this = x;
}
Fixed::Fixed( const int x ) {
	_rawBits = x << _nFractionalBits;
}
Fixed::Fixed( const float x ) {
	_rawBits = roundf(x * _nFractionalCapacity);
}
Fixed::~Fixed( void )
{}

int		Fixed::getRawBits( void ) const {
	return _rawBits;
}
Fixed& 	Fixed::setRawBits( int x )
{
	_rawBits = x;
	return *this;
}
Fixed&	Fixed::operator++()
{
	++_rawBits;
	return *this;
}
Fixed&	Fixed::operator--()
{
	--_rawBits;
	return *this;
}
Fixed 	Fixed::operator++( int )
{
	Fixed	r( *this );
	_rawBits++;
	return r;
}
Fixed 	Fixed::operator--( int )
{
	Fixed	r( *this );
	_rawBits--;
	return r;
}
Fixed& 	Fixed::operator=( const Fixed& x )
{
	_rawBits = x.getRawBits();
	return *this;
}
Fixed 	Fixed::operator+( const Fixed& x ) const
{
	Fixed	r( *this );
	return r._rawBits += x._rawBits;
}
Fixed 	Fixed::operator-( const Fixed& x ) const
{
	Fixed	r( *this );
	return r._rawBits -= x._rawBits;
}
Fixed 	Fixed::operator*( const Fixed& x ) const
{
	Fixed	r( *this );
	r._rawBits *= x._rawBits;
	r._rawBits >>= _nFractionalBits;
	return r;
}
Fixed 	Fixed::operator/( const Fixed& x ) const
{
	long d = _rawBits;
	d <<= sizeof( int ) * 8;
	d /= x._rawBits;
	d >>= sizeof( int ) * 8 - _nFractionalBits;
	Fixed r;
	return r.setRawBits( d );
}
bool 	Fixed::operator<( const Fixed& x ) const {
	return _rawBits < x._rawBits;
}
bool 	Fixed::operator>( const Fixed& x ) const {
	return _rawBits > x._rawBits;
}
bool 	Fixed::operator==( const Fixed& x ) const {
	return _rawBits == x._rawBits;
}
bool 	Fixed::operator!=( const Fixed& x ) const {
	return _rawBits != x._rawBits;
}
bool 	Fixed::operator<=( const Fixed& x ) const {
	return _rawBits <= x._rawBits;
}
bool 	Fixed::operator>=( const Fixed& x ) const {
	return _rawBits >= x._rawBits;
}
int 	Fixed::toInt( void ) const {
	return _rawBits >> _nFractionalBits;
}
double 	Fixed::toDouble( void ) const {
	return ( double )_rawBits / _nFractionalCapacity;
}
float 	Fixed::toFloat( void ) const {
	return ( float )_rawBits / _nFractionalCapacity;
}

const Fixed&	Fixed::max( const Fixed& x, const Fixed& y ) {
	return x.getRawBits() > y.getRawBits() ? x : y;
}
const Fixed&	Fixed::min( const Fixed& x, const Fixed& y ) {
	return x.getRawBits() < y.getRawBits() ? x : y;
}

std::ostream&	operator<<( std::ostream& os, const Fixed& x ) {
	return os << x.toDouble();
}
