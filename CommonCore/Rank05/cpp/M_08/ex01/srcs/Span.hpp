#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <iterator>
# include <stdexcept>

class Span {
private:
	unsigned int _maxSize;
    std::vector<int> _values;
public:
	Span();
    Span(unsigned int maxSize);
	~Span();
	Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int val);
    int shortestSpan();
    int longestSpan();
    template <typename T>
    void addRange(T begin, T end){
        if(_values.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize)
            throw std::runtime_error("Span: Not enough space for range.");
        _values.insert(_values.end(), begin, end);
    }
};



#endif