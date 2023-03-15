#include <algorithm>
#include <cstdio>
#include <exception>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include "./BitcoinExchange.cpp"
#include "./DateAndValue.cpp"

const char *fileError = "Error: could not open file.";

class UserDatabase {
	private:
		std::ifstream file;

	public:
		UserDatabase(int ac, char *av[]) {
			std::string line;
			if (ac < 2)
				std::cout<<fileError<<std::endl;
			file.open(av[1]);
			if (file.fail())
				std::cout<<fileError<<std::endl;
			std::getline(file, line);
		}
		~UserDatabase() {}


	private:
		UserDatabase(UserDatabase &o) {}
		UserDatabase& operator=(UserDatabase &o) {return *this;}

	public:
		DateAndValue* get(void) throw (std::exception) {
			std::string		line;
			DateAndValue*	rtn = new DateAndValue();
			long long y,m,d = 0;
			double v = 0;
			
			if (!std::getline(file, line))
			{
				delete rtn;
				return 0;
			}
			std::cout<<line<<std::endl;
			sscanf(line.c_str(), "%lld-%lld-%lld | %lf", &y,&m,&d,&v);
			try {
				rtn->setYear(y);
				rtn->setMonth(m);
				rtn->setDay(d);
				rtn->setValue(v);
			} catch (std::exception &e) {
				throw e;
			}
			return rtn;
		}
};