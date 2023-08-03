#include "Array.hpp"

int main(void)
{
	Array<int> intArray(5);
	Array<std::string> strArray(5);

	for (int i = 0; i < 5; i++)
	{
		intArray[i] = i;
		strArray[i] = i + 48;
	}

	std::cout << "intArray: ";
	for (int i = 0; i < 5; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "strArray: ";
	for (int i = 0; i < 5; i++)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << "intArray[4]: " << intArray[4] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "intArray[4]: " << e.what() << std::endl;
	}

	try {
		std::cout << "intArray[5]: " << intArray[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "intArray[5]: " << e.what() << std::endl;
	}

	try {
		std::cout << "strArray[-5]: " << strArray[-5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "strArray[5]: " << e.what() << std::endl;
	}
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