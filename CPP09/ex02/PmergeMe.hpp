#pragma once

#ifdef __APPLE__
	#define SYSTEM 1
#elif __linux__
	#define SYSTEM 0
#endif

// Insertion sort param //
#define INSERTION_K 5


#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>

//COLORS
#define RED "\033[1;31m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define END "\033[0m"

class PmergeMe {
	private:
		std::deque<unsigned int> deque;
		std::vector<unsigned int> vector;
		bool done;
		unsigned int dim;
		float time_deque;
		float time_vector;
		clock_t start_time;

		void print_numbers();
		void incr_time(int flag);
		std::string check_command(std::string const &line);
		void extract_numbers(std::string &numbers, char **av);


		// Ford-Johnson algorithm //
		template <typename T>
		void merge(T &c, T &help, unsigned int low, unsigned int mid, unsigned int high);
		template <typename T>
		void insertion_sort(T &c, unsigned int low, unsigned int high);
		template <typename T>
		void merge_isort(T &c, T &help, unsigned int low, unsigned int high); 
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();

		std::deque<unsigned int>& GetDeque();
		std::vector<unsigned int>& GetVector();
		void check_args_insert(char **av);
};
