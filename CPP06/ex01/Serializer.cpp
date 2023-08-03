#include "Serializer.hpp"

Serializer::Serializer(){
  std::cout << "Default constructor called, Welcome to Serializer!" << std::endl;
}

Serializer::~Serializer(){
  std::cout << "Destructor called, Conversion did it!" << std::endl;
}

Serializer::Serializer(const Serializer& obj){
	*this = obj;
}

Serializer& Serializer::operator=(const Serializer& obj){
	if (this != &obj)
		*this = obj;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *data = reinterpret_cast<Data*>(raw);
	return data;
}
