#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <cctype>

int parse(char *input);
std::map<std::string, float> mountDb(std::ifstream &file);
int inputManage(std::map<std::string, float> db, std::ifstream &file);
float convert(const std::map<std::string, float> &db, const std::string &date);
int inputParse(std::string &line, std::string &date, float &value);
std::map<std::string, float> mountDb(void);
int floatParse(float &value, std::string &val);
int dateParse(const std::string& date);
//void printDb(std::map<std::string, float> db);
#endif