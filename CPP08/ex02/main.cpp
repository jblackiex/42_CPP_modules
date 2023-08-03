#include "MutantStack.hpp"
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(2);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	mstack.push(2);
	std::cout << mstack.size() << std::endl;
	//mstack.push(3);
	//mstack.push(5);
	//mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << std::endl << "Iterator: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl << "Reverse iterator: " << std::endl;
	MutantStack<int> s(mstack);
	MutantStack<int>::reverse_iterator rit = s.rbegin();
	MutantStack<int>::reverse_iterator rite = s.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::list<int> list;
	list.insert(list.begin(), mstack.begin(), mstack.end());
	std::cout << std::endl << "List: " << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << std::endl;
	return 0;
}