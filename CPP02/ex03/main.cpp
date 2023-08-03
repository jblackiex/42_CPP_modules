#include "Point.hpp"

int main( void )
{
	if ( bsp( Point(7, 4), Point(12, 4), Point(11, 7), Point(9, 5) ))
		std::cout << "Punto dentro il triangolo" << std::endl;
	else
		std::cout << "..mi dispiace, wrong choice" << std::endl;
	return 0;
}