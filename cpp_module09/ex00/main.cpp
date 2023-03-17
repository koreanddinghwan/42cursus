//Todo cpp, hpp분리
#include "UserDatabase.hpp"
#include "BitcoinExchange.hpp"
#include <exception>

int main(int ac, char *av[]) 
{
	UserDatabase	*userDb;
	Exchanger		*exchangerDb;

	try {
		userDb = new UserDatabase(ac, av);
	} catch (std::exception &e) {
		return 1;
	}


	try {
		exchangerDb = new Exchanger("./data.csv");
	} catch (std::exception &e) {
		return 1;
	}

	while (1) 
	{
		DateAndValue *v;

		try {
			//get 1 value from user Database(input.txt)
			v = userDb->get();
			if (v == NULL){ //file end
				delete v;
				break;
			}
		} catch (std::exception &e) {
			continue;//error in file
		}
		exchangerDb->printPriceByDate(v);
		delete v;
	}
	return 0; 
}
