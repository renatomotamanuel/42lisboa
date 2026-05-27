#include "Serializer.hpp"

Serializer::Serializer(){

}

Serializer::~Serializer() { 
}

Serializer::Serializer(const Serializer &other){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t temp = reinterpret_cast<uintptr_t>(ptr);
    return temp;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *temp = reinterpret_cast<Data *>(raw);
    return temp;
}
