#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    /* {
        numbers[0] = 5;
        Array<int> tmp = numbers;
        tmp[0] = 7;
        Array<int> test(tmp);
        tmp[0] = 5;
        numbers[0] = 10;
        std::cout << "numbers " << numbers[0] << std::endl;
        std::cout << "tmp " << tmp[0] << std::endl;
        std::cout << "test " << test[0] << std::endl;
    } */

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "size is " << numbers.size() << std::endl;
    delete [] mirror;//
    return 0;
}