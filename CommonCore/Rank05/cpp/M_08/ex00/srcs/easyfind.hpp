#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &arr, int nbr){
    for(typename T::iterator i = arr.begin(); i != arr.end(); i++){
        if(*i == nbr)
            return i;
    }
    throw std::runtime_error("easyFind: Value not found.");
}

template <typename T>
typename T::const_iterator easyfind(const T &arr, int nbr){
    for(typename T::const_iterator i = arr.begin(); i != arr.end(); i++){
        if(*i == nbr)
            return i;
    }
    throw std::runtime_error("easyFind: Value not found.");
}

#endif