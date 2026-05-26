#include "Data.hpp"

Data::Data(){
	std::cout << "Default Data constructor called" << std::endl;
    _nbr = 0;
    _str = "default";
    _unbr = 0;
    _c = 'a';
}

Data::Data(int nbr, std::string str, unsigned int unbr, char c){
	std::cout << "Default Data constructor called" << std::endl;
    _nbr = nbr;
    _str = str;
    _unbr = unbr;
    _c = c;
}

Data::~Data() { 
	std::cout << "Data has been DESTROYED" << std::endl;
}

Data::Data(const Data &other){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Data &Data::operator=(const Data &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other){
        _nbr = other._nbr;
        _str = other._str;
        _unbr = other._unbr;
        _c = other._c;
    }
	return *this;
}

int Data::getInt() const{
    return this->_nbr;
}

std::string Data::getStr() const{
    return this->_str;
}

unsigned int Data::getUnsignedInt() const{
    return this->_unbr;
}

char Data::getChar() const{
    return this->_c;
}

std::ostream &operator<<(std::ostream &os, Data &f){
    os << "Data:" << std::endl << "Int: " << f.getInt() << std::endl << "Str: " << f.getStr() << std::endl << "Unsigned Int: " << f.getUnsignedInt() << std::endl << "Char: " << f.getChar();
    return os;
}