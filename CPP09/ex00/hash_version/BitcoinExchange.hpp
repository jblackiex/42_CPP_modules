#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

class BitcoinExchange {
	private:
		std::map<float, std::pair<std::string, float> > _map;
		std::ifstream file;
		std::ifstream csv;
		std::string input;
		BitcoinExchange();

		template <typename T>
		void print(std::map<float, std::pair<std::string, float> > const &t, T const &i) {
			if (i == _map.size())
			{
				for (std::map<float, std::pair<std::string, float> >::const_iterator it = t.begin(); it != t.end(); it++) {
						if (it->second.second == -1.0f)
							std::cout << it->second.first << std::endl;
						else
							std::cout << it->second.first << it->second.second << std::endl;
			}

			}
		}

		template <typename retPass>
		bool check_line(std::string const &line, retPass i) {
			switch (i)
			{
			case 1:
				if (line.find("-") == std::string::npos)
					return true;
				return false;
			case 2:
				if (line.find("|") == std::string::npos)
					return true;
				return false;
			case 3:
				if (!std::isdigit(line[0]))
					return true;
				return false;
			case 4:
				if (atof(line.substr(5, 2).c_str()) > 12 || atof(line.substr(8, 2).c_str()) > 31 ||
					atof(line.substr(0, 4).c_str()) > 2022)
					return true;
				return false;
			}
			return false;
		}

		void insert_value(std::string const &line, int count);

	public:
		BitcoinExchange(std::string const &av1);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		void check_file_print();
	
	
	class BadFile : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "Not a Good File! Try Again";
			}
	};
};
