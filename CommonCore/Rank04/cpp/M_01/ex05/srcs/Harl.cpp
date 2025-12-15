#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {
	std::cout << "Harl has been DESTROYED." << std::endl;
}

void Harl::complain( std::string level ){
	std::string comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::* _Commentptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i){
		if (level == comments[i]){
			(this->*_Commentptr[i])();
			return ;
		}
	}
	std::cout << "Harl has no complains. Your bacon delivery was exceptional." << std::endl;
	return ;
}

void Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

