#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>


class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:
	Contact(std::string _firstName = "", 
		std::string _lastName = "", std::string _nickName = "", 
		std::string _phoneNumber = "", std::string _darkestSecret = "");
	~Contact();
	std::string getFname() const;
	std::string getLname() const;
	std::string getNname() const;
	std::string getNumber() const;
	Contact& operator=(const Contact& other);
	void displayContact() const;
};

#endif