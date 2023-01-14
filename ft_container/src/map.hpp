#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/ft_pair.hpp"
#include <cstddef>
#include <memory>

namespace ft {

	/*
	 * unique key를 가지는 key-value pari를 가지는 정렬된 컨테이너.
	 * key는 __Compare함수를 통해 정렬된다.
	 * Search, removal, insertion 연산은 로그 시간 복잡도를 가진다.
	 * 일반적으로 rb tree를 통해 구현된다.
	 * */
template< typename __Key, typename __Tp, 
	typename __Compare = std::less<__Key>,
    typename __Alloc = std::allocator<ft::pair<const __Key, __Tp>>
> class map {

typedef __Key key_type;
typedef __Tp mapped_type;
typedef __Compare key_compare;
typedef ft::pair<const __Key, __Tp> value_type;


/*
 * member class
 * value_compare : function object
 * */
class value_compare {
	typedef bool result_type;
	typedef map::value_type first_argument_type;
	typedef map::value_type second_argument_type;

	protected:
		/*
		 * function object
		 * */
		__Compare _comp;

	public:
		/*
		 * initilaize of comparer _comp
		 * */
		value_compare(__Compare c) : _comp(c) { }

		result_type operator()(const value_type& _lhs, const value_type& _rhs) {
			return (this->_comp(_lhs.first, _rhs.first));
		}
};

private:

public:
      typedef typename __Alloc::pointer                   pointer;
      typedef typename __Alloc::const_pointer             const_pointer;
      typedef typename __Alloc::reference                 reference;
      typedef typename __Alloc::const_reference           const_reference;




};








}
#endif
