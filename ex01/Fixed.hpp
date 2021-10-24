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
	void	setRawBits( int const raw );
	Fixed&	operator=( const Fixed& x );
	int		toInt( void ) const;
	float	toFloat( void ) const;
	double	toDouble( void ) const;
private:
	static const int	_nFractionalBits;
	static const int	_nFractionalCapacity;
	int					_rawBits;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& x );
