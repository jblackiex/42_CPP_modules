#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	sp.addNumber(1);

	Span sp2 = Span(5);
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(7);
	sp2.addnumIter(vec.begin(), vec.end());
	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	sp2.addNumber(10);

	//srand(time(NULL));

	Span sp3 = Span(10000);
	std::vector<int> vec2;
	for (int i = 0; i < 10000; i++)
		vec2.push_back(i);
	sp3.addnumIter(vec2.begin(), vec2.end());
	std::cout << "Shortest Span (10k): " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest Span(10k): " << sp3.longestSpan() << std::endl;

	std::cout << std::endl << "*Test with negative numbers*" << std::endl << std::endl;
	Span sp4 = Span(5);
	sp4.addNumber(-3);
	sp4.addNumber(-6);
	sp4.addNumber(-9);
	sp4.addNumber(-17);
	sp4.addNumber(-11);
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;


std::cout << std::endl << "*Test with not-full vector*" << std::endl << std::endl;
	Span sp5 = Span(3);
	sp5.addNumber(-9);
	sp5.addNumber(-3);
	std::cout << sp5.shortestSpan() << std::endl;
	std::cout << sp5.longestSpan() << std::endl;
	return 0;
}
