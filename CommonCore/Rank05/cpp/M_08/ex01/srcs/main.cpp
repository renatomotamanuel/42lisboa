#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    Span big(100000);
    for (int i = 0; i < 100000; ++i)
        big.addNumber(i);
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;
    return 0;
    return 0;
}