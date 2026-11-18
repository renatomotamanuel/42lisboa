#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int ac, char **av){
	std::string line;
	int nbr;
	char *end;
	clock_t st = std::clock();
	clock_t ender;

	_vecTime = 0;
	_deqTime = 0;
	for(int i = 1; i < ac; i++){
		line = av[i];
		nbr = strtol(line.c_str(), &end, 10);
		_vec.push_back(nbr);
	}
	ender = std::clock();
	_vecConstruct = double(ender - st) / CLOCKS_PER_SEC * 1000000.0;
	st = std::clock();
	for(int i = 1; i < ac; i++){
		line = av[i];
		nbr = strtol(line.c_str(), &end, 10);
		_deq.push_back(nbr);
	}
	ender = std::clock();
	_deqConstruct = double(ender - st) / CLOCKS_PER_SEC * 1000000.0;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if(this != &other){
        _deq = other._deq;
        _vec = other._vec;
		_deqTime = other._deqTime;
        _vecTime = other._vecTime;
		_deqConstruct = other._deqConstruct;
        _vecConstruct = other._vecConstruct;
    }
	return *this;
}

void PmergeMe::printVec(void){
	for(size_t i = 0; i <_vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printTimeTable(void){
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << _deqTime << " us" << std::endl;
}

int searchVec(std::vector<std::pair<int, int> > &vec, int value, size_t bound){
	if(vec.empty())
		return 0;
	int l = 0;
	int r = static_cast<int>(bound);
	while(l < r){
		int mid = l + (r - l) / 2;
		if(vec[mid].first < value)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

std::vector<size_t> jacobVec(size_t len){
	std::vector<size_t> order;
	size_t prev;
	size_t curr;
	size_t st;
	size_t end;
	size_t next;

	if(len == 0)
		return order;
	std::vector<bool> used(len, false);
	prev = 1;
	curr = 3;
	while(curr <= len + 1){
		st = curr;
		end = prev + 1;
		for(size_t i = st; i >= end; --i){
			size_t j = i - 2;
			if(j < len && !used[j]){
				order.push_back(j);
				used[j] = true;
			}
			if(i == end)
				break;
		}
		next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	for(size_t i = len; i > 0; --i){
		size_t j = i - 1;
		if(!used[j]){
			order.push_back(j);
			used[j] = true;
		}
	}
	return order;
}

void fordJohnsonVec(std::vector<std::pair<int, int> > &vec){
	std::vector<std::pair<int, int> > winners;
	std::vector<std::pair<int, int> > losers;
	std::vector<std::pair<int, int> > sort;

	if(vec.size() < 2)
		return ;
	size_t n = vec.size();
	size_t mid = vec.size() / 2;
	for(size_t i = 0; i < mid; i++){
		std::pair<int,int> l = vec[2 * i];
		std::pair<int,int> w = vec[2 * i + 1];
		if(l.first > w.first)
			std::swap(l, w);
		losers.push_back(l);
		winners.push_back(w);
		sort.push_back(std::make_pair(w.first, static_cast<int>(i)));
	}
	fordJohnsonVec(sort);
	std::vector<std::pair<int, int> > main;
	main.push_back(losers[sort[0].second]);
	for(size_t i = 0; i < mid; i++)
		main.push_back(winners[sort[i].second]);
	std::vector<size_t> order = jacobVec(mid - 1 + (n % 2));
	for(size_t i = 0; i < order.size(); i++){
		size_t idx = order[i];
		std::pair<int, int>val;
		size_t end = main.size();
		if(idx < mid - 1){
			val = losers[sort[idx + 1].second];
			int id = winners[sort[idx + 1].second].second;
			end = 0;
			while(main[end].second != id)
				end++;
		}
		else
			val = vec[n -1];
		main.insert(main.begin() + searchVec(main, val.first, end), val);
	}
	vec = main;
}

int PmergeMe::sortVec(void){
	clock_t st = std::clock();
	clock_t end;
	std::vector<std::pair<int, int> > vec;

	if(_vec.size() < 2){
		end = std::clock();
		_vecTime = double(end - st) / CLOCKS_PER_SEC * 1000000.0;
		_vecTime += _vecConstruct;
		return 0;
	}
	for(size_t i = 0; i < _vec.size(); i++)
		vec.push_back(std::make_pair(_vec[i], static_cast<int>(i)));
	fordJohnsonVec(vec);
	for(size_t i = 0; i < vec.size(); i++)
		_vec[i] = vec[i].first;
	end = std::clock();
	_vecTime = double(end - st) / CLOCKS_PER_SEC * 1000000.0;
	_vecTime += _vecConstruct;
	return 0;
}

int isNbr(std::string line){
	if(line.empty())
		return std::cerr << "Error: arguments can not be empty" << std::endl, 1;
	for(size_t i = 0; i < line.length(); i++){
		if(!isdigit(static_cast<unsigned char>(line[i])))
			return std::cerr << "Error: arguments must be numeric." << std::endl, 1;
	}
	return 0;
}

int isValid(std::string line){
	char *end;
	long nbr = strtol(line.c_str(), &end, 10);
	if(*end != '\0' || nbr < 0 || nbr > INT_MAX)
		return std::cerr << "Error: arguments must be int." << std::endl, 1;
	return 0;
}

int parse(int ac, char **av){
	std::string line;
	int nbr;
	char *end;

	for(int i = 1; i < ac; i++){
		line = av[i];
		if(isNbr(line))
			return 1;
		else if(isValid(line))
			return 1;
	}
	return 0;
}

int searchDeq(std::deque<std::pair<int, int> > &deq, int value, size_t bound){
	if(deq.empty())
		return 0;
	int l = 0;
	int r = static_cast<int>(bound);
	while(l < r){
		int mid = l + (r - l) / 2;
		if(deq[mid].first < value)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

std::deque<size_t> jacobDeq(size_t len){
	std::deque<size_t> order;
	size_t prev;
	size_t curr;
	size_t st;
	size_t end;
	size_t next;

	if(len == 0)
		return order;
	std::deque<bool> used(len, false);
	prev = 1;
	curr = 3;
	while(curr <= len + 1){
		st = curr;
		end = prev + 1;
		for(size_t i = st; i >= end; --i){
			size_t j = i - 2;
			if(j < len && !used[j]){
				order.push_back(j);
				used[j] = true;
			}
			if(i == end)
				break;
		}
		next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	for(size_t i = len; i > 0; --i){
		size_t j = i - 1;
		if(!used[j]){
			order.push_back(j);
			used[j] = true;
		}
	}
	return order;
}

void fordJohnsonDeq(std::deque<std::pair<int, int> > &deq){
	std::deque<std::pair<int, int> > winners;
	std::deque<std::pair<int, int> > losers;
	std::deque<std::pair<int, int> > sort;

	if(deq.size() < 2)
		return ;
	size_t n = deq.size();
	size_t mid = deq.size() / 2;
	for(size_t i = 0; i < mid; i++){
		std::pair<int,int> l = deq[2 * i];
		std::pair<int,int> w = deq[2 * i + 1];
		if(l.first > w.first)
			std::swap(l, w);
		losers.push_back(l);
		winners.push_back(w);
		sort.push_back(std::make_pair(w.first, static_cast<int>(i)));
	}
	fordJohnsonDeq(sort);
	std::deque<std::pair<int, int> > main;
	main.push_back(losers[sort[0].second]);
	for(size_t i = 0; i < mid; i++)
		main.push_back(winners[sort[i].second]);
	std::deque<size_t> order = jacobDeq(mid - 1 + (n % 2));
	for(size_t i = 0; i < order.size(); i++){
		size_t idx = order[i];
		std::pair<int, int>val;
		size_t end = main.size();
		if(idx < mid - 1){
			val = losers[sort[idx + 1].second];
			int id = winners[sort[idx + 1].second].second;
			end = 0;
			while(main[end].second != id)
				end++;
		}
		else
			val = deq[n -1];
		main.insert(main.begin() + searchDeq(main, val.first, end), val);
	}
	deq = main;
}

int PmergeMe::sortDeq(void){
	clock_t st = std::clock();
	clock_t end;
	std::deque<std::pair<int, int> > deq;

	if(_deq.size() < 2){
		end = std::clock();
		_deqTime = double(end - st) / CLOCKS_PER_SEC * 1000000.0;
		_deqTime += _deqConstruct;
		return 0;
	}
	for(size_t i = 0; i < _deq.size(); i++)
		deq.push_back(std::make_pair(_deq[i], static_cast<int>(i)));
	fordJohnsonDeq(deq);
	for(size_t i = 0; i < deq.size(); i++)
		_deq[i] = deq[i].first;
	end = std::clock();
	_deqTime = double(end - st) / CLOCKS_PER_SEC * 1000000.0;
	_deqTime += _deqConstruct;
	return 0;
}