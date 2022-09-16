#include <iostream>

int	ft_strlen(const char *str)
{
	int	size;

	if (!str)
		return (-1);
	size = 0;
	while (str[size])
		size++;
	return (size);
}

class MyString
{
	private:
	char	*string_content;
	int		string_length;
	int		memory_capacity;
	public:
	MyString(char c);
	MyString(const char *str);
	MyString(const MyString& str);
	~MyString();
	int		length()	const;
	void	print()		const;
	void	println()	const;
	MyString&	assign(const char *str);
	MyString&	assign(const MyString &str);
	void	reserve(int size);
	char	at(int index) const;
	int		capacity(void) const;
	MyString& insert(int loc, const MyString &str);
	MyString& insert(int loc, const char *str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}
MyString::MyString(const char *str)
{
	string_length = ft_strlen(str);
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
	memory_capacity = string_length;
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	string_content = new char[string_length];
	memory_capacity = string_length;
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}

MyString::~MyString()
{
	delete []string_content;
}

int MyString::length() const
{
	return string_length;
}

void MyString::print() const
{
	for (int i = 0; i != string_length; i++)
	{
		std::cout<<string_content[i];
	}
}

void MyString::println() const
{
	for (int i = 0; i != string_length; i++)
	{
		std::cout<<string_content[i];
	}
	std::cout<<std::endl;
}

MyString& MyString::assign(const char *str)
{
	int	str_length = ft_strlen(str);
	if (str_length > memory_capacity)
		delete []string_content;
	string_content = new char[str_length];
	memory_capacity = str_length;
	string_length = str_length;
	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
	return (*this);

}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length > memory_capacity)
		delete []string_content;
	string_content = new char[str.string_length];
	memory_capacity = str.string_length;
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
	string_length = str.string_length;
	return (*this);
}

void	MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char *prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
}

char	MyString::at(int i) const
{
	if (i >= string_length || i < 0)
		return (0);
	else
		return (string_content[i]);
}

MyString&	MyString::insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > string_length)
		return *this;
	if (string_length + str.string_length > memory_capacity)
	{
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char *prev_string_content = string_content;
		string_content = new char[memory_capacity];
		int i;
		for (i = 0; i < loc; i++)
			string_content[i] = prev_string_content[i];
		for (int j = 0; j != str.string_length; j++)
		string_content[i + j] = str.string_content[j];

		for (; i < string_length; i++)
			string_content[str.string_length + i] = prev_string_content[i];

		delete []prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	for (int i = string_length - 1; i >= loc; i--)
		string_content[i + str.string_length] = string_content[i];

	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];
	string_length = string_length + str.string_length;
	return (*this);
}

MyString& MyString::insert(int loc, const char *str)
{
	MyString temp(str);
	return (insert(loc, temp));
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return (insert(loc, temp));
}

int MyString::capacity() const
{
	return memory_capacity;
}

MyString &erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > string_length)
		return *this;

	for (int i = loc + num; i < string_length; i++)
		string_content[i - num] = string_content[i];
	string_length -= num;
	return (*this);
}

int main()
{
	MyString str1("very very very long string");
	str1.reserve(30);
	
	std::cout<<"Capacity : "<<str1.capacity()<<std::endl;
	std::cout<<"String length : " << str1.length()<<std::endl;
	str1.println();
	return 0;
}
