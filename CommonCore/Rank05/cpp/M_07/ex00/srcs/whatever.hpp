#pragma once
#include <iostream>

template <typename T>
void swap(T &x, T &y){
    T z;
    z = x;
    x = y;
    y = z;
}

template <typename T>
T min(T &x, T &y){
    if(x > y)
        return y;
    return x;
}

template <typename T>
T max(T &x, T &y){
    if(x > y)
        return x;
    return y;
}
