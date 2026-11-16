#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <exception>
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

public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	int sortVec(void);
	void sortWinnersVec(std::vector<std::pair<int, int> > &pairs, size_t left, size_t right);
	void mergeVec(std::vector<std::pair<int, int> > &pairs, size_t left, size_t right, size_t mid);
};

int parse(int ac, char **av);

#endif
