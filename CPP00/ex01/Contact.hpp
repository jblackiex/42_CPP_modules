# ifndef CONTACT_HPP
# define CONTACT_HPP

#include "blacklist.h"

class Contact {
private:
    std::string	first_name;
    std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact() {} // Costruttore di default

	Contact(const std::string& firstName, const std::string& lastName,
            const std::string& nickname, const std::string& phoneNumber, const std::string& DarkestSecret)
            : first_name(firstName), last_name(lastName),
              nickname(nickname), phone_number(phoneNumber), darkest_secret(DarkestSecret) {}
	~Contact() {}

	std::string getFormattedString(const std::string& str, int width);
	std::string	displayOne(int info);
	bool		ContactExist();
};

#endif