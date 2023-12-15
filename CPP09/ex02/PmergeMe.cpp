#include "PmergeMe.hpp"

void PmergeMe::incr_time(int flag) {

	if (flag == 42) {
		this->start_time = clock();			
		return ;
	}	
	time_t current_time = clock();
	float tmp_time = static_cast<float>(current_time - this->start_time) / CLOCKS_PER_SEC;
	tmp_time *= 1000000.0f;

	switch (flag) {
		case 0:
			this->time_deque += tmp_time;
			break;
		case 1:
			this->time_vector += tmp_time;
			break;
		default:
			this->time_deque += tmp_time;
			this->time_vector += tmp_time;
	}
	this->start_time = clock();	
}

void PmergeMe::extract_numbers(std::string &numbers, char **av) {
	if (av) {
		int i = 1;
		while (av[i])
		{
			if (std::string(av[i]).empty()){
				std::cerr << "Error: there's an empty string." << std::endl;
				throw std::exception();
			}
			numbers += av[i++] + std::string(" ");
		}
	}
	std::istringstream convert(numbers);
	long long int tmp;
	while (convert >> tmp) {
		if (tmp < 0 || (tmp < std::numeric_limits<unsigned int>::min() || tmp > std::numeric_limits<unsigned int>::max())) {
			if (tmp > 0) std::cerr << "Error: value out of range." << std::endl;
			else std::cerr << "Error: value must be positive." << std::endl;
			throw std::exception();
		}
		incr_time(42);
		this->vector.push_back(static_cast<unsigned int>(tmp));
		incr_time(1);
		incr_time(42);
		this->deque.push_back(static_cast<unsigned int>(tmp));
		incr_time(0);
	}
	if (convert.eof() == false) {
		std::cerr << "Error: Bad values generated." << std::endl;
		throw std::exception();
	}
}

std::string PmergeMe::check_command(std::string const &line) {
	const char *command = NULL;
	std::string res = "";

	if (SYSTEM && !line.find("jot") && line.find("-r") < 10 && line.find("|") < 25 && line.find("tr") < 35 && line.find("n") < 35)
			command = line.c_str();
	else if (!line.find("shuf") && line.find("-i") < 10 && line.find("-n") < 20 && line.find("|") < 30 && line.find("tr") < 35 && line.find("n") < 38)
			command = line.c_str();
	else
		return res;

	FILE *pipe = popen(command, "r");
	if (!pipe) {
		std::cerr << "Error: popen() failed." << std::endl;
		throw std::exception();
	}
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), pipe))
        res += buffer;
	if (pclose(pipe)) {
		std::cerr << "Error: Failed to close command stream." << std::endl;
		throw std::exception();
	}
	return res;
}

// Insertion sort algorithm //
template<typename T> void PmergeMe::insertion_sort(T &c, unsigned int low, unsigned int high) {
	typename T::iterator iter, key;
	typename T::value_type value;

    for (key = (c.begin() + 1 + low); key != c.end() && key != (c.begin() + high + 1); ++key) {
		iter = key - 1; // Initialize iter to the element before current-position
		value = *key; // Store the current-position small value
		// Move current-position small value to num. pos left while value[current-position - 1] > value[current-position]
		while (iter >= (c.begin() + low) && *iter > value) {
			std::swap(*iter, *(iter + 1));
			--iter;
		}
	}
}

template<typename T> void PmergeMe::merge(T &c, T &help, unsigned int low, unsigned int mid, unsigned int high) {

	for (unsigned int i = low; i <= high; i++)
		help[i] = c[i];

	unsigned int help_left = low;
	unsigned int help_right = mid + 1;
	unsigned int curr = low;

	while (help_left <= mid && help_right <= high) {
		if (help[help_left] <= help[help_right]) {
			c[curr] = help[help_left];
			help_left++;
		}
		else {
			c[curr] = help[help_right];
			help_right++;
		}
		curr++;
	}

	if (help_left <= mid)
	{
		unsigned int rem = mid - help_left;
		for (unsigned int i = 0; i <= rem; ++i)
			c[curr + i] = help[help_left + i];
	}
}

// Ford-Johnson algorithm //
template<typename T> void PmergeMe::merge_isort(T &c, T &help, unsigned int low, unsigned int high) {

		if (high - low > INSERTION_K) { 
			unsigned int mid = low + (high - low) / 2;
			merge_isort(c, help, low, mid);
			merge_isort(c, help, mid + 1, high);
			merge(c, help, low, mid, high);
		}
		else
			insertion_sort(c, low, high);
}

void PmergeMe::print_numbers() {
	// int count = 1;
	std::vector<unsigned int>::const_iterator it;
	for(it = this->vector.begin(); it != this->vector.end(); ++it)
		std::cout << *it << " ";
	if (it != this->vector.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::check_args_insert(char **av) {
	std::string numbers = "";

	if (this->done == false ) {
	this->start_time = clock();
	if (av[1] && !std::string(av[1]).empty()) {
		numbers = check_command(av[1]);
		incr_time(2);
		if (numbers.empty())
			extract_numbers(numbers, av);
		else
			extract_numbers(numbers, NULL);
	}
	else {
		std::cerr << "Error" << std::endl;
		throw std::exception();
	}
	this->dim = this->deque.size();
	if (this->dim - 1 > 10000000) {
			std::cerr << "Error: something wrong. Check for spaces." << std::endl;
			throw std::exception();
		}
	std::cout << std::endl << "Before:  ";
	std::deque<unsigned int> help_deque(this->dim);
	std::vector<unsigned int> help_vector(this->dim);
	print_numbers();
	incr_time(2);
	incr_time(42);
	merge_isort(this->deque, help_deque, 0, this->dim - 1);
	incr_time(0);
	incr_time(42);
	merge_isort(this->vector, help_vector, 0, this->dim - 1);
	incr_time(1);
	std::cout << std::endl << "After:   ";
	print_numbers();
	std::cout << std::endl << "---> " << BOLD << "time " << END << "to process a range of " << this->dim << " elements with " << RED << "std::deque: " << END << std::fixed << this->time_deque << " us";
	std::cout << std::endl << "--> " << BOLD << "time " << END << "to process a range of " << this->dim << " elements with " << GREEN << "std::vector: " << END << std::fixed << this->time_vector << " us" << std::endl;
	this->done = true;
	}
	else
		std::cout << "Vector and Deque already filled, call Getters." << std::endl;
}

std::deque<unsigned int>& PmergeMe::GetDeque() {

	if (this->done == true)
		return this->deque;
	else
	{
		std::cerr << "Vector && Deque not filled, call check_args_insert()" << std::endl;
		throw std::exception();
	}
}

std::vector<unsigned int>& PmergeMe::GetVector() {

	if (this->done == true)
		return this->vector;
	else
	{
		std::cerr << "Vector && Deque not filled, call check_args_insert()" << std::endl;
		throw std::exception();
	}
}

PmergeMe::PmergeMe() { this->done = false; this->dim = 0; this->time_deque = 0; this->time_vector = 0; }

PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->vector = rhs.vector;
		this->deque = rhs.deque;
		this->done = rhs.done;
		this->dim = rhs.dim;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// clock() measures CPU time used by the program,
// which is different from wall clock time.
// If you're interested in measuring real time regardless of how much CPU time your program is using,
// you might want to use other functions like std::chrono library functions in modern C++.