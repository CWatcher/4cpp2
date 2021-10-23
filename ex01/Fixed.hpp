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
	double	toDouble( void ) const;
	float	toFloat( void ) const;
private:
	static const int	_nFractionalBits;
	int					_rawBits;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& x );
