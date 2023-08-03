# ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <cctype>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );
#endif