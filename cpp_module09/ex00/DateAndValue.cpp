
#ifndef __DATEANDVALUE_HPP__
# define __DATEANDVALUE_HPP__

#include <climits>
#include <exception>
#include <stdexcept>
class DateAndValue{

private:
	short int	y;
	char		m;
	char		d;
	float		v;

public:
	DateAndValue() {}
	~DateAndValue() {}

private:
	DateAndValue(DateAndValue &o) {}
	DateAndValue& operator=(DateAndValue &o) {return *this;}


public:
	void setYear(long long y) throw(InvalidDateException) {
		if (y < 2009)
			throw InvalidDateException();
		this->y = static_cast<short int>(y);
	}

	void setMonth(long long m) throw(InvalidDateException) {
		if (m < 1 || m > 12)
			throw InvalidDateException();
		this->m = static_cast<char>(m);
	}

	void setDay(long long d) throw(InvalidDateException) {
		if (d < 1)
			throw InvalidDateException();

		//check leap year
		if (this->m == 2 && this->y % 4 == 0) {
			if (d > 29)
				throw InvalidDateException();
		}//1, 3, 5, 7,8,10,12 == max 31
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

	void setValue(double v) throw(ValueIntOverflowException, ValueNotPositiveException) {
		if (static_cast<int>(v) > INT_MAX)
			throw ValueIntOverflowException();
		else if (static_cast<int>(v) < 0)
			throw ValueNotPositiveException();
		this->v = static_cast<float>(v);
	}

	short int getYear() const {
		return this->y;
	}
	char getMonth() const {
		return this->m;
	}
	char getDay() const {
		return this->d;
	}
	char getValue() const {
		return this->v;
	}

	class ValueIntOverflowException : public std::exception {
		public:
			const char *what() const throw() {
				return "too large a number.";
			}
	};

	class ValueNotPositiveException : public std::exception {
		public:
			const char *what() const throw() {
				return "not a positive number.";
			}
	};

	class InvalidDateException : public std::exception {
		public:
			const char *what() const throw() {
				return "bad input";
			}
	};
};

#endif
