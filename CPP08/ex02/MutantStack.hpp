#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <deque>

template <class T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"

// La keyword *typename* viene utilizzata principalmente 
// nella definizione di template per specificare 
// che una particolare espressione è un tipo, 
// anche se il compilatore non può determinarlo immediatamente.