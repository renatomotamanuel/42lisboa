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
	virtual ~Animal();
	std::string getType() const;
	Animal(const Animal &other);
    Animal &operator=(const Animal &other);
	virtual int	makeSound() const = 0;
};


#endif