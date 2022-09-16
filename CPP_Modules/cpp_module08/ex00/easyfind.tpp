#ifndef EASYFIND_TPP

#ifndef EASYFIND_HPP
# error __FILE__ should only be included from easyfind.hpp
#endif

# define EASYFIND_TPP

template <typename T>
class NotFound : public std::exception
{
	const char* what() const throw()
	{
		return ("Not found in container");
	}
};

template<typename T>
void easyfind(T& container, int key) throw(NotFound<T>)
{
	std::cout<<"I want to find "<<key<<std::endl;
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), key);
	if (it != container.end())
		std::cout<<"Found!"<<" "<<*it<<std::endl;
	else
		throw(NotFound<T>());
}

#endif
