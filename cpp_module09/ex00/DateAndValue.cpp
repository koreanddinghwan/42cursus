#include "./DateAndValue.hpp"
#include <iostream>

DateAndValue::DateAndValue() {}
DateAndValue::~DateAndValue() {}

DateAndValue::DateAndValue(DateAndValue &o) {static_cast<void>(o);}
DateAndValue& DateAndValue::operator=(DateAndValue &o) { static_cast<void>(o); return *this;}


void DateAndValue::setYear(long long y) throw(InvalidDateException) 
{
	if (y < 2009)
		throw InvalidDateException();
	this->y = static_cast<short int>(y);
}

void DateAndValue::setMonth(long long m) throw(InvalidDateException) 
{
	if (m < 1 || m > 12)
		throw InvalidDateException();
	this->m = static_cast<char>(m);
}

void DateAndValue::setDay(long long d) throw(InvalidDateException) 
{
	std::cout<<d<<std::endl;
	if (d < 1)
		throw InvalidDateException();

	//check leap year
	if (this->m == 2 && this->y % 4 == 0) {
		if (d > 29)
			throw InvalidDateException();
	}
	else if (this->y == 2009) {
		if (this->m == 1 && this->d < 2)
			throw InvalidDateException();
	}
	//1, 3, 5, 7,8,10,12 == max 31
	else if ((this->m < 8 && this->m % 2 == 1) || 
			(this->m >= 8 && this->m % 2 == 0)) {
		if (d > 31)
			throw InvalidDateException();
	} else {//2,4,6,9,11
		if (d > 30)
			throw InvalidDateException();
	}
	this->d = static_cast<char>(d);
}

void DateAndValue::setValue(double v) throw(ValueIntOverflowException, ValueNotPositiveException) 
{
	if (static_cast<long long>(v) > INT_MAX)
		throw ValueIntOverflowException();
	else if (static_cast<int>(v) < 0)
		throw ValueNotPositiveException();
	this->v = static_cast<float>(v);
}

void DateAndValue::setRewindOneDay() 
{
	if (this->d == 1)
	{
		if (this->m == 1)
		{
			this->d = 31;
			this->m = 12;
			this->y -= 1;
		}
		else
		{
			this->d = 31;
			this->m -= 1;
		}
	}
	else
	{
		this->d -= 1;
	}
}

short int DateAndValue::getYear() const {
	return this->y;
}
char DateAndValue::getMonth() const {
	return this->m;
}
char DateAndValue::getDay() const {
	return this->d;
}
float DateAndValue::getValue() const {
	return this->v;
}

const char* DateAndValue::ValueIntOverflowException::what() const throw() {
	return "too large a number.";
}

const char* DateAndValue::ValueNotPositiveException::what() const throw() {
	return "not a positive number.";
}

const char* DateAndValue::InvalidDateException::what() const throw() {
	return "bad input";
}
