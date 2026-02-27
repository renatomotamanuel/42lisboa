#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
	std::string getName();
	int getGrade();
	void incrementGrade(void);
	void decrementGrade(void);
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& f);

#endif