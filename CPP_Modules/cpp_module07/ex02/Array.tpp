#ifndef ARRAY_TPP

# ifndef ARRAY_HPP
#  error __FILE__ should only be included from array.hpp
# endif

# define ARRAY_TPP

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T> &arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout<<arr[i]<<std::endl;
	return (os);
}

template <typename T>
Array<T>::Array(void): num(0), arr(new T[0])
{
	std::cout<<"Array Default Constructor Called!"<<std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): num(n), arr(new T[n])
{
	std::cout<<"Array Constructor Called!"<<std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : num(copy.num), arr(new T[copy.num])
{
	std::cout<<"Array Copy Constructor Called!"<<std::endl;
	for (unsigned int i = 0; i < num; i++)
		this->arr[i] = copy.arr[i];//해당 T의 operator= 에 해당하는 메서드로 값을 대입
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy)
{
	if (this == &copy) //early return 
		return (*this);

	delete[] this->arr;
	this->num = copy.num;
	arr = new T[num];

	for (unsigned int i = 0; i < num; i++)
		this->arr[i] = copy.arr[i];//해당 T의 operator= 에 해당하는 메서드로 값을 대입

	return (*this);
}

template <typename T>
Array<T>::~Array<T>(void)
{
	std::cout<<"Array Destructor Called!"<<std::endl;
	delete []this->arr;//각 원소의 소멸자 호출
}

//Array 객체가 const일때
template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= num)
		throw (OutOfBoundException());
	else
		return (this->arr[i]);
}

//Array 객체가 const가 아닐때
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= num)
		throw (OutOfBoundException());
	else
		return (this->arr[i]);
}


template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->num);
}

template <typename T>
const char *Array<T>::OutOfBoundException::what(void) const throw()
{
	return ("Out of range");
}

#endif
