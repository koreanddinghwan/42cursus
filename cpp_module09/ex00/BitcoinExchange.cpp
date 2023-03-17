#include "./BitcoinExchange.hpp"
#include <iomanip>

Exchanger::Exchanger(const char *fileName) 
{
	this->reserveVector();
	this->init(fileName);
}

Exchanger::~Exchanger() {}

//do not use explicitly
Exchanger::Exchanger(Exchanger &o) { static_cast<void>(o); }
Exchanger& Exchanger::operator=(Exchanger &o) { static_cast<void>(o); return *this; }

void Exchanger::reserveVector() 
{
	chart.resize(14);
	for (int i = 0; i < 14; i++)
	{
		chart[i].resize(12);
		for (int j = 0; j < 12; j++)
		{
			chart[i][j].assign(31, -1);
		}
	}
}

void Exchanger::init(char const *fileName) throw(std::exception) 
{
	std::string line;
	short int	t_y;
	char		t_m;
	char		t_d;
	float		t_price;

	std::ifstream file(fileName);
	std::getline(file, line);
	if (file.is_open())
	{
		std::getline(file, line);
		while (std::getline(file, line))
		{
			t_y = atoi(&line[0]);
			t_m = atoi(&line[5]);
			t_d = atoi(&line[8]);
			t_price = atof(&line[11]);
			chart[t_y - 2009][t_m - 1][t_d - 1] = t_price;
		}
		file.close();
	} else {
		std::cout<<"Error: cannot open file"<<std::endl;
		throw std::exception();
	}
}

float Exchanger::getPrice(int y, int m, int d) const 
{
	if (y >= 2022 && m >= 3 && d >= 30)
		return chart[13][2][28];

	return chart[y-2009][m-1].at(d - 1);
}

void Exchanger::printPriceByDate(DateAndValue *v) {
	std::cout<<static_cast<int>(v->getYear())<<"-"<<static_cast<int>(v->getMonth())<<"-"<<static_cast<int>(v->getDay())<<" => "<<v->getValue()<<" = ";
	while (1) {
		float p = this->getPrice(v->getYear(), v->getMonth(), v->getDay());
		if (p == -1)
		{
			v->setRewindOneDay();
			continue;
		}
		else {
			std::cout<<std::fixed<<std::setprecision(2)<<p * v->getValue()<<std::endl;
			break;
		}
	}
}

