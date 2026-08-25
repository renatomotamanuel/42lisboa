#include "Span.hpp"

Span::Span() : _maxSize(10){}

Span::Span(int maxSize) : _maxSize(maxSize){}

Span::~Span() {}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_values = other._values;
	}
	return *this;
}

void Span::addNumber(int val){
    if(_values.size() >= _maxSize)
        throw std::runtime_error("Span: Vector is full.");
    _values.push_back(val);
}

int Span::shortestSpan(){
    if(_values.size() < 2)
        throw std::runtime_error("Span: Not enough values in vector.");
    std::vector<int> temp = _values;
    std::sort(temp.begin(), temp.end());
    int small = temp[1] - temp[0];
    for(size_t i = 2; i < temp.size(); i++){
        int diff = temp[i] - temp[i - 1];
        if(diff < small)
            small = diff;
    }
    return small;
}

int Span::longestSpan(){
    if(_values.size() < 2)
        throw std::runtime_error("Span: Not enough values in vector.");
    std::vector<int> temp = _values;
    std::sort(temp.begin(), temp.end());
    return temp.back() - temp.front();
}
