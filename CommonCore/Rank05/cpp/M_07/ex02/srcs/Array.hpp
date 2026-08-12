#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>


template<typename T>class Array{
private:
    T *_arr;
    int _max;
public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);
    T &operator[](int pos);
    int size() const;
    T getVal(int i) const;
};

#include "Array.tpp"


#endif