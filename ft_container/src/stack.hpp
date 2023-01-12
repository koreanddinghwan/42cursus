#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"



namespace ft {

template<typename _Tp, typename _Sequence = ft::vector<_Tp> > class stack
{
	//typedefs
	public:
		typedef typename _Sequence::value_type value_type;
		typedef typename _Sequence::size_type size_type;
		typedef typename _Sequence::reference reference;
		typedef typename _Sequence::const_reference const_reference;
		typedef _Sequence constainer_type;


	//member object
	protected:
		_Sequence _c;


	//member functions
	public:
		stack(const _Sequence& __cont = _Sequence()) : _c(__cont) {}

		stack(const stack& __o) {
			this->_c = __o._c;
		}
		
		~stack() {
		}

		stack& operator=(const stack& __o) {
			_c = __o._c;
			return (*this);
		}

		reference top() {
			return (_c.back());
		}

		const_reference top() const {
			return (_c.back());
		}

		bool empty() const {
			return (_c.empty());
		}

		size_type size() const {
			return (_c.size());
		}

		void push(const value_type& value) {
			return (_c.push_back(value));
		}

		void pop() {
			return (_c.pop_back());
		}

		/*
		 * _c is proteted member object, 
		 * so these two friend function enable operator specialization
		 * to compare lhs' _c and rhs' c
		 * */
		template<typename T, typename C>
		friend bool operator==(const stack<T, C>& lhs, const stack<T, C>& rhs);
	
		template<typename T, typename C>
		friend bool operator<(const stack<T, C>& lhs, const stack<T, C>& rhs);
};

//Non-member funtions

template< typename _Tp, typename _Sequence >
bool operator==( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return (lhs._c == rhs._c);
}

template< typename _Tp, typename _Sequence >
bool operator!=( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return (!(lhs == rhs));
}

template< typename _Tp, typename _Sequence >
bool operator<( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return (lhs._c < rhs._c);
}

template< typename _Tp, typename _Sequence >
bool operator>=( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return !(lhs < rhs);
}

template< typename _Tp, typename _Sequence >
bool operator>( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return (rhs < lhs);
}

template< typename _Tp, typename _Sequence >
bool operator<=( const ft::stack<_Tp,_Sequence>& lhs, const ft::stack<_Tp,_Sequence>& rhs ) 
{
	return !(rhs < lhs);
}

} //namespace ft

#endif
