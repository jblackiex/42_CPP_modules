#include "Point.hpp"

Point::Point() : x(0), y(0) {
	//std::cout << "Default Constructor Point called" << std::endl;
}

Point::Point(const float val, const float val_1) : x(val), y(val_1) {
	//std::cout << "Float Constructor Point called" << std::endl;
}

Point::Point(const Point &newobj) : x(newobj.x), y(newobj.y) {
	//std::cout << "Copy Constructor Point called" << std::endl;
}

Point::~Point()
{
	//std::cout << "Destructor Point called" << std::endl;
}

Fixed	Point::get_x(void) const {
	return (this->x);
}

Fixed	Point::get_y(void) const {
	return (this->y);
}

bool	Point::operator== (const Point &newobj) const{
	if (this->x == newobj.x && this->y == newobj.y)
	{
		std::cout << "Hai scelto un vertice del triangolo" << std::endl;
		return true;
	}
	return false;
}

Point & Point::operator= (const Point &newobj) {
	//std::cout << "Assignment operator called" << std::endl;
	if (this != &newobj)
	{
		this->get_x() = newobj.get_x();
		this->get_y() = newobj.get_y();
	}
	return(*this);
}