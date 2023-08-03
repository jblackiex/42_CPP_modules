#include "blacklist.h"

void	createContact(std::string& firstName, std::string& lastName,
					std::string& nickname, std::string& phoneNumber,
					std::string& DarkestSecret) {
	std::cout << "Enter First Name: " << std::endl ;
	std::getline(std::cin, firstName);

	std::cout << "Enter Last Name: " << std::endl ;
	std::getline(std::cin, lastName);

	std::cout << "Enter Nickname: " << std::endl ;
	std::getline(std::cin, nickname);

	std::cout << "Enter Phone Number: " << std::endl ;
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter your Darkest Secret: " << std::endl ;
	std::getline(std::cin, DarkestSecret);
}

void	SearchContact_base(PhoneBook *blacklist)
{
	std::string str;

	system("clear");
	blacklist->DisplayTable();
	std::cout << "Enter the index of the contact to display: " << std::endl;
	std::getline(std::cin, str);
	blacklist->SearchContact(str);
}

int	main()
{
    PhoneBook	blacklist;
	std::string	command;
	std::string firstName, lastName, nickname, phoneNumber, DarkestSecret;

	system("clear");
	while (true) 
	{
		std::cout << "Blacklist: " << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "" || command == "clear")
			system("clear");
		else if (command == "ADD")
		{
			createContact(firstName, lastName, nickname, phoneNumber, DarkestSecret);
			Contact	newcontact(firstName, lastName, nickname, phoneNumber, DarkestSecret);
			if (!newcontact.ContactExist())
				blacklist.AddContact(newcontact);
		}
		else if (command == "SEARCH")
			SearchContact_base(&blacklist);
	}
	return 0;
}