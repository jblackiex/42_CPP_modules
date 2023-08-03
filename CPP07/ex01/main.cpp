#include "iter.hpp"

template <typename T>
void print_memb(T &x)
{
	std::cout << x << " ";
}

int main(void)
{
	int array[5] = {1, 2, 3, 4, 5};
	int len = 5;
	std::string array2[5] = {"Hello", "World", "!", "How", "Are you?"};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Int array: " << std::endl;
	iter(array, len, print_memb<int>);

	std::cout << std::endl << std::endl << "Char array: " << std::endl;

	void *s = reinterpret_cast<void *>(print_memb<char>);
	iter(charArray, 5, reinterpret_cast<void (*)(char&)>(s));


	std::cout << std::endl << std::endl << "String array: " << std::endl;
	iter(array2, len, print_memb<std::string>);

	std::cout << std::endl << std::endl << "Const Char* array: " << std::endl;
	const char *charPointerArray[5] = {array2[0].c_str(), array2[1].c_str(), array2[2].c_str(), array2[3].c_str(), array2[4].c_str()};
	iter(charPointerArray, len, print_memb<const char*>);

	std::cout << std::endl << std::endl;
	sleep(5);
	std::string str;
	std::cout << "Now it' s your turn! type something!" << std::endl;
	std::getline(std::cin, str);
	std::cout << std::endl << "You typed: " << std::endl;
	iter(&str, 1, print_memb<std::string>);
	std::cout << std::endl;
	return 0;
}









/*
::iter(intArray, 5, printElement);
    std::cout << std::endl;

    // Chiamata alla funzione nel namespace MyNamespace
    MyNamespace::iter(intArray, 5, printElement);
    std::cout << std::endl;

    return 0;
}
In questo esempio, la funzione iter è definita sia nello spazio dei nomi globale che in MyNamespace. Utilizzando l'operatore di risoluzione di ambito ::, è possibile specificare quale versione di iter si desidera chiamare. La chiamata ::iter(intArray, 5, printElement) richiama la versione definita nello spazio dei nomi globale, mentre MyNamespace::iter(intArray, 5, printElement) richiama la versione definita in MyNamespace.
*/