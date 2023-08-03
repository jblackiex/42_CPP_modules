#ifndef whatever_HPP
#define whatever_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b){
	T c = a;
	a = b;
	b = c;
};

template <typename T>
T min(T a, T b){
	return a >= b ? b : a;	
};

template <typename T>
T max(T a, T b){
	return b >= a ? b : a;	
};

#endif