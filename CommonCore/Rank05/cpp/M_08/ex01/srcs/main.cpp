#include "Span.hpp"

int main()
{
    try {
        Span full(2);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
    }
    catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
    }
    try {
        Span empty(5);
        empty.shortestSpan();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Span one(5);
        one.addNumber(42);
        one.longestSpan();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
    std::vector<int> v(10, 1);
    Span small(5);
    small.addRange(v.begin(), v.end());
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
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
    std::vector<int> v;
    v.push_back(6);
    v.push_back(3);
    v.push_back(17);
    v.push_back(9);
    v.push_back(11);
    Span vec(5);
    vec.addRange(v.begin(), v.end());
    std::cout << vec.shortestSpan() << std::endl;
    std::cout << vec.longestSpan() << std::endl;
    return 0;
}