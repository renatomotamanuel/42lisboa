#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int ac, char **av){
	std::string line;
	int nbr;
	char *end;

	for(int i = 1; i < ac; i++){
		line = av[i];
		nbr = strtol(line.c_str(), &end, 10);
		_deq.push_back(nbr);
		_vec.push_back(nbr);
	}
	/* printDeq();
	std::cout << std::endl;
	printVec(); */
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other){
        _deq = other._deq;
        _vec = other._vec;
    }
	return *this;
}

void PmergeMe::mergeVec(std::vector<std::pair<int, int> > &pairs, size_t left, size_t right, size_t mid){
	std::vector<std::pair<int, int> > temp;
	size_t fst;
	size_t snd;

	temp.reserve(right - left + 1);
	fst = left;
	snd = mid + 1;
	while(fst <= mid && snd <= right){
		if(pairs[fst].second <= pairs[snd].second){
			temp.push_back(pairs[fst]);
			fst++;
		}
		else{
			temp.push_back(pairs[snd]);
			snd++;
		}
	}
	while(fst <= mid){
		temp.push_back(pairs[fst]);
		fst++;
	}
	while(snd <= right){
		temp.push_back(pairs[snd]);
		snd++;
	}
	for(size_t i = 0; i < temp.size(); ++i)
		pairs[left + i] = temp[i];
}


void PmergeMe::sortWinnersVec(std::vector<std::pair<int, int> > &pairs, size_t left, size_t right){
	size_t mid;

	if(left >= right)
		return ;
	mid = left + (right - left) / 2;
	sortWinnersVec(pairs, left, mid);
	sortWinnersVec(pairs, mid + 1, right);
	mergeVec(pairs, left, right, mid);
}

void printDeq(std::deque<int> deq){
	std::cout << "Deq: ";
	for(size_t i = 0; i <deq.size(); i++)
		std::cout << deq[i] << " ";
	std::cout << std::endl;
}

void printVec(std::vector<int> vec){
	std::cout << "Vec: ";
	for(size_t i = 0; i <vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void printVecLong(std::vector<size_t> vec){
	std::cout << "Vec: ";
	for(size_t i = 0; i <vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void printPairs(std::vector<std::pair<int, int> > pairs){
	for (size_t i = 0; i < pairs.size(); ++i) {
    std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
	}
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

int searchVec(std::vector<int>& vec, int value, size_t bound){
	if(vec.empty())
		return 0;
	if(bound >= vec.size())
		bound = vec.size() - 1;
	int l = 0;
	int r = static_cast<int>(bound);
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(vec[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

int PmergeMe::sortVec(void){
	std::vector<std::pair<int, int> > pairs;
	int fst;
	int snd;
	int offset;

	offset = -1;
	if(_vec.size() < 2)
		return 0;
	if(_vec.size() % 2 != 0)
		offset = _vec[_vec.size() - 1];
	for(size_t i = 0; (i + 1) < _vec.size(); i += 2){
		fst = _vec[i];
		snd = _vec[i + 1];
		if(fst > snd)
			pairs.push_back(std::make_pair(snd, fst));
		else
			pairs.push_back(std::make_pair(fst, snd));
	}
	sortWinnersVec(pairs, 0, pairs.size() - 1);
	_vec.clear();
	std::vector<size_t> order;
	std::vector<std::pair<int, int> > dups;
	_vec.push_back(pairs[0].first);
	_vec.push_back(pairs[0].second);
	for(size_t i = 1; i < pairs.size(); i++){
		_vec.push_back(pairs[i].second);
		dups.push_back(std::make_pair(pairs[i].first, pairs[i].second));
	}
	if(offset != -1)
		dups.push_back(std::make_pair(offset, -1));
	order = jacobVec(dups.size() - 1);
	for(size_t i = 0; i < order.size(); ++i){
		size_t j = order[i];
		int val = dups[j].first;
		int valWin = dups[j].second;
		size_t bound = _vec.size() - 1;
		if(valWin != -1){
			for(size_t k = 0; k < _vec.size(); ++k){
				if(_vec[k] == valWin){
					bound = k;
					break ;
				}
			}
		}
		int pos = searchVec(_vec, val, bound);
		_vec.insert(_vec.begin() + pos, val);
	}
	bool is_sorted = (std::adjacent_find(_vec.begin(), _vec.end(), std::greater<int>()) == _vec.end());

    if (is_sorted) {
        std::cout << "Vector is sorted\n";
    } else {
        std::cout << "Vector is not sorted\n";
    }
	return 0;
}

int isNbr(std::string line){
	if(line.empty())
		return std::cerr << "Error: arguments can not be empty" << std::endl, 1;
	for(size_t i = 0; i < line.length(); i++){
		if(!isdigit(static_cast<unsigned char>(line[i])))
			return 1;
	}
	return 0;
}

int isValid(std::string line){
	char *end;
	long nbr = strtol(line.c_str(), &end, 10);
	if(*end != '\0' || nbr < 0 || nbr > INT_MAX)
		return 1;
	return 0;
}

int checkDup(std::deque<int> deq){
	std::deque<int> dup(deq);
	int hasDup;

	std::sort(dup.begin(), dup.end());
	hasDup = std::adjacent_find(dup.begin(), dup.end()) != dup.end();
	return hasDup;
}

int parse(int ac, char **av){
	std::string line;
	std::deque<int> deq;
	int nbr;
	char *end;

	for(int i = 1; i < ac; i++){
		line = av[i];
		if(isNbr(line))
			return 1;
		else if(isValid(line))
			return 1;
		nbr = strtol(line.c_str(), &end, 10);
		deq.push_back(nbr);
	}
	if(checkDup(deq))
		return std::cerr << "Error: duplicates are not allowed." << std::endl, 1;
	return 0;
}