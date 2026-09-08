#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{
private:
    std::string _target;
	int executeAction(const Bureaucrat &f) const;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm(std::string target);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
};

#endif