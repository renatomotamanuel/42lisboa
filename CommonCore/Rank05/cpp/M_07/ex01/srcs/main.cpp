#include "iter.hpp"

void printInt(int arr){
    std::cout << arr << " ";
}

void printStr(std::string arr){
    std::cout << arr << " ";
}

int main (void){
    int intArr[] = { 1, 2, 3, 4, 5};
    std::string strArr[] = {"a", "b", "c", "d", "e"};
    std::cout << "Printing Int Array:" << std::endl;
    ::iter(intArr, 5, printInt);
    std::cout << std::endl;
    std::cout << "Printing Str Array:" << std::endl;
    ::iter(strArr, 5, printStr);
    std::cout << std::endl;
    return 0;
}