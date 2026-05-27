#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){

}

void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p){
    try{
		dynamic_cast<A &>(p);
        std::cout << "A2" << std::endl;
        return ;
	}
	catch (std::exception & e){
	}
    try{
		dynamic_cast<B &>(p);
        std::cout << "B2" << std::endl;
        return ;
	}
	catch (std::exception & e){
	}
    try{
		dynamic_cast<C &>(p);
        std::cout << "C2" << std::endl;
        return ;
	}
	catch (std::exception & e){
	}
    std::cout << "Unknown" << std::endl;
}

Base * generate(void){
    int x = rand() % 3;
    switch (x){
        case 0:{
            std::cout << "Gen A" << std::endl;
            return new A();
        } 
        case 1:{
            std::cout << "Gen B" << std::endl;
            return new B();
        } 
        default:{
            std::cout << "Gen C" << std::endl;
            return new C();
        }
    }
    return NULL;
}