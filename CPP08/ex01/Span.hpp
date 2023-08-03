#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

class Span {
	private:
		std::vector<int> _vec;
		unsigned int _N;
	public:
	Span();
	Span(unsigned int num);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	void addnumIter(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	class ElementNotFound : public std::exception{
		public:
			virtual const char* what() const throw() {
					return ("Error! You've reached the end of the array..");
			}

	};

	class ArrayTooSmall : public std::exception{
		public:
			virtual const char* what() const throw() {
					return ("Error! Span is too small.. ");
			}

	};
};

#endif