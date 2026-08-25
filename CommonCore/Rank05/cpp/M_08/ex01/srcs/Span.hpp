#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>

class Span {
private:
	unsigned int _maxSize;
    std::vector<int> _values;
public:
	Span();
    Span(int maxSize);
	~Span();
	Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int val);
    int shortestSpan();
    int longestSpan();
};

#endif