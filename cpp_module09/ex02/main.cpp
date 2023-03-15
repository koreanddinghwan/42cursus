#include "./PmergeMe.hpp"
#include <exception>

int main(int ac, char **av)
{

	try {
	PmergeMe pm(ac, av, 32);
	pm.sortAndPrintElapse();
	} catch (std::exception &e) {
		return 1;
	}
	return 0;
}
