#include "blacklist.h"

void	PhoneBook::AddContact(const Contact& contact) {
	std::cout << std::endl;
	std::cout << "ADDED!" << std::endl;
		if (c_num < 8)
		{
			contacts[c_num] = contact;
			c_num++;
		}
		else 
		{
			for (int i = 0; i < 7; i++)
				contacts[i] = contacts[i + 1];
			contacts[7] = contact;
		}
	}

int		PhoneBook::SearchContact(std::string str_old) {
		std::string str;
		int index = atoi((char *)str_old.c_str());
		if (str_old == "EXIT")
			return 1;
        if (index < 0 || index > 7 || str_old[1]
			|| !(str_old[0] > 47 && str_old[0] < 58) || contacts[index].ContactExist())
		{
			std::cout << "Invalid contact index.." << std::endl;
			sleep(1);
			system("clear");
			return 1;
		}
		std::cout << std::endl;
		std::cout << "index:  " << index << std::endl;
		std::cout << "first_name:  " << contacts[index].displayOne(1) << std::endl;
		std::cout << "last_name:  " << contacts[index].displayOne(2) << std::endl;
		std::cout << "nickname:  " << contacts[index].displayOne(3) << std::endl;
		std::cout << "phone_number:  " << contacts[index].displayOne(4) << std::endl;
		std::cout << "darkest_secret:  " << contacts[index].displayOne(5) << std::endl;
		std::cout << std::endl;
		std::cout << "Enter the index of the contact to display (EXIT to esc): " << std::endl;
		std::getline(std::cin, str);
		SearchContact(str);
		return 0;
    }

void	PhoneBook::DisplayTable() {
	std::cout << "\033[1;37m" << std::setw(10) << "index" << " | "
			<< std::setw(10) << "first_name" << " | "
			<< std::setw(10) << "last_name" << " | "
			<< std::setw(10) << "nickname" << " | "
			<< std::setw(10) << "phone_numb" << " | "
			<< std::setw(10) << "darkest_sec" << "\033[0m" << std::endl;
std::cout << std::setw(10) <<"+----------+------------+------------+------------+------------+------------+" << std::endl;
	for (int i = 0; i < c_num; i++)
	{
		std::cout << std::setw(10) << i << " | "
			<< std::setw(10) << contacts[i].getFormattedString(contacts[i].displayOne(1), 10) << " | "
			<< std::setw(10) << contacts[i].getFormattedString(contacts[i].displayOne(2), 10) << " | "
			<< std::setw(10) << contacts[i].getFormattedString(contacts[i].displayOne(3), 10) << " | "
			<< std::setw(10) << contacts[i].getFormattedString(contacts[i].displayOne(4), 10) << " | "
			<< std::setw(10) << contacts[i].getFormattedString(contacts[i].displayOne(5), 10) << " | " << std::endl;
	}
}