#include "PmergeMe.hpp"

bool isSorted(std::vector<unsigned int> vec) {
    if (vec.size() <= 1) {
        return true;
    }

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }

    return true;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PmergeMe sort;
		try {
			sort.check_args_insert(av);
		}
		catch (std::exception &e) {
			return 1;
		}

	if (isSorted(sort.GetVector()))
        std::cout << "Input is sorted." << std::endl;
    else
        std::cout << "Input is not sorted." << std::endl;
	}
	else
		std::cerr << "Error: wrong arguments, min 2 args." << std::endl;
	return 0;
}
