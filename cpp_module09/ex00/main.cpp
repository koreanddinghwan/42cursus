//Todo cpp, hpp분리
#include "./BitcoinExchange.cpp"
#include "./UserDatabase.cpp"
#include <exception>

int main(int ac, char *av[]) 
{
	UserDatabase	*userDb;
	Exchanger		*exchanger;

	try {
		userDb = new UserDatabase(ac, av);
	} catch (std::exception &e) {
		return 0;
	}


	try {
		exchanger = new Exchanger("./data.csv");
	} catch (std::exception &e) {
		delete userDb;
		delete exchanger;
		return 0;
	}

	while (1) 
	{
		DateAndValue *v;

		try {
			v = userDb->get();
			if (v == NULL){ //file end
				delete v;
				break;
			}
		} catch (std::exception &e) {
			continue;//error in file
		}

		std::cout<<static_cast<int>(v->getYear())<<"-"<<static_cast<int>(v->getMonth())<<"-"<<static_cast<int>(v->getDay())<<" => "<<v->getValue()<<" = ";
		while (1) {
			float p = exchanger->getPrice(v->getYear(), v->getMonth(), v->getDay());
			if (p == -1)
			{
				v->setRewindOneDay();
				continue;
			}
			else {
				std::cout<<p * v->getValue()<<std::endl;
				break;
			}
		}
		delete v;
	}

	delete userDb;
	delete exchanger;
	while (1);
	return 0; 
}
