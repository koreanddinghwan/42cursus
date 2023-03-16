#include "./UserDatabase.hpp"

const char *fileError = "Error: could not open file.";

UserDatabase::UserDatabase(int ac, char *av[]) 
{
	std::string line;
	if (ac != 2) {
		std::cout<<fileError<<std::endl;
		throw std::exception();
	}
	file.open(av[1]);
	if (file.fail()) {
		std::cout<<fileError<<std::endl;
		throw std::exception();
	} 
	std::getline(file, line);
}

UserDatabase::~UserDatabase() {}

UserDatabase::UserDatabase(UserDatabase &o) { static_cast<void>(o);}
UserDatabase& UserDatabase::operator=(UserDatabase &o) { static_cast<void>(o); return *this; }

DateAndValue* UserDatabase::get(void) throw (std::exception) 
{
	std::string		line;
	DateAndValue*	rtn = new DateAndValue();
	long long y,m,d = 0;
	double v = 0;
	
	if (!std::getline(file, line))
	{
		delete rtn;
		return 0;
	}
	sscanf(line.c_str(), "%lld-%lld-%lld | %lf", &y,&m,&d,&v);
	try {
		rtn->setYear(y);
		rtn->setMonth(m);
		rtn->setDay(d);
	} catch (std::exception &e) {
		std::cout<<"Error: "<<e.what()<<" => "<<line<<std::endl;
		delete rtn;
		throw e;
	}

	try {
		rtn->setValue(v);
	} catch (std::exception &e) {
		std::cout<<"Error: "<<e.what()<<std::endl;
		delete rtn;
		throw e;
	}
	return rtn;
}
