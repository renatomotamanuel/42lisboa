#include "Fixed.hpp"

Fixed::Fixed() : _value (0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	_value = value << this->_bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	_value = (roundf(value * (1 << this->_bits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_bits;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const{
	return static_cast<float>(_value) / (static_cast<float>(1 << _bits));
}
	
int Fixed::toInt( void ) const{
	return _value / (1 << _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}