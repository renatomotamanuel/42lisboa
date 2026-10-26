#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# include <string>

template <typename T>
void swap(T &x, T &y){
    T z;
    z = x;
    x = y;
    y = z;
}

template <typename T>
T const &min(T const &x, T const &y){
    if(x >= y)
        return y;
    return x;
}

template <typename T>
T const &max(T const &x, T const &y){
    if(x > y)
        return x;
    return y;
}

#endif