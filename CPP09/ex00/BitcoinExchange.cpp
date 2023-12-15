#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &av1)
{
	std::string tmp;
	this->file.open(av1.c_str());
	this->csv.open("data.csv");
	if (!std::getline(this->csv, tmp))
	{
		std::cerr << "Error: file csv empty." << std::endl;
		throw BitcoinExchange::BadFile();
	}
	this->input = av1;
	if (!file || !csv || !file.is_open() || !csv.is_open())
		throw BitcoinExchange::BadFile();
}

void BitcoinExchange::insert_value(std::string const &line, int count)
{
	csv.seekg(0);
	std::string tmp;
	std::string tmp_csv = "";
	int count2 = 0;
	std::string c = " => ";
	long unsigned int i = 13;
	if (line[13] == '.')
		count2++;
	while(!count2 && i < line.size())
	{
		if (line[i] == ' ' || line[i] == '	') {
			count2++;
			tmp_csv = "   <--cut spaces";
			break ;
		}
		if (!isdigit(line[i]) && line[i] != '.')
			count2++;
		i++;
	}
	if (line[11] != '|' || line[12] != ' ' || count2)
	{
		tmp = "Error: bad input => " + line;
		tmp +=  tmp_csv;
		_map.insert(std::make_pair(count, std::make_pair(tmp, -1.0f)));
		return ;
	}
	count2 = 0;
	while (std::getline(this->csv, tmp))
	{
		if (count2 && (tmp.substr(0, 10).compare(line.substr(0, 10))) >= 0)
		{
			std::string line2;
			std::string tmp2;
			float num_csv;
			if ((tmp.substr(0, 10).compare(line.substr(0, 10))))
				num_csv = atof(&tmp_csv.c_str()[11]);
			else
				num_csv = atof(&tmp.c_str()[11]);
			float num = atof(line.substr(13, line.size() - 1).c_str());
			std::stringstream str;
			std::stringstream str2;
			str << std::fixed << std::setprecision(2) << num;
			str2 << std::fixed << std::setprecision(2) << num_csv;
			line2 = str.str();
			tmp2 = str2.str();
			num = atof(line2.c_str());
			num_csv = atof(tmp2.c_str());
			num = num * num_csv;
			_map.insert(std::make_pair(count, std::make_pair(line.substr(0, 10).append(c).append(line.substr(13, line.size() - 1)).append(" = "), num)));
			break ;
		}
		if (!count2)
			count2 = 1;
		tmp_csv = tmp;
	}
}

void BitcoinExchange::check_file_print(void)
{
	int count = 0;
	std::string bad_input;
	std::string line;

	while (std::getline(this->file, line))
	{
		bad_input = "Error: bad input => ";
		if (!count && line.compare("date | value"))
			throw BitcoinExchange::BadFile();
		else if (count)
		{
			if (line.size() <= 2 || check_line(&line[4], 1) || check_line(&line[7], 1))
				_map.insert(std::make_pair(count - 1, std::make_pair("Error: not a valid Date", -1.0f)));
			else if (check_line(&line[11], 2) || check_line(line, 4))
				_map.insert(std::make_pair( count - 1, std::make_pair(bad_input.append(line), -1.0f)));
			else if (atof(line.substr(0, 4).c_str()) < 2008)
				_map.insert(std::make_pair(count - 1, std::make_pair("Error: bitcoin was invented in 2008.. cut the spaces", -1.0f)));
			else if (line[line.size() - 2] == '-' && !check_line(&line[line.size() - 1], 3))
				_map.insert(std::make_pair(count - 1, std::make_pair("Error: not a positive number.", -1.0f)));
			else if (atof(line.substr(13, line.size() - 1).c_str()) > 2000)
				_map.insert(std::make_pair(count - 1, std::make_pair("Error: too large a number.", -1.0f)));
			else
				insert_value(line, count - 1);
		}
		count++;
	}
	print(_map, _map.size());
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_map = rhs._map;
		this->file.open(rhs.input.c_str());
		try {
			this->csv.open("data.csv");
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: could not open file." << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() { file.close(); csv.close(); }