#ifndef iter_HPP
#define iter_HPP

#include <iostream>
#include <string>

#include <unistd.h>

template <typename T, typename F>
void iter(T *array, size_t len, F f){
	for(size_t i = 0; i < len; i++)
		f(array[i]);
};

#endif
