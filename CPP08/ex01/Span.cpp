#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int num) : _N(num) {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &copy) {
	if (this != &copy)
	{
		this->_vec = copy._vec;
		this->_N = copy._N;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (this->_N == 0)
	{
		try{
			throw Span::ElementNotFound();
		}
		catch (Span::ElementNotFound &e)
		{
				std::cout << e.what() << "can' t add " << num << std::endl;
		}
	}
	this->_N--;
	this->_vec.push_back(num);
}

unsigned int Span::longestSpan() {
	int add_1 = 0;
	if (_vec.size() <= 1)
	{
		try{
		throw Span::ArrayTooSmall();
		}
		catch (Span::ArrayTooSmall &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::vector<int> _vec2(_vec.size());
	std::copy(_vec.begin(), _vec.end(), _vec2.begin());
	std::sort(_vec2.begin(), _vec2.end());
	if (*(_vec2.begin()) == 0)
		add_1 = 1;
	if (*(_vec2.end() - 1) < 0 && *(_vec2.begin()) < 0)
		return ((-*(_vec2.begin())) + *(_vec2.end() - 1));
	else
		return ((*(_vec2.end() - 1) + add_1) - *(_vec2.begin()));
}

unsigned int Span::shortestSpan() {
	if (_vec.size() <= 1)
	{
		try{
		throw Span::ArrayTooSmall();
		}
		catch (Span::ArrayTooSmall &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::vector<int> _vec2(_vec.size());
	std::copy(_vec.begin(), _vec.end(), _vec2.begin());
	std::sort(_vec2.begin(), _vec2.end());
	int tmp = 0;
	bool flag_neg = false;
	if (*(_vec2.begin()) < 0 && *(_vec2.begin() + 1) < 0)
	{
		flag_neg = true;
		tmp =  ((-*(_vec2.begin())) + *(_vec2.begin() + 1));
	}
	else
		tmp = (*(_vec2.begin() + 1)) - *(_vec2.begin());
	for(std::vector<int>::const_iterator i = _vec2.begin(); i != (_vec2.end() - 1); i++)
	{
		if (flag_neg && *(i + 1) - *(i) < tmp)
			tmp = ((-*i) + *(i + 1));
		else if (*(i + 1) - *(i) < tmp)
			tmp = *(i + 1) - *(i);
	}
	if (!tmp)
		tmp = 1;
	return tmp;
}

void Span::addnumIter(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for(std::vector<int>::const_iterator i = begin; i != end; i++)
	{
		if (_N == 0)
		{
			try{
				throw Span::ElementNotFound();
			}
			catch (Span::ElementNotFound &e)
			{
				std::cout << e.what() << "can' t add " << *begin << std::endl;
			}
		}
		_vec.push_back(*i);
		_N--;
	}
}

Span::~Span() {}