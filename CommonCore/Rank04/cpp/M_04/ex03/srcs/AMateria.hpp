#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"


class AMateria{
protected:
	std::string _type;
public:
	AMateria(std::string const & type);
	~AMateria();
	std::string const & getType() const;
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const = 0;
};

#endif