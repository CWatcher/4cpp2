#pragma once

#include <string>

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& x );
	Fixed( const int x );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	Fixed&	operator=( const Fixed& x );
	int		toInt( void ) const;
private:
	static const int	_nFractionalBits;
	int					_rawBits;
};
