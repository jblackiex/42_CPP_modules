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
	bool	operator>(const Fixed &fix_num) const ;
	bool	operator<(const Fixed &fix_num) const ;
	bool	operator>=(const Fixed &fix_num) const ;
	bool	operator<=(const Fixed &fix_num) const ;
	bool	operator==(const Fixed &fix_num) const ;
	bool	operator!=(const Fixed &fix_num) const ;
	Fixed	operator+(const Fixed &fix_num) const ;
	Fixed	operator-(const Fixed &fix_num) const ;
	Fixed	operator*(const Fixed &fix_num) const ;
	Fixed	operator/(const Fixed &fix_num) const ;
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
	static Fixed	&min(Fixed & fix_1, Fixed &second);
	static const Fixed	&min(const Fixed & fix_1, const Fixed & second);
	static Fixed	&max(Fixed & fix_1, Fixed &second);
	static const Fixed	&max(const Fixed & fix_1, const Fixed & second);

};

std::ostream& operator<<(std::ostream& os, Fixed const & fix_num);

#endif
