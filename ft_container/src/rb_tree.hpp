#ifndef RB_TREE_HPP
#define RB_TREE_HPP

/*
 * actual implement of red-black tree
 * */

#include <cstddef>
#include <iterator>
#include <memory>

namespace ft {

//tree color
enum _rb_tree_color {
	_red = 0,
	_black = 1
};

//tree sentinel node
//have only color, parent, left, right
class _rb_tree_sentinel_node {
public:
	typedef _rb_tree_sentinel_node* _ptr;
	typedef const _rb_tree_sentinel_node* _const_ptr;
	
	_rb_tree_color _color;
	_ptr _parent;
	_ptr _left;
	_ptr _right;

	static _ptr _node_mininum(_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	static _ptr _node_maxinum(_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}

	static _const_ptr _const_node_mininum(_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	static _const_ptr _const_node_maxinum(_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}
};//sentinel node end

/* increment iterator */
_rb_tree_sentinel_node* _rb_tree_increment(_rb_tree_sentinel_node* __n);
const _rb_tree_sentinel_node* _rb_tree_const_increment(const _rb_tree_sentinel_node* __n); 

/* decrement iterator */
_rb_tree_sentinel_node* _rb_tree_decrement(_rb_tree_sentinel_node* __n);
const _rb_tree_sentinel_node* _rb_tree_const_decrement(const _rb_tree_sentinel_node* __n);

/* insert */
void _rb_tree_insert_rebalance(
		const bool _insert_left,
		_rb_tree_sentinel_node* __n,
		_rb_tree_sentinel_node* __p,
		_rb_tree_sentinel_node& __h
		);

/* remove */

//tree node
template<typename _T>
class _rb_tree_node : public _rb_tree_sentinel_node {

public:
	_T _value_field;
	typedef _rb_tree_node<_T> _Link_Type;
};//tree node end

//iterator
template<typename _Tp>
class _Rb_tree_iterator {
	typedef _Tp value_type;
	typedef _Tp& reference;
	typedef _Tp* pointer;

	typedef std::bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

	typedef _Rb_tree_iterator<_Tp> _Self;
	typedef _rb_tree_sentinel_node::_ptr _Base_ptr;
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
		_M_node = _rb_tree_increment(_M_node);
		return (*this);
	}

	_Self& operator++(int) {
		_Self _tmp = *this;
		_M_node = _rb_tree_increment(_M_node);
		return (_tmp);
	}

	_Self& operator--() {
		_M_node = _rb_tree_decrement(_M_node);
		return (*this);
	}

	_Self& operator--(int) {
		_Self _tmp = *this;
		_M_node = _rb_tree_decrement(_M_node);
		return (_tmp);
	}

	bool operator==(const _Self& __o) const {
		return _M_node == __o._M_node;
	}

	bool operator!=(const _Self& __o) const {
		return _M_node != __o._M_node;
	}
};//iterator end

template<typename _Tp>
class _Rb_tree_const_iterator {
	typedef _Tp value_type;
	typedef _Tp& reference;
	typedef _Tp* pointer;

	typedef _Rb_tree_iterator<_Tp> iterator;

	typedef std::bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

	typedef _Rb_tree_const_iterator<_Tp> _Self;
	typedef _rb_tree_sentinel_node::_const_ptr _Base_ptr;
	typedef _rb_tree_node<_Tp>* _Link_Type; //inner node pointer
	
	//member node
	_Base_ptr _M_node;

	_Rb_tree_const_iterator() : _M_node() {}
	_Rb_tree_const_iterator(_Link_Type __v) : _M_node(__v) {}
	_Rb_tree_const_iterator(const iterator& it) : _M_node(it._M_node) {}
	
	reference operator*() const {
		return static_cast<_Link_Type>(_M_node)->_value_field;
	}

	pointer operator->() const {
		return &static_cast<_Link_Type>(_M_node)->_value_field;
	}

	_Self& operator++() {
		_M_node = _rb_tree_const_increment(_M_node);
		return (*this);
	}

	_Self& operator++(int) {
		_Self _tmp = *this;
		_M_node = _rb_tree_const_increment(_M_node);
		return (_tmp);
	}

	_Self& operator--() {
		_M_node = _rb_tree_const_decrement(_M_node);
		return (*this);
	}

	_Self& operator--(int) {
		_Self _tmp = *this;
		_M_node = _rb_tree_const_decrement(_M_node);
		return (_tmp);
	}

	bool operator==(const _Self& __o) const {
		return _M_node == __o._M_node;
	}

	bool operator!=(const _Self& __o) const {
		return _M_node != __o._M_node;
	}
};//const iterator end

template<typename _v>
bool operator==(const _Rb_tree_iterator<_v>& _l,
		const _Rb_tree_const_iterator<_v> &_r) {
	return _l._M_node == _r._M_node;
}

template<typename _v>
bool operator!=(const _Rb_tree_iterator<_v>& _l,
		const _Rb_tree_const_iterator<_v> &_r) {
	return _l._M_node != _r._M_node;
}

template<typename _Key, typename _Value, typename _KeyOfValue, typename _Compare, typename _Alloc = std::allocator<_Value> >
class _RB_tree {


	protected:
	 typedef _rb_tree_sentinel_node* _ptr;
	 typedef const _rb_tree_sentinel_node* _const_ptr; 
	 typedef _rb_tree_node<_Value> _rb_tree_node;

	public:
	 typedef _Key key_type;
	 typedef _Value value_type;
	 typedef value_type* pointer;
	 typedef const value_type* const_pointer;
	 typedef value_type& reference;
	 typedef const value_type& const_reference;
	 typedef _rb_tree_node* _Link_Type;
	 typedef const _rb_tree_node* _Const_Link_Type;
	 typedef size_t size_type;
	 typedef ptrdiff_t difference_type;
	 typedef _Alloc allocator_type;




};


};
#endif
