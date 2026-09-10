#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat {
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int increment);
	void decrementGrade(int decrement);
	class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
	class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
	void signForm(AForm& f);
	void executeForm(AForm const & form);
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& f);

#endif