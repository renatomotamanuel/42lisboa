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

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->_value + other._value);
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->_value - other._value);
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed((this->_value * (1 << _bits)) / other._value);
}


bool Fixed::operator>(const Fixed &other) const {
	return this->_value > other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_value >= other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_value != other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_value == other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_value <= other._value;
}

Fixed &Fixed::operator++(){
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--(){
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	this->_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}