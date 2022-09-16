#include "Converter.hpp"
#include <cctype>

template <typename T>
std::string tostr(const T& t)
{ 
	std::ostringstream os;
	os<<t;
	return os.str(); 
};

template <>
std::string tostr<char>(const char& t)
{ 
	std::string rtn;

	rtn.push_back('\'');
	rtn.push_back(t);
	rtn.push_back('\'');
	return (rtn);
};

template <>
std::string tostr<float>(const float& t)
{ 
	std::ostringstream os;
	std::string rtn;
	os.unsetf(std::ios::floatfield);
	os.precision(std::numeric_limits<float>::digits10);
	os<<t; //출력버퍼에 출력결과가 있음.
	os.setf(std::ios::floatfield);
	rtn = os.str();//출력버퍼로부터 값 가져오기
	if (t - static_cast<int>(t) == 0)
		rtn.append(".0f");
	else
		rtn.append("f");
	return rtn;
};

template <>
std::string tostr<double>(const double& t)
{ 
	std::ostringstream os;
	os.unsetf(std::ios::floatfield);
	os.precision(std::numeric_limits<double>::digits10);
	os<<t;
	os.setf(std::ios::floatfield);
	std::string rtn = os.str();//출력버퍼로부터 값 가져오기
	if (t - static_cast<int>(t) == 0)
		rtn.append(".0");
	return rtn; 
};

Converter::Converter(void) throw(std::invalid_argument) : av()
{
	throw std::invalid_argument("Invalid Argument");
}

Converter::Converter(char *av) throw(std::invalid_argument) : av(av), f(std::strtod(av, &endp)), i(std::strtol(av, &iendp, 10))
{
	if (isnan(f) && std::strlen(endp) != 0) //check nana nanf ....
		throw std::invalid_argument("Invalid Argument");
	else if (std::strlen(endp) != 0 && std::strcmp(endp ,"f") != 0 && std::strlen(av) != 1) //check invalid floating nums
		throw std::invalid_argument("Invalid Argument!");
	this->print();
} 

Converter::Converter(const Converter& copy)
{
	(void)copy;
} 

Converter& Converter::operator=(const Converter &copy)
{
	(void)copy;
	return *this;
}

Converter::~Converter()
{}

void Converter::print(void) const
{
	std::cout<<"char: "<<getchar()<<std::endl;
	std::cout<<"int: "<<getint()<<std::endl;
	std::cout<<"float: "<<getfloat()<<std::endl;
	std::cout<<"double: "<<getdouble()<<std::endl;
}
 
const std::string Converter::getchar(void) const
{
	std::string rtn;

	if (isnan(f) || isinf(f))
		return "impossible";
	if (i < -128 || i >= 127)
		return "overflow";
	if (std::strlen(av) == 1 && (av[0] < 48 || av[0] > 57)) //1글자 문자일때
		return (tostr(static_cast<int>(av[0])));
	if (!std::isprint(static_cast<char>(f)))
		return "Non displayable";
	return (tostr(static_cast<char>(f)));
}

const std::string Converter::getint(void) const
{
	if (isnan(f) || isinf(f) || std::isalpha(av[0]))
		return "impossible";
	if (i > INT32_MAX || i < INT32_MIN) //overflowed, -2147483648 ~
		return "overflow";
	return (tostr(static_cast<int>(f)));
}

const std::string Converter::getfloat(void) const
{
	if (isnan(f))
		return "nanf";
	if (isinf(f))
	{
		if (av[0] == '-')
			return "-inff";
		else
			return "+inff";
	}
	if (std::isalpha(av[0]))
		return "impossible";
	return (tostr(static_cast<float>(f)));
}

const std::string Converter::getdouble(void) const
{
	if (isnan(f))
		return "nan";
	if (isinf(f))
	{
		if (av[0] == '-')
			return "-inf";
		else
			return "+inf";
	}
	if (std::isalpha(av[0]))
		return "impossible";
	return (tostr(f));
}
