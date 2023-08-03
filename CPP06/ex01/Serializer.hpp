#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#include "Data.h"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &obj);
	~Serializer();
	Serializer &operator=(const Serializer &obj);

	static char _char;
	static int _int;
	static float _float;
	static double _double;
	static bool _flag_error;
	static bool _flag_inf;
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif