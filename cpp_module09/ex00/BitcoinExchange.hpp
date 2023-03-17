#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "DateAndValue.hpp"

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
	Exchanger(const char *fileName);
	~Exchanger();

private:
	//do not use explicitly
	Exchanger(Exchanger &o);
	Exchanger& operator=(Exchanger &o);

private:
	void reserveVector();
	void init(char const *fileName) throw(std::exception);
	float getPrice(int y, int m, int d) const;

public:
	void printPriceByDate(DateAndValue *v);
};

#endif
