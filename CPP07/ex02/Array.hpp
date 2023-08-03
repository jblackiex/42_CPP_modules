#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#include <unistd.h>

template <class T>
class Array{
	private:
		T *_array;
		int _len;
	public:
		Array();
		Array(int len);
		Array(const Array<T> &src);
		~Array(void);

		Array &operator=(const Array<T> &src);

		T &operator[](int i) const;

		unsigned int size(void) const;
};

#include "Array.tpp"

#endif