#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
	int fix_value;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const Fixed &newobj);
	Fixed & operator= (const Fixed &newobj);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
