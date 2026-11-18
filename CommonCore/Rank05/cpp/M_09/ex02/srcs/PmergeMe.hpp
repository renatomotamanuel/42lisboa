#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <cstdlib>
# include <cctype>
# include <ctime>
# include <algorithm>
# include <deque>
# include <vector>

class PmergeMe{
private:
	std::deque<int> _deq;
	std::vector<int> _vec;
	double _vecTime;
	double _deqTime;
	double _vecConstruct;
	double _deqConstruct;
public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	int sortVec(void);
	int sortDeq(void);
	void printVec(void);
	void printTimeTable(void);
};

int parse(int ac, char **av);

#endif
