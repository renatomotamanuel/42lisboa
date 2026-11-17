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

int floatParseSimple(float &value, std::string &val){
    char *end = NULL;

    value = static_cast<float>(strtod(val.c_str(), &end));
    if(end == val.c_str() || *end != 0)
        return 1;
    return 0;
}

int floatParse(float &value, std::string &val){
    char *end = NULL;
	int nbr;
	int dec;

	if(val.empty())
		return 1;
	for(size_t i = 0; i < val.size(); i++){
		if(val[i] == '-' && !i)
			continue;
		if(val[i] == '.')
			dec++;
		else if(isdigit(static_cast<unsigned char>(val[i])))
			nbr++;
		else
			return 1;
	}
	if(!nbr || dec > 1)
		return 1;
    value = static_cast<float>(strtod(val.c_str(), &end));
    if(end == val.c_str() || *end != 0)
        return 1;
    return 0;
}

std::map<std::string, float> mountDb(void){
    std::ifstream file("data.csv");
    std::map<std::string, float> db;
    std::string line;
    std::string val;
    std::string date;
    float value;

    if(!file.is_open())
        return std::cerr << "Error: could not open database." << std::endl, db;
    std::getline(file, line);
    while(std::getline(file, line)){
        value = 0;
        size_t pos = line.find(',');
        if(pos == std::string::npos)
            continue;
        date = line.substr(0, pos);
        val = line.substr(pos + 1);
        if(floatParseSimple(value, val))
            continue ;
        if(dateParse(date))
            continue;
        db[date] = value;
    }
    return db;
}

/* void printDb(std::map<std::string, float> db){
    std::map<std::string, float>::iterator it;

    for(it = db.begin(); it != db.end(); it++){
        std::cout << "date: " << it->first << "   " << "value: " << it->second << std::endl;
    }
} */

int inputParse(std::string &line, std::string &date, float &value){
    std::string val;
    std::string ret;
    size_t st;
    size_t pos;

    pos = line.find('|');
	if (pos == std::string::npos || line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return std::cerr << "Error: bad input => " << line << std::endl, 1;
	date = line.substr(0, 10);
	if (dateParse(date))
		return std::cerr << "Error: bad input => " << date << std::endl, 1;
	val = line.substr(pos + 1);
	st = val.find_first_not_of(" \t");
	if (st == std::string::npos)
		return std::cerr << "Error: bad input => " << line << std::endl, 1;
	ret = val.substr(st);
	if (floatParse(value, ret))
		return std::cerr << "Error: bad input => " << line << std::endl, 1;
	if (value < 0)
		return std::cerr << "Error: not a positive number." << std::endl, 1;
	else if (value > 1000)
		return std::cerr << "Error: too large a number." << std::endl, 1;
	return 0;
}


float convert(const std::map<std::string, float> &db, const std::string &date){
	std::map<std::string, float>::const_iterator it = db.upper_bound(date);

	if (it == db.begin())
		return -1;
	--it;
	return it->second;
}

int inputManage(std::map<std::string, float> db, std::ifstream &file){
    std::string line;
    std::string date;
    float value;
	float ret;

    if(!std::getline(file, line) || line != "date | value")
        return std::cerr << "Error: bad input => " << line << std::endl, 1;
    while(std::getline(file, line)){
        if(inputParse(line, date, value))
			continue;
        ret = convert(db, date);
		if (ret < 0){
			std::cerr << "Error: " << date << " not in the database" << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << (value * ret) << std::endl;
    }
	return 0;
}

int parse(char *input){
    std::ifstream file(input);
    std::map<std::string, float> db;

    if(!file.is_open())
        return std::cerr << "Error: could not open file." << std::endl, 1;
    db = mountDb();
    if(db.empty())
        return std::cerr << "Error: mounting database." << std::endl,1;
    return inputManage(db, file);
}