#include <cctype>
#include <climits>
#include <exception>
#include <list>
#include <deque>
#include <iostream>
#include <ctime>
#include <deque>
#include <iomanip>

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

class PmergeMe
{
private:
	std::list<int>	originalList;
	std::list<int>	list;
	std::deque<int>	originalQueue;
	std::deque<int>	deque;
	int				counts;
	unsigned int	thresHold;
	int				printMax;

public:
	PmergeMe(int ac, char **av, int thresHold, int printMax) throw(std::exception);
	~PmergeMe(); 

private:
	PmergeMe(PmergeMe &o); 
	PmergeMe& operator=(PmergeMe &o);

	//merge-insert sort => 병합정렬을 통해 작은 부분으로 배열을 나눠가다가 일정 길이에 도달하면 삽입정렬을 수행.
	void merge_insertion_sort_list(std::list<int> &input_list);

	void merge_list(std::list<int> &input_list);
	void insertion_list(std::list<int> &input_list);

	void merge_insertion_sort_deque(std::deque<int> &queue);
	void merge_deque(std::deque<int> &input_deque);
	void insertion_deque(std::deque<int> &input_deque);

public:
	void print(); 
private:
	void printList(std::list<int> l, const char *msg);
	void printDeque(std::deque<int> l, const char *msg);
	void printMessage(double time, const char *type);
};

#endif
