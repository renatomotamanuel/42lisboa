#include <iostream>
#include <fstream>
#include <string>

int	main (int ac, char **av)
{
	if (ac !=4)
		return std::cout << "Program must take 3 args, filename, s1 and s2." << std::endl, 1;
	std::string s1 = std::string (av[2]);
	std::string s2 = std::string (av[3]);
	if (s1.empty())
   		return std::cout << "Error: s1 cannot be empty." << std::endl, 1;
	std::string filename = std::string(av[1]);
	std::ifstream infile(filename.c_str());
	if(!infile.is_open())
		return std::cout << "Error. Could not open the file." << std::endl, 1;
	filename += ".replace";
	std::ofstream outfile (filename.c_str());
	if(!outfile.is_open())
		return std::cout << "Error. Could not create the file." << std::endl, 1;
	std::string line;
	while(std::getline(infile, line)){
		size_t pos = 0;
		size_t old_pos = 0;
		while(1){
			pos = line.find(s1.c_str(), old_pos, s1.length());
			if(pos == std::string::npos){
				outfile << line.substr(old_pos);
				break ;
			}
			outfile << line.substr(old_pos, pos - old_pos) << s2;
			old_pos = pos + s1.length();
		}
		outfile << std::endl;
	}
	return 0;
}