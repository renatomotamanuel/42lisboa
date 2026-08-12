#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _max(0){}

template <typename T>
Array<T>::Array(unsigned int n){
    _arr = new T[n];
    _max = n;
}
template <typename T>
Array<T>::~Array(){
    delete[] _arr;
}

template <typename T>
Array<T>::Array(const Array &other){
    _arr = new T[other.size()];
    _max = other.size();
    for(int i = 0; i < other.size(); i++)
        _arr[i] = other.getVal(i);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
    if(this != &other){
        delete[] _arr;
       _max = other.size();
       _arr = new T[_max];
       for(int i = 0; i < other.size(); i++)
            _arr[i] = other.getVal(i);
    }
	return *this;
}

template <typename T>
T &Array<T>::operator[](int pos){
    if(pos < 0 || pos >= _max)
        throw std::runtime_error("Array:Position out of bounds.");
    else
        return _arr[pos];
}
template <typename T>
int Array<T>::size() const{
    return _max;
}
template <typename T>
T Array<T>::getVal(int i) const{
    return _arr[i];
}