#include "./RPN.cpp"
#include <exception>

int main(int ac, char *av[])
{
	try {
		RPN rpn(ac, av);
		rpn.printResult();
	} catch (std::exception &e) {
		return 1;
	}	
	return 0;
}
