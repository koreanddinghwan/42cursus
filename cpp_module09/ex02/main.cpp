#include "./PmergeMe.hpp"
#include <exception>

int main(int ac, char **av)
{
	try {
		PmergeMe pm(ac, av, 32, 7);
		pm.print();
	} catch (std::exception &e) {
		return 1;
	}
	return 0;
}
