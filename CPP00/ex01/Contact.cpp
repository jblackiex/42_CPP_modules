#include "blacklist.h"

std::string	Contact::getFormattedString(const std::string& str, int width) {
        if ((int) str.length() <= width)
			return std::string(width - str.length(), ' ') + str;
        else
            return str.substr(0, width - 1) + ".";
    }

std::string	Contact::displayOne(int info) {
		switch (info) {
			case 1: return (std::string (first_name));
			case 2: return (std::string (last_name));
			case 3: return (std::string (nickname));
			case 4: return (std::string (phone_number));
			case 5: return (std::string (darkest_secret));;
		}
		return NULL;
    }

bool		Contact::ContactExist() {
		if (first_name.empty() || last_name.empty() || nickname.empty()
			|| phone_number.empty() || darkest_secret.empty())
			return true;
		else
			return false;
	}