#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default Constructor called" << std::endl;
	this->fix_value = 0;
}

Fixed::Fixed(const Fixed &newobj) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = newobj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator= (const Fixed &newobj)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &newobj)
		this->fix_value = newobj.fix_value;
	
	return(*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits" << std::endl;
	return(this->fix_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits" << std::endl;
	this->fix_value = raw;
}