#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	~Animal();
	Animal(const Animal &other);
    Animal &operator=(const Animal &other);
	std::string getType() const;
	int	makeSound() const;
};


#endif