#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>class Array{
private:
    T *_arr;
public:
    Array(){
        _arr = new T;
        std::cout << "Default" << std::endl;
    }
    Array(unsigned int n){
        _arr = new T;
        for(unsigned int i = 0; i < n; i++)
            _arr[i] = 0;
        std::cout << "UInt n" << std::endl;
    }
    void printArr(){
        for(int i = 0; _arr[i]; i++)
            std::cout << _arr[i] << " ";
        std::cout << std::endl;
    }
};


#endif