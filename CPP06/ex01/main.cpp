#include "Serializer.hpp"

int main()
{
	Data tmp;

	tmp.data = 42;
	std::cout << "Data: " << tmp.data << std::endl;
	uintptr_t raw = Serializer::serialize(&tmp);
	std::cout << "Raw_serializer: " << raw << std::endl;
	Data *data = Serializer::deserialize(raw);
	std::cout << "Data_deserializer: " << data->data << std::endl;
	return 0;
}