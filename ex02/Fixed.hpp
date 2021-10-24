#pragma once

#include <string>
#include <ostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& x );
	Fixed( const int x );
	Fixed( const float x );
	~Fixed( void );
	int		getRawBits( void ) const;
	Fixed&	setRawBits( int const raw );
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++( int );
	Fixed	operator--( int );
	Fixed&	operator=( const Fixed& x );
	Fixed	operator+( const Fixed& x );
	Fixed	operator-( const Fixed& x );
	Fixed	operator*( const Fixed& x );
	Fixed	operator/( const Fixed& x );
	bool	operator<( const Fixed& x );
	bool	operator>( const Fixed& x );
	bool	operator==( const Fixed& x );
	bool	operator!=( const Fixed& x );
	bool	operator<=( const Fixed& x );
	bool	operator>=( const Fixed& x );
	int		toInt( void ) const;
	float	toFloat( void ) const;
	double	toDouble( void ) const;
	static const	Fixed&	max( const Fixed& x, const Fixed& y );
	static const	Fixed&	min( const Fixed& x, const Fixed& y );
private:
	static const int	_nFractionalBits;
	static const int	_nFractionalCapacity;
	int					_rawBits;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& x );
