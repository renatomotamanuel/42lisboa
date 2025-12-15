#include <iostream>
#include <fstream>
#include <string>

int	main (int ac, char **av)
{
	int replace;
	int j;
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
	while(std::getline(infile, line))
	{
		for (int i = 0; line[i]; i++)
		{
			replace = 0;
			if(line[i] == s1[0])
			{
				for (j = 0; line[i + j] && s1[j]; j++)
				{
					if(line [i + j] != s1[j])
					{
						replace = 1;
						break ;
					}
				}
				if(!replace)
				{
					i += j;
					for(int k = 0; s2[k]; k++)
						outfile << s2[k];
				}
			}
			outfile << line[i];
		}
		outfile << std::endl;
	}
	return 0;
}