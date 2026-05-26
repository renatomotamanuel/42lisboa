#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t temp = reinterpret_cast<uintptr_t>(ptr);
    return temp;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *temp = reinterpret_cast<Data *>(raw);
    return temp;
}
