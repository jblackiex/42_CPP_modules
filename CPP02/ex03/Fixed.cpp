#include "Fixed.hpp"

Fixed::Fixed() {
	//std::cout << "Default Constructor called" << std::endl;
	this->fix_value = 0;
}

Fixed::Fixed(const int intval) {
	//std::cout << "Int Constructor called" << std::endl;
	this->fix_value = intval << this->bits;
}

Fixed::Fixed(const float floatval) {
	//std::cout << "Float Constructor called" << std::endl;
	this->fix_value = (int)roundf(floatval * (1 << this->bits));
}

Fixed::Fixed(const Fixed &newobj) {
	//std::cout << "Copy Constructor called" << std::endl;
	*this = newobj;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator= (const Fixed &newobj)
{
	//std::cout << "Assignment operator called" << std::endl;
	if (this != &newobj)
		this->fix_value = newobj.fix_value;
	
	return(*this);
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits called" << std::endl;
	return(this->fix_value);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits called" << std::endl;
	this->fix_value = raw;
}

int		Fixed::toInt(void) const{
	return this->fix_value >> this->bits;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>( this->fix_value) / ( 1 << this->bits );
}

std::ostream& operator<< (std::ostream& os, Fixed const & fix_num) {
	os << fix_num.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &fix_num) const {
	return (this->getRawBits() > fix_num.getRawBits());
}

bool	Fixed::operator<(const Fixed &fix_num) const {
	return (this->getRawBits() < fix_num.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fix_num) const {
	return (this->getRawBits() >= fix_num.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fix_num) const {
	return (this->getRawBits() <= fix_num.getRawBits());
}

bool	Fixed::operator==(const Fixed &fix_num) const {
	return (this->getRawBits() == fix_num.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fix_num) const {
	return (this->getRawBits() != fix_num.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fix_num) const {
	return (Fixed(this->toFloat() + fix_num.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fix_num) const {
	return (Fixed(this->toFloat() - fix_num.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fix_num) const {
	return (Fixed(this->toFloat() * fix_num.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fix_num) const {
	return (Fixed(this->toFloat() / fix_num.toFloat()));
}

Fixed	&Fixed::operator++(void) {
	++this->fix_value;
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	--this->fix_value;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp;
	tmp.fix_value = this->fix_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp;
	tmp.fix_value = this->fix_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed & fix_1, Fixed &fix_2) {
	if (fix_1 > fix_2)
		return fix_1;
	return fix_2;
}

const Fixed	&Fixed::min(const Fixed & fix_1, const Fixed & fix_2) {
	if (fix_1 > fix_2)
		return fix_1;
	return fix_2;
}

Fixed	&Fixed::max(Fixed & fix_1, Fixed &fix_2) {
	if (fix_1 > fix_2)
		return fix_1;
	return fix_2;
}

const Fixed	&Fixed::max(const Fixed & fix_1, const Fixed & fix_2) {
	if (fix_1 > fix_2)
		return fix_1;
	return fix_2;
}