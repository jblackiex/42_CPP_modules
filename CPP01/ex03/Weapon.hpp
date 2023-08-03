#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <cstring>

class Weapon {
private:
    std::string type;

public:
	Weapon() {};
	Weapon(std::string type) { this->type = type; };
	~Weapon() {};
	std::string& getType();
	void setType(const std::string& newType);
};

#endif