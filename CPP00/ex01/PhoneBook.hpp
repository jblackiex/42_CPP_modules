# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "blacklist.h"

class PhoneBook {
private:
	Contact		contacts[8];
	short int	c_num;

public:

    PhoneBook() : c_num(0) {}
	~PhoneBook() {}

	void	AddContact(const Contact& contact);
	int		SearchContact(std::string str_old);
	void	DisplayTable();
};

#endif