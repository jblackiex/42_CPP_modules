#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

class RPN {
	private:
		std::stack<int> nums;
		std::string input;
		char sign;
		int total;
		int swap;
		RPN();

		template <typename retPass>
		bool check_line(std::string const &line, retPass i) {
			switch (i)
			{
			case 1:
				if (line[0] == '+' || line[0] == '-' || line[0] == '*' || line[0] == '/')
				{
					this->sign = line[0];
					return true;
				}
				return false;
			case 2:
				if (line[0] != 32)
					return true;
				return false;
			case 3:
				if (std::isdigit(line[0]))
				{
					this->nums.push(line[0] - 48);
					return true;
				}
				else if (line[0] == '-' && std::isdigit(line[1]))
				{
					int tmp = (line[1] - 48) * -1;
					return(nums.push(tmp), true);
				}
				return false;
			}
			return true;
		}

		void gen_value();

	public:
		RPN(std::string const &av1);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();

		void check_args_insert();
	
};
