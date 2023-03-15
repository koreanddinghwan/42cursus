#include "./PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av, int thresHold) throw(std::exception)
{
	if (ac < 2)
	{
		std::cout<<"No Argument"<<std::endl;
		throw std::exception();
	}
	this->thresHold = thresHold;

	int i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cout<<"Error"<<std::endl;
				throw std::exception();
			}
			j++;
		}
		long long t = atol(av[i]);
		if (t <= INT_MAX || t > 0)
		{
			this->originalList.push_back(static_cast<int>(t));
			this->originalQueue.push_back(static_cast<int>(t));
		}
		else 
		{
			std::cout<<"Invalid Arguments"<<std::endl;
			throw std::exception();
		}
		i++;
	}
	this->counts = ac - 1;
}

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &o) {}


PmergeMe& PmergeMe::operator=(PmergeMe &o) {return *this;}

void PmergeMe::sortAndPrintElapse() {
	clock_t start;
	clock_t end;
	double	q_els;
	double	l_els;

	start = clock();
	this->list = originalList;
	merge_insertion_sort_list(this->list);
	end = clock();
	l_els = static_cast<double>(end - start);

	start = clock();
	this->deque = originalQueue;
	merge_insertion_sort_deque(this->deque);
	end = clock();
	q_els = static_cast<double>(end - start);

	printBeforeAfter();
	printMessage(l_els, "list");
	printMessage(q_els, "deque");
}

void PmergeMe::printBeforeAfter() {
	int count = 0;

	std::cout<<"Before:  ";
	for (std::list<int>::iterator it = this->originalList.begin(); it != this->originalList.end(); it++, count++){
		std::cout<<*it<<" ";
		if (count == 7)
		{
			std::cout<<"[....]"<<std::endl;
			break;
		}
	}

	count = 0;
	std::cout<<"After:   ";
	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++, count++){
		std::cout<<*it<<" ";
		if (count == 7)
		{
			std::cout<<"[....]"<<std::endl;
			break;
		}
	}
}

void PmergeMe::printMessage(double time, const char *type) {
	std::cout<<"Time to process a range of 3000 elements with std::["<<type<<"] :";
	std::cout<<std::setprecision(8)<<time / 100000<<"us"<<std::endl;
	}
