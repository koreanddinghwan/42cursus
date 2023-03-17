#include "./PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av, int thresHold, int printMax) throw(std::exception)
{
	if (ac < 2)
	{
		std::cout<<"No Argument"<<std::endl;
		throw std::exception();
	}
	this->thresHold = thresHold;
	this->printMax = printMax;

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
PmergeMe::PmergeMe(PmergeMe &o) { static_cast<void>(o);}

PmergeMe& PmergeMe::operator=(PmergeMe &o) { static_cast<void>(o); return *this;}


void PmergeMe::print() {
	clock_t start;
	clock_t end;
	double	els;

	std::cout <<"\033[5;31m [std::list] \033[0m"<< std::endl;
	printList(this->originalList, "Before:  \033[35m");

	//START TIME
	start = clock();
	this->list.assign(originalList.begin(),originalList.end());
	merge_insertion_sort_list(this->list);
	//END TIME
	end = clock();
	els = static_cast<double>(end - start);

	printList(this->list, "After:   \033[35m");
	printMessage(els, "list");

	std::cout<<std::endl;

	std::cout <<"\033[5;31m [std::deque] \033[0m"<< std::endl;
	printDeque(this->originalQueue, "Before:  \033[35m");

	//START TIME
	start = clock();
	this->deque.assign(originalQueue.begin(), originalQueue.end());
	merge_insertion_sort_deque(this->deque);
	//END TIME
	end = clock();
	els = static_cast<double>(end - start);

	printDeque(this->deque, "After:   \033[35m");
	printMessage(els, "deque");
}


void PmergeMe::printList(std::list<int> l, const char *msg)
{
	int count = 0;

	std::cout<<msg;
	for (std::list<int>::iterator it = l.begin(); it != l.end() && count < this->printMax; it++, count++){
		std::cout<<*it<<" ";
	}
	if (count == this->printMax)
		std::cout<<"[...]\033[0m"<<std::endl;
	else
		std::cout<<std::endl;
}

void PmergeMe::printDeque(std::deque<int> q, const char *msg)
{
	int count = 0;

	std::cout<<msg;
	for (std::deque<int>::iterator it = q.begin(); it != q.end() && count < this->printMax; it++, count++){
		std::cout<<*it<<" ";
	}
	if (count == this->printMax)
		std::cout<<"[...]\033[0m"<<std::endl;
	else
		std::cout<<std::endl;
}

void PmergeMe::printMessage(double time, const char *type) {
	std::cout<<"\033[33m Time to process a range of \033[35m " << this->originalList.size() << " \033[33m elements with std::["<<type<<"] :\033[35m";
	std::cout<<std::setprecision(7)<<time<<"us \033[0m"<<std::endl;
}
