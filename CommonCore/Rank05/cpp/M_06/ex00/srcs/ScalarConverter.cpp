#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}

ScalarConverter::~ScalarConverter() { 
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	return *this;
}

static int detect(std::string str){
    int x = 0;
    if(!str[0])
        return 0;
    if(!str[1]){
        if(str[0] && (str[0] >= 48 && str[0] <= 57))
            return 1;
        else
            return 0;
    }
    if(str == "nanf" || str == "inff" || str == "-inff" || str == "+inff")
        return 2;
    else if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
        return 3;
    int i;
    for(i = 0; str[i]; i++){
        if(i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;;
        if(str[i] == '.'){
            if(x == 2)
                return 3;
            x = 2;
        }
        else if ((str[i] < 48 && str[i] > 57) && str[i + 1])
            return 3;
    }
    if(x == 2){
        if(str[i -1] == 'f')
            return 2;
        return 3;
    }
    return 1;
}

static void printChar(double ret){
    std::cout << "char: ";
    char c;
    if (ret < 0 || ret > 127 || std::isnan(ret) || std::isinf(ret))
        std::cout << "impossible";
    else if(ret < 32 || ret > 126)
        std::cout << "Non Displayable";
    else{
        c = static_cast<char>(ret);
        std::cout << "'" << c << "'";
    }
    std::cout << std::endl;
}

static void printInt(double ret){
    std::cout << "int: ";
    int c;
    if (ret < INT_MIN || ret > INT_MAX || std::isnan(ret) || std::isinf(ret))
        std::cout << "impossible";
    else{
        c = static_cast<int>(ret);
        std::cout << c;
    }
    std::cout << std::endl;
}

static void printFloat(double ret){
    std::cout << "float: ";
    float c;
    if (std::isnan(ret))
        std::cout << "nanf";
    else if(std::isinf(ret)){
        if(ret < 0)
            std::cout << "-inff";
        else
            std::cout << "+inff";
    }
    else{
        c = static_cast<float>(ret);
        std::cout << std::fixed << std::setprecision(1) << c << 'f';
    }
    std::cout << std::endl;
}

static void printDouble(double ret){
    std::cout << "double: ";
    if (std::isnan(ret))
        std::cout << "nan";
    else if(std::isinf(ret)){
        if(ret < 0)
            std::cout << "-inf";
        else
            std::cout << "+inf";
    }
    else{
        std::cout << std::fixed << std::setprecision(1) << ret;
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string f){
    int x = detect(f);
    double ret;
    switch(x){
        case 0:{
            if(!f[0])
                ret = 0;
            else{
                char c = f[0];
                ret = c;
            }
            break;
        }
        case 1:{
            int i = atoi(f.c_str());
            ret = i;
            break;
        }
        case 2:{
            float d = static_cast<float>(atof(f.c_str()));
            ret = d;
            break;
        }  
        case 3:{
            ret = atof(f.c_str());
            break;
        }
    }
    printChar(ret);
    printInt(ret);
    printFloat(ret);
    printDouble(ret);
}