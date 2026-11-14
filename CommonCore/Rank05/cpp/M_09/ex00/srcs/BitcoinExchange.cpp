#include "BitcoinExchange.hpp"

int dateParse(const std::string& date){
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return 1;
	for (int i = 0; i < 10; i++){
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(static_cast<unsigned char>(date[i])))
			return 1;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || day < 1 || month > 12)
		return 1;
	switch (month)
	{
		case 1:{
            if (day > 31)
				return 1;
			break;
        }
		case 2: {
			bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			int maxDay;
			if (isLeap)
				maxDay = 29;
			else
				maxDay = 28;
			if (day > maxDay)
				return 1;
			break;
		}
        case 3:{
            if (day > 31)
				return 1;
			break;
        }
        case 4:{
            if (day > 30)
				return 1;
			break;
        }
        case 5:{
            if (day > 31)
				return 1;
			break;
        }
        case 6:{
            if (day > 30)
				return 1;
			break;
        }
        case 7:{
            if (day > 31)
				return 1;
			break;
        }
        case 8:{
            if (day > 31)
				return 1;
			break;
        }
        case 9:{
            if (day > 30)
				return 1;
			break;
        }
        case 10:{
            if (day > 31)
				return 1;
			break;
        }
        case 11:{
            if (day > 30)
				return 1;
			break;
        }
        case 12:{
            if (day > 31)
				return 1;
			break;
        }
	}
	return 0;
}


int floatParse(float &value, std::string &val){
    char *end = NULL;

    value = static_cast<float>(strtod(val.c_str(), &end));
    if(end == val.c_str() || *end != 0)
        return 1;
    return 0;
}

std::map<std::string, float> mountDb(std::ifstream &file){
    std::map<std::string, float> db;
    std::string line;
    std::string val;
    std::string date;
    float value;

    std::getline(file, line);
    while(std::getline(file, line)){
        value = 0;
        size_t pos = line.find(',');
        if(pos == std::string::npos)
            continue;
        date = line.substr(0, pos);
        val = line.substr(pos + 1);
        if(floatParse(value, val))
            continue ;
        if(dateParse(date))
            continue;
        db[date] = value;
    }
    return db;
}

int parse(char *input){
    std::ifstream file(input);
    std::map<std::string, float> db;

    if(!file.is_open())
        return std::cout << "Error: Could'nt open file." << std::endl, 1;
    db = mountDb(file);
    if(db.empty())
        return 1;
    return 0;
}