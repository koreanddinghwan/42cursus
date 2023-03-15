#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef __BitcoinExchange_HPP__
# define __BitcoinExchange_HPP__

class Exchanger {
//typedefs
private:
	typedef std::vector<float> days;
	typedef std::vector<days> months;

public:
	typedef std::vector<months> PriceChart;

//member variables
private:
	PriceChart	chart;

/** methods **/
public:
	Exchanger(const char *fileName) {
		this->reserveVector();
		this->init(fileName);
	}
	~Exchanger() {}

private:
	//do not use explicitly
	Exchanger(Exchanger &o) {}
	Exchanger& operator=(Exchanger &o) {return *this;}

private:
	void reserveVector() {
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

	void init(char const *fileName) throw(std::exception) {
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
			throw std::exception();
		}
	}

public:
	float getPrice(int y, int m, int d) const throw(std::out_of_range) {
	  return chart[y-2009][m-1].at(d - 1);
	}
};

#endif
