#ifndef POINT_HPP
#define POINT_HPP


#include "Fixed.hpp"

#include <iostream>
#include <cmath>

class Point {
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float val, const float val_1);
	Point(const Point &newobj);
	Point & operator= (const Point &newobj);
	bool	operator== (const Point &newobj) const;
	~Point();

	Fixed	get_x(void) const;
	Fixed	get_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
