#include "MutantStack.hpp"

template <class T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <class T> MutantStack<T>::~MutantStack() {}

template <class T> MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
    *this = copy;
}

template <class T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy) {
    if (this != &copy)
        std::stack<T>::operator=(copy);
    return *this;
}

template <class T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<class T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template<class T> typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const{
	return this->c.begin();
}

template<class T> typename MutantStack<T>::const_iterator MutantStack<T>::cend() const{
	return this->c.end();
}

template<class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
	return this->c.rbegin();
}

template<class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
	return this->c.rend();
}

template<class T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const {
	return this->c.rbegin();
}

template<class T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const {
	return this->c.rend();
}
