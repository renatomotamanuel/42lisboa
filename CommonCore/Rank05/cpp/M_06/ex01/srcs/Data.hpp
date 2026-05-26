#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

class Data {
private:
    int _nbr;
    std::string _str;
    unsigned int _unbr;
    char _c;
public:
    Data();
    Data(int nbr, std::string str, unsigned int unbr, char c);
    ~Data();
    Data(const Data &other);
    Data &operator=(const Data &other);
    int getInt() const;
    std::string getStr() const;
    unsigned int getUnsignedInt() const;
    char getChar() const;
};

std::ostream &operator<<(std::ostream &os, Data &f);

#endif