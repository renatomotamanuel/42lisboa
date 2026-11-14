#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cctype>
# include <cstdlib>
# include <fstream>
# include <map>

int parse(char *input);
std::map<std::string, float> mountDb(std::ifstream &file);

#endif