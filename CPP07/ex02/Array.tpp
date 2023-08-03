#include "Array.hpp"

template <class T> Array<T>::Array() : _array(new T[0]), _len(0) {}

template <class T> Array<T>::Array(int len) : _array(new T[len]), _len(len) {}

template <class T> Array<T>::Array(const Array<T> &src) : _array(new T[src._len]), _len(src._len) { 
	for(int i = 0; i < src._len; i++)
		this->_array[i] = src._array[i];
}

template <class T> Array<T> &Array<T>::operator=(const Array<T> &src) {	
	if (this != &src) {
	delete [] this->_array;
	this->_array = new T[src._len];
	for(int i = 0; i < src._len; i++)
		this->_array[i] = src._array[i];
	this->_len = src._len;
	}
	return *this;
}


template <class T> T& Array<T>::operator[](int i) const {
	if (i >= this->_len || i < 0)
		throw std::exception();
	return this->_array[i];
}

template <class T> unsigned int Array<T>::size(void) const {
	return this->_len;
}

template <class T> Array<T>::~Array(void) {
	delete [] this->_array;
}