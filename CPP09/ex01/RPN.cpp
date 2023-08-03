#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const &av1){ this->input = av1; this->total = 0;}

void RPN::gen_value(void)
{
	int tmp;

	if (swap && nums.top() != total)
	{
		tmp = nums.top();
		nums.pop();
		int tmp2 = nums.top();
		nums.pop();
		nums.push(tmp);
		nums.push(tmp2);
	}
	tmp = nums.top();
	if (nums.size() != 1 || nums.top() == total)
		nums.pop();
			switch (sign)
			{
			case '+':
				tmp += nums.top();
				break;
			case '-':
				tmp -= nums.top();
				break;
			case '*':
				tmp *= nums.top();
				break;
			case '/':
				if (nums.top() == 0)
				{
					std::cout << "Error: division by zero." << std::endl;
					exit(1);
				}
				tmp /= nums.top();
				break;
			}
			//std::cout << nums.top() << "prima" << std::endl;
			if (nums.size() != 1 || nums.top() == total)
				nums.pop();
			//std::cout << nums.top() << "dopo" << std::endl;
			this->total = tmp;
			swap = 1;
			nums.push(total);
}

void RPN::check_args_insert(void)
{
	int i = 0;
	int flag = 1;
	int sum = 0;
	int sum2 = 0;
	this->swap = 0;
	if (check_line(&input[i], 1) && input[i + 1] && check_line(&input[i + 1], 2))
		;
	else if (check_line(&input[i], 1) || (!check_line(&input[input.size() - 1], 1)
		&& !check_line(&input[input.size() - 1], 3)))
		flag = 0;
	while(flag && this->input[i])
	{
		if ((!i || !(i % 2)) && input[i + 1] && input[i] == '-' && check_line(&input[i], 3))
		{
			input = input.substr(i + 1, input.size() - (i + 1));
			i = 1;
			continue;
		}
		if ((nums.empty() || nums.size() < 2) && check_line(&input[i], 1))
			flag = 0;
		else if (i && (i % 2) && check_line(&input[i], 2))
			flag = 0;
		else if ((!i || !(i % 2)) && input[i + 1] && !check_line(&input[i], 1))
		{
			if (!check_line(&input[i], 3))
				flag = 0;
		}
		if (check_line(&input[i], 1))
		{
			sum = 1;
			if (nums.top() == total && nums.size() == 2)
				sum2++;
			if (sum2 == 2)
				break;
			gen_value();
		}
		i++;
	}
	if (!flag || !sum) //"5 7 6 8 + + +" // ./RPN "+ 7 7 * 7 -"
		std::cout << "Error: invalid input." << std::endl;
	else
		std::cout << this->total << std::endl;
}

RPN::RPN(RPN const &src) { *this = src; }

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->input = rhs.input;
		this->nums = rhs.nums;
		this->total = rhs.total;
	}
	return *this;
}

RPN::~RPN() {}