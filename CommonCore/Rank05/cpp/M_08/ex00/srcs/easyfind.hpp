#pragma once

#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &arr, int nbr){
    for(typename T::iterator i = arr.begin(); i != arr.end(); i++){
        if(*i == nbr)
            return i;
    }
    throw std::runtime_error("easyFind: Value not found.");
}
