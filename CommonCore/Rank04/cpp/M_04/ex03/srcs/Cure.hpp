#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(std::string type);
	~Cure();
};

#endif