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
		explicit stack(const _Sequence& __cont = _Sequence()) : _c(__cont) {
		}

		stack(const stack& __o) {

		}
		
		~stack() {
			~this->_c;
		}

		stack& operator=(const stack& __o) {
			_c = __o._c;
			return (*this);
		}



		reference top() {

		}

};




} //namespace ft



#endif
