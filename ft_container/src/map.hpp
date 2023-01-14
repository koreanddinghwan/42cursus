#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/ft_pair.hpp"
#include <memory>

namespace ft {

	/*
	 * unique key를 가지는 key-value pari를 가지는 정렬된 컨테이너.
	 * key는 Compare함수를 통해 정렬된다.
	 * Search, removal, insertion 연산은 로그 시간 복잡도를 가진다.
	 * 일반적으로 rb tree를 통해 구현된다.
	 * */
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T>>
> class map {



};








}
#endif
