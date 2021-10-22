#pragma once

#include <string>

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& x );
	~Fixed( void );
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	Fixed& 	operator=( const Fixed& x );
private:
	static const int 	_nFractionalBits;
	int 				_rawBits;
};
