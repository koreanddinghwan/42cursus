#ifndef FT_FUNCTION_HPP
#define FT_FUNCTION_HPP

#include "ft_pair.hpp"
#include <__functional/unary_function.h>
namespace ft {

	/*
	 * std::unary_function
	 * base class for creating function objects with one argument
	 * unary function does not define operator(), 
	 * so we need to define operator() in derived class
	 * depreciated in c++11
	 * */


	/*
	 * _Identity used in stl_set
	 * because set need value_type as key
	 * */
	template<typename _Tp>
	class _Identity : public std::unary_function<_Tp, _Tp>
	{
		const _Tp& operator()(const _Tp& __x) const {
			return __x;
		}
	};

	/*
	 * _Select1st used in stl_map
	 * map have pair(key - value)
	 *   typedef T1 first_type;
	 *   typedef T2 second_type;
	 *   T1 first;
	 *   T2 second;
	 * _Select1st return first_type(key)
	 * */
	template<typename _Pair>
	class _Select1st : public std::unary_function<_Pair, typename _Pair::first_type>
	{
		const typename _Pair::first_type& operator() (const _Pair& __x) {
			return __x.first;
		}
	};

};

#endif
