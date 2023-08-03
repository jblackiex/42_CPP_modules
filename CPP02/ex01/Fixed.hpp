#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed {
private:
	int fix_value;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const int intval);
	Fixed(const float floatval);
	Fixed(const Fixed &newobj);
	Fixed & operator= (const Fixed &newobj);
	~Fixed();

	int		getRawBits(void) const;
	float 	toFloat(void) const;
	int		toInt(void) const;
	void	setRawBits(int const raw);

friend std::ostream& operator<<(std::ostream& os, Fixed const & fix_num);
};

#endif
