#include "Point.hpp"

Fixed	max_min(const Point &p1, const Point &p2, std::string str) {
	if (str == "min")
		return (p1.get_x() < p2.get_x() ? p1.get_x() : p2.get_x());
	return (p1.get_x() > p2.get_x() ? p1.get_x() : p2.get_x());
}

Fixed	may_min(const Point &p1, const Point &p2, std::string str) {
	if (str == "min")
		return (p1.get_y() < p2.get_y() ? p1.get_y() : p2.get_y());
	return (p1.get_y() > p2.get_y() ? p1.get_y() : p2.get_y());
}

Fixed	comp_final(const Fixed &p1, const Fixed &p2, std::string str) {
	if (str == "min")
		return (p1 < p2 ? p1 : p2);
	return (p1 > p2 ? p1 : p2);
}

// guardo quali sono i lati giusti, i 2 lati dai quali passa la retta //
bool	check_section(const Point &p1, const Point &p2, const Fixed &intx, const Fixed &intx2, const Point &p3, const Point &p4)
{
	int count;

	count = 0;
	if (((max_min(p1, p2, "min") < intx) && (intx < max_min(p1, p2, "max"))))
		count++;
	if (((max_min(p3, p4, "min") < intx2) && (intx2 < max_min(p3, p4, "max"))))
		count++;
	if (count == 2)
		return true;
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	int	count;
	int count2;
	
	count = 0;
	count2 = 0;
	if (a == point || b == point || c == point)
		return false;

	// Calcolo le equazioni delle rette dei lati del triangolo con coeff ang e q (termine noto) //
	Fixed m_ab = (b.get_y() - a.get_y()) / (b.get_x() - a.get_x());
	Fixed q_ab = a.get_y() - m_ab * a.get_x();

	Fixed m_bc = (c.get_y() - b.get_y()) / (c.get_x() - b.get_x());
	Fixed q_bc = b.get_y() - m_bc * b.get_x();

	Fixed m_ca = (a.get_y() - c.get_y()) / (a.get_x() - c.get_x());
    Fixed q_ca = c.get_y() - m_ca * c.get_x();

	// Calcolo le intersezioni tra la retta che passa per il punto e i lati del triangolo //
	Fixed intersection_ab_x = (point.get_y() - q_ab) / m_ab;
	Fixed intersection_bc_x = (point.get_y() - q_bc) / m_bc;
	Fixed intersection_ca_x = (point.get_y() - q_ca) / m_ca;

	// Verifico se i punti di intersezione ci sono, esistono //
	if (((max_min(a, b, "min") <= intersection_ab_x) && (intersection_ab_x <= max_min(a, b, "max")))
		&& ((may_min(a, b, "min") < point.get_y()) && (point.get_y() < may_min(a, b, "max"))))
		count++;

	if (((max_min(b, c, "min") <= intersection_bc_x) && (intersection_bc_x <= max_min(b, c, "max")))
		&& ((may_min(b, c, "min") < point.get_y()) && (point.get_y() < may_min(b, c, "max"))))
		count++;

	if (((max_min(c, a, "min") <= intersection_ca_x) && (intersection_ca_x <= max_min(c, a, "max")))
		&& ((may_min(c, a, "min") < point.get_y()) && (point.get_y() < may_min(c, a, "max"))))
		count++;

	if (count >= 2)
	{
		// se esistono i punti, verifico che il punto da me scelto sia in mezzo alla retta formata da questi 2; se e' cosi significa che e' dentro al triangolo //
		if (check_section(b, c, intersection_bc_x, intersection_ca_x, c, a) && ((comp_final(intersection_bc_x, intersection_ca_x, "min") < point.get_x()) && (point.get_x() < comp_final(intersection_bc_x, intersection_ca_x, "max"))))
			count2++;
		if (check_section(a, b, intersection_ab_x, intersection_ca_x, c, a) && ((comp_final(intersection_ab_x, intersection_ca_x, "min") < point.get_x()) && (point.get_x() < comp_final(intersection_ab_x, intersection_ca_x, "max"))))
			count2++;
		if (check_section(a, b, intersection_ab_x, intersection_bc_x, b, c) && ((comp_final(intersection_ab_x, intersection_bc_x, "min") < point.get_x()) && (point.get_x() < comp_final(intersection_ab_x, intersection_bc_x, "max"))))
			count2++;
		if (count2)
			return true;
	}
	return false;
}

// VERSIONE FUNZIONANTE MA CON LE INEQUAZIONI E IL PRODOTTO VETTORIALE TRA I SEGMENTI //

/*bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	if (a == point || b == point || c == point)
		return false;
	Fixed ineq = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (point.get_x() - a.get_x());
	Fixed ineq2 = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) - (c.get_y() - b.get_y()) * (point.get_x() - b.get_x());
	Fixed ineq3 = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) - (a.get_y() - c.get_y()) * (point.get_x() - c.get_x());

	if (ineq >= 0 && ineq2 >= 0 && ineq3 >= 0)
	{
		if (ineq == 0 || ineq2 == 0 || ineq3 == 0)
		{
			std::cout << "Hai preso un punto su un lato" << std::endl;
			return false;
		}
		return true;
	}
	return false;
}
*/

// VERSIONE FUNZIONANTE calcolo AREA triangoli minori interni //

/* Fixed	calcolaAreaTriangolo(const Fixed &x1, const Fixed &y1, const Fixed &x2, const Fixed &y2, const Fixed &x3, const Fixed &y3){
	Fixed sin = (0.5F);
	Fixed area = sin * ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
	if (area < 0)
		area = area * -1;
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	if (a == point || b == point || c == point)
		return false;

	Fixed areaTOT = calcolaAreaTriangolo(a.get_x(), a.get_y(), b.get_x(), b.get_y(), c.get_x(), c.get_y());
	Fixed areaPOINT1 = calcolaAreaTriangolo(point.get_x(), point.get_y(), a.get_x(), a.get_y(), b.get_x(), b.get_y());
	Fixed areaPOINT2 = calcolaAreaTriangolo(point.get_x(), point.get_y(), a.get_x(), a.get_y(), c.get_x(), c.get_y());
	Fixed areaPOINT3 = calcolaAreaTriangolo(point.get_x(), point.get_y(), c.get_x(), c.get_y(), b.get_x(), b.get_y());

	if (areaPOINT1 == 0 || areaPOINT2 == 0 || areaPOINT3 == 0)
	{
		std::cout << "Point on Edge." << std::endl;
		return false;
	}
	Fixed pointTOT = areaPOINT1 + areaPOINT2 + areaPOINT3;
	std::cout << "Area triangolini = " << pointTOT << std::endl;
	std::cout << "Area triangolo = " << areaTOT << std::endl;
	if (areaTOT == pointTOT)
		return true;
	return false;
}
*/
