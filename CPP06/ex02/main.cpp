#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int tmp = rand() % 3;
	switch (tmp)
	{
	case 0:
		std::cout << "A generated" << std::endl;
		return new A;
	case 1:
		std::cout << "B generated" << std::endl;
		return new B;
	case 2:
		std::cout << "C generated" << std::endl;
		return new C;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try{
	A &tmp = dynamic_cast<A &>(p);
	std::cout << "A" << std::endl;
	(void)tmp;
	}
	catch (std::exception &e) {
	try{
	B &tmp2 = dynamic_cast<B &>(p);
	std::cout << "B" << std::endl;
	(void)tmp2;
	}
	catch (std::exception &e) {
	try{
	C &tmp3 = dynamic_cast<C &>(p);
	std::cout << "C" << std::endl;
	(void)tmp3;	
	}
	catch (std::exception &e) {
	std::cout << "Unknown" << std::endl;
	}
	}
	}
}

int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}