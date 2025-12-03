#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string number;
public:
	Contact(std::string first_name = "", std::string last_name = "", std::string number = "");
	~Contact();
	Contact& operator=(const Contact& other);
	std::string getName() const;
	std::string getNumber() const;
	void displayContact() const;
};

#endif