#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
private:
	Brain *_think;
public:
	Dog();
	~Dog();
};


#endif