#ifndef RB_TREE_HPP
#define RB_TREE_HPP

/*
 * actual implement of red-black tree
 * */

#include <cstddef>
#include <iterator>
namespace ft {

//tree color
enum _rb_tree_color {
	_red = 0,
	_black = 1
};

//tree centinel node
//have only color, parent, left, right
class _rb_tree_centinel_node {
	protected:
	typedef _rb_tree_centinel_node* _ptr;
	typedef const _rb_tree_centinel_node* _const_ptr;
	
	_rb_tree_color _color;
	_ptr _parent;
	_ptr _left;
	_ptr _right;

	_ptr _node_mininum(_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	_ptr _node_maxinum(_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}

	_const_ptr _const_node_mininum(_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	_const_ptr _const_node_maxinum(_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}

	/* increment */
	_rb_tree_centinel_node* _rb_tree_increment(_rb_tree_centinel_node* __n) {
		if (__n->_right != NULL)
		{
			__n = __n->_right;
			__n = _node_mininum(__n);
		}
		else
		{
			//__n이 부모의 왼쪽자식이면 부모 그대로 반환
			//__n이 부모의 오른쪽 자식이면 부모를 left로 가지는 부모의 부모를 타고 올라가서 끝을 반환.
			_rb_tree_centinel_node* __p = __n->_parent;
			while (__n == __p->_right)
			{
				__n = __p;
				__p = __p->_parent;
			}
			//
			if (__n->_right != __p)
				__n = __p;
		}
		return __n;
	}

	_rb_tree_centinel_node* _rb_tree_decrement(_rb_tree_centinel_node* __n) {
		
	}

	const _rb_tree_centinel_node* _rb_tree_increment(const _rb_tree_centinel_node* __n) {
		
	}

	const _rb_tree_centinel_node* _rb_tree_decrement(const _rb_tree_centinel_node* __n) {
		
	}
};

//tree node
template<typename _T>
class _rb_tree_node : public _rb_tree_centinel_node {

public:
	_T _value_field;
	typedef _rb_tree_node<_T> _Link_Type;
};

//iterator
template<typename _Tp>
class _Rb_tree_iterator {
	typedef _Tp value_type;
	typedef _Tp& reference;
	typedef _Tp* pointer;

	typedef std::bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

	typedef _Rb_tree_iterator<_Tp> _Self;
	typedef _rb_tree_node::_ptr _Base_ptr;
	typedef _rb_tree_node<_Tp>* _Link_Type; //inner node pointer
	
	//member node
	_Base_ptr _M_node;

	_Rb_tree_iterator() : _M_node() {}
	_Rb_tree_iterator(_Link_Type __v) : _M_node(__v) {} 
	
	reference operator*() const {
		return static_cast<_Link_Type>(_M_node)->_value_field;
	}

	pointer operator->() const {
		return &static_cast<_Link_Type>(_M_node)->_value_field;
	}

	_Self& operator++() {
		return _M_node;
	}
};


};





};


#endif
