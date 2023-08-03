#ifndef easyfind_HPP
#define easyfind_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
	public:
	class ElementNotFound : public std::exception{
		public:
			virtual const char* what() const throw() {
					return ("Element not found");
			}

	};
};

#endif

template <typename T>
void easyfind(const T& elem, int num){
	int	j;
	int count;

	j = 0;
	count = 0;
	for (typename T::const_iterator i = elem.begin(); i != elem.end(); i++) {
		if (*i == num)
		{
			j = 1;
			break ;
		}
		count++;
	}
	if (!j)
	{
		std::cout << num << " Error" << std::endl;
		throw Vector::ElementNotFound(); 
	}
	std::cout << "Element " << num << " found at the " << "position number " << count << std::endl;
};


#endif