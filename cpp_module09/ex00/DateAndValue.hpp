#include <climits>
#include <exception>
#include <stdexcept>

#ifndef __DATEANDVALUE_HPP__
# define __DATEANDVALUE_HPP__

class DateAndValue{

private:
	short int	y;
	char		m;
	char		d;
	float		v;

public:
	DateAndValue();
	~DateAndValue();

private:
	DateAndValue(DateAndValue &o);
	DateAndValue& operator=(DateAndValue &o);


public:
	void setYear(long long y) throw(InvalidDateException);
	void setMonth(long long m) throw(InvalidDateException); 
	void setDay(long long d) throw(InvalidDateException);
	void setValue(double v) throw(ValueIntOverflowException, ValueNotPositiveException);
	void setRewindOneDay();
	short int getYear() const;
	char getMonth() const;
	char getDay() const;
	float getValue() const;

	class ValueIntOverflowException : public std::exception {
		public:
			const char *what() const throw();
	};

	class ValueNotPositiveException : public std::exception {
		public:
			const char *what() const throw();
	};

	class InvalidDateException : public std::exception {
		public:
			const char *what() const throw();
	};
};

#endif
