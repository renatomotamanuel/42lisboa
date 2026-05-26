#include "Serializer.hpp"

int main(){
    Data temp(10, "ola", 7, 'a');
    Data *temp2;
    uintptr_t ptr;

    std::cout << temp << std::endl;
    ptr = Serializer::serialize(&temp);
    std::cout << ptr << std::endl;
    temp2 = Serializer::deserialize(ptr);
    std::cout << *temp2 << std::endl;
}