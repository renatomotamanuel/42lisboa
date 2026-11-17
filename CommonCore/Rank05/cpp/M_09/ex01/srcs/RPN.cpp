#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN() {}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other){
        _stack = other._stack;
    }
	return *this;
}

static int isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

static int operation(long long fst, long long snd, long long &ret, char c){
	switch(c){
		case '+':{
			if((snd > 0 && fst > LLONG_MAX - snd) || (snd > 0 && fst < LLONG_MIN - snd))
				return std::cerr << "Error: overflow." << std::endl, 1;
			ret = fst + snd;
			return 0;
		}
		case '-':{
			if((snd > 0 && fst > LLONG_MAX + snd) || (snd > 0 && fst < LLONG_MIN + snd))
				return std::cerr << "Error: overflow." << std::endl, 1;
			ret = fst - snd;
			return 0;
		}
		case '*':{
			int ov = 0;
			if(fst > 0){
				if(snd > 0)
					ov = fst > LLONG_MAX / snd;
				else
					ov = snd < LLONG_MIN / fst;
			}
			else{
				if(snd > 0)
					ov = fst < LLONG_MIN / snd;
				else
					ov = (fst != 0 && snd < LLONG_MAX / fst);
			}
			if(ov)
				return std::cerr << "Error: overflow." << std::endl, 1;
			ret = fst * snd;
			return 0;
		}
		case '/':{
			if(!snd)
				return std::cerr << "Error: can not divide by 0." << std::endl, 1;
			if(fst == LLONG_MIN && snd == -1)
				return std::cerr << "Error: overflow." << std::endl, 1;
			ret = fst / snd;
			return 0;
		}
		default:{
				return std::cerr << "Error." << std::endl, 1;
		}
	}
}

std::string RPN::calc(std::string input){
	std::istringstream in(input);
	std::string token;
	long long fst;
	long long snd;
	long long ret;

	while(in >> token){
		if(token.length() == 1){
			if(std::isdigit(static_cast<unsigned char>(token[0])))
				_stack.push(token[0] - 48);
			else if(isOperator(token[0])){
				if(_stack.size() < 2)
					return std::cerr << "Error: bad input." << std::endl, "";
				snd = _stack.top();
				_stack.pop();
				fst = _stack.top();
				_stack.pop();
				if(operation(fst, snd, ret, token[0]))
					return "";
				_stack.push(ret);
			}
			else
				return std::cerr << "Error: bad input." << std::endl, "";
		}
		else
			return std::cerr << "Error: bad input." << std::endl, "";
	}
	if(_stack.size() != 1)
		return std::cerr << "Error: bad input." << std::endl, "";
	ret = _stack.top();
	std::ostringstream os;
	os << ret;
	return os.str();
}