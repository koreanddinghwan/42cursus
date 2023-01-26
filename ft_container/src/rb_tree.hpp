#ifndef RB_TREE_HPP
#define RB_TREE_HPP

/*
 * actual implement of red-black tree
 * */

#include "utils/ft_reverse_iterator.hpp"
#include "utils/utils.hpp"
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
	typedef	_rb_tree_sentinel_node*			_node_ptr;
	typedef	const _rb_tree_sentinel_node*	_const_node_ptr;
	
	_rb_tree_color _color;
	_node_ptr _parent;
	_node_ptr _left;
	_node_ptr _right;

	//get a minimum node
	static _node_ptr _node_mininum(_node_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	static _node_ptr _node_maxinum(_node_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}

	static _const_node_ptr _const_node_mininum(_const_node_ptr __n)
	{
		while (__n && __n->_left) {
			__n = __n->_left;
		}
		return __n;
	}

	static _const_node_ptr _const_node_maxinum(_const_node_ptr __n)
	{
		while (__n && __n->_right) {
			__n = __n->_right;
		}
		return __n;
	}
};//sentinel node end

/* insert */
inline void _rb_tree_insert_rebalance(
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
	typedef _rb_tree_node<_T>* _Link_Type;
};//tree node end

class _rb_tree_iterator_base
{
public :
	typedef _rb_tree_sentinel_node::_node_ptr _ptr;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t diffrerence_type;

	//member
	_ptr __n;

	void _tree_iterator_increment() {
		if (__n->_right != NULL)
		{
			__n = __n->_right;
			__n = _rb_tree_sentinel_node::_node_mininum(__n);
		}
		else
		{
			//__n이 부모의 왼쪽자식이면 부모 그대로 반환
			//__n이 부모의 오른쪽 자식이면 부모를 left로 가지는 부모의 부모를 타고 올라가서 끝을 반환.
			_rb_tree_sentinel_node* __p = __n->_parent;
			while (__n == __p->_right)
			{
				__n = __p;
				__p = __p->_parent;
			}
			//stl rbtree의 sentinel node는 left, right, parent가 동일한 노드를 가리킨다.
			if (__n->_right != __p)
				__n = __p;
		}
	}

	void _tree_iterator_decrement() {

		//현재 노드가 sentinel node인경우, decrement는 
		if (__n->_color == _red && __n->_parent->_parent == __n)
			__n = __n->_right;
		else if (__n->_left != NULL)
		{
			//left에서 right most
			_rb_tree_sentinel_node *__left = __n->_left;
			__left =  _rb_tree_sentinel_node::_node_maxinum(__left);
			__n = __left;
		}
		else
		{
			_rb_tree_sentinel_node *__p = __n->_parent;
			while (__n == __p->_left)
			{
				__n = __p;
				__p = __p->_parent;
			}
			__n = __p;
		}
	}
};

template<typename _V, typename _R, typename _P>
class _rb_tree_iterator : public _rb_tree_iterator_base
{
	typedef _V value_type;
	typedef _R reference;
	typedef _P pointer;
	typedef _rb_tree_iterator<_V, _V&, _V*> iterator;
	typedef _rb_tree_iterator<_V, const _V&, const _V*> const_iterator;
	typedef _rb_tree_iterator<_V, _R, _R> self;
	typedef _rb_tree_node<_V>* link_type;

	_rb_tree_iterator() {}
	_rb_tree_iterator(link_type __o) {__n = __o;}
	_rb_tree_iterator(iterator __it) {__n = __it.__n;}

	reference operator*() const {
		return link_type(__n)->_value_field;
	}

	pointer operator->() const {
		return &(operator*());
	}

	self& operator++() {
		_tree_iterator_increment();
		return *this;
	}

	self operator++(int) {
		self tmp = *this;
		_tree_iterator_increment();
		return tmp;
	}

	self& operator--() {
		_tree_iterator_decrement();
		return *this;
	}

	self& operator--(int) {
		self tmp = *this;
		_tree_iterator_decrement();
		return tmp;
	}
};

/*
 * utils
 * */

inline _rb_tree_sentinel_node *_get_node_grand_parent(_rb_tree_sentinel_node *__n) {
	return (__n->_parent->_parent);
}

inline _rb_tree_sentinel_node *_get_node_uncle(_rb_tree_sentinel_node *__n) {
	//부모의 오른쪽 자식인 경우,
	_rb_tree_sentinel_node *_gp = _get_node_grand_parent(__n);

	if (_gp->_right == __n->_parent)
		return (_gp->_left);
	else
		return (_gp->_right);
}

inline const bool _is_root(_rb_tree_sentinel_node *__n) {
	_rb_tree_sentinel_node *_gp = _get_node_grand_parent(__n);
	if (_gp == __n)
		return true;
	else
		return false;
}

inline const bool _is_leaf(_rb_tree_sentinel_node *__n) {
	if (__n->_color == _black
		&& !(__n->_left) && !(__n->_right)
		)
		return true;
	else
		return false;
}


/*
 * rotate method
 * */

/*
 *          __p                         __p
 *
 *               __n       =>                   __c
 *
 *
 *          __b        __c                 __n       __cr
 *                     |  |                |  |
 *                 __cl   __cr           __b  __cl
 * */
inline void _rb_tree_rotate_left(
		_rb_tree_sentinel_node * const __n,
		_rb_tree_sentinel_node* &__root) {
	
	_rb_tree_sentinel_node *__c = __n->_right;

	//__cl
	__n->_right = __c->_left;
	if (__c->_left != NULL)
		__c->_left->_parent = __n;
	__c->_parent = __n->_parent;

	//__p
	if (__n == __root)//header node specification
		__root = __c;
	//__n is left child of __p -> now, __c is left child of __p
	else if (__n == __n->_parent->_left)
		__n->_parent->_left = __c;
	else
		__n->_parent->_right = __c;

	__c->_left = __n;
	__n->_parent = __c;
}

/*
 *                  __p                     __p
 *
 *
 *            __n         =>           __c
 *
 *
 *      __c      __b               __cl      __n
 *      | |                                  |  |
 *   __cl __cr                            __cr  __b
 * */
inline void _rb_tree_rotate_right(
		_rb_tree_sentinel_node * const __n,
		_rb_tree_sentinel_node* &__root) {
	
	_rb_tree_sentinel_node *__c = __n->_left;

	//__cr
	__n->_left = __c->_right;
	if (__c->_right != NULL)
		__c->_right->_parent = __n;
	__c->_parent = __n->_parent;

	//__p
	if (__n == __root)
		__root = __c;
	else if (__n == __n->_parent->_left)
		__n->_parent->_left = __c;
	else
		__n->_parent->_right = __c;

	__c->_right = __n;
	__n->_parent = __c;
}


inline void rebalancing_case1(
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
);

//ll, rr case
inline void rebalancing_case5(
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	_rb_tree_sentinel_node *__gp = _get_node_grand_parent(__n);

	__n->_parent->_color = _black;
	__gp->_color = _red;
	if (__n == __n->_parent->_left) //ll case
		_rb_tree_rotate_right(__gp, __h._parent);
	else //rr case
		_rb_tree_rotate_left(__gp, __h._parent);
}

// lr, rl case to ll, rr case
inline void rebalancing_case4(
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {

	_rb_tree_sentinel_node *__gp = _get_node_grand_parent(__n);

	if (//lr case to ll case
		__n == __n->_parent->_right
		&& __n->_parent == __gp->_left
		) 
	{
		_rb_tree_rotate_left(__n->_parent, __h._parent);
		__n = __n->_left; //old parent
	}
	else if (//rl case to rr case
			__n == __n->_parent->_left
			&& __n->_parent == __gp->_right
			) 
	{
		_rb_tree_rotate_right(__n->_parent, __h._parent);
		__n = __n->_right;
	}//ll, rr case and transformed ll, rr case by upper if, else if
	rebalancing_case5(__n, __h);
}

inline void rebalancing_case3 (
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	_rb_tree_sentinel_node *__gp;
	_rb_tree_sentinel_node *__u = _get_node_uncle(__n);

	if ((__u != NULL) && (__u->_color == _red)) {
		__n->_parent->_color = _black;
		__u->_color = _black;
		__gp = _get_node_grand_parent(__n);
		__gp->_color = _red;
		rebalancing_case1(__gp, __h);
	} else {
		rebalancing_case4(__n, __h);
	}
}

inline void rebalancing_case2 (
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	if (__n->_parent->_color == _black)
		return ;
	else
		rebalancing_case3(__n, __h);
}

inline void rebalancing_case1 (
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	
	if (_is_root(__n))
		__n->_color = _black;
	else
		rebalancing_case2(__n, __h);
}


inline void _rb_tree_insert_rebalance(
		const bool _insert_left,
		_rb_tree_sentinel_node* __n,
		_rb_tree_sentinel_node* __p,
		_rb_tree_sentinel_node& __h
		) {

	//삽입 노드 초기화
	__n->_color = _red;
	__n->_left = NULL;
	__n->_right = NULL;
	__n->_parent = __p;

	if (_insert_left)
	{
		__p->_left = __n;

		//삽입된 노드가 맨 처음 노드라면 header node의 모든 포인터가 자신을 가리키도록
		if (__p == &__h)
		{
			__h._parent = __n;
			__h._right = __n;
		}
		//삽입된 노드가 가장 왼쪽노드라면 해당 포인터를 header노드에서 유지
		else if (__p == __h._left)
			__h._left = __n;
	}
	else
	{
		__p->_right = __n;

		if (__p == __h._right)
			__h._right = __n;
	}

	//rebalancing
	rebalancing_case1(__n, __h);
}



template<typename _Key, 
	typename _Value, 
	typename _KeyOfValue, // == _Compare
	typename _Compare,  
	typename _Alloc = std::allocator<_Value> >
class _RB_tree {

	 //binding allocator with node_allocator
	 typedef typename _Alloc::template rebind< _rb_tree_node<_Value> >::other node_allocator;

	public:
	 typedef _Key key_type;
	 typedef _Value value_type;
	 typedef _Compare compare_type;
	 typedef _Alloc allocator_type;

	 typedef value_type*			pointer;
	 typedef const value_type*		const_pointer;
	 typedef value_type&			reference;
	 typedef const value_type&		const_reference;

	 typedef size_t					size_type;
	 typedef ptrdiff_t				difference_type;

	//iterators
	typedef _rb_tree_iterator<_Value, reference, pointer> iterator;
	typedef _rb_tree_iterator<_Value, const_reference, const_pointer> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	protected:
	 typedef _rb_tree_sentinel_node* _ptr;
	 typedef const _rb_tree_sentinel_node* _const_ptr; 
	 typedef _rb_tree_node<_Value> _rb_tree_node;

	private:
	 typedef _rb_tree_sentinel_node::_node_ptr			node_ptr;
	 typedef _rb_tree_sentinel_node::_const_node_ptr	const_node_ptr;
	 typedef _rb_tree_node*								Link_Type;
	 typedef const _rb_tree_node*						Const_Link_Type;

	public:
	 //get allocator of node, not _Alloc<_Val>
	 allocator_type get_allocator() const {
		 return *(static_cast<const node_allocator>(&this->_M_impl));
	 }

	 protected:
	 /*
	  * implementation of internal rb_tree
	  * @param _Key_Compare equals to _Compare function object
	 */
	 template<typename _Key_Compare>
	class _RB_tree_impl : public node_allocator
	{
		//key compare
		_Key_Compare			_M_key_cmp;
		//header node
		_rb_tree_sentinel_node	_M_header;
		//maintain node counts
		size_type				_M_node_cnt;

		//constructor
		_RB_tree_impl(const node_allocator& __a = node_allocator(), const _Key_Compare& __cmp = _Key_Compare()) : node_allocator(__a), _M_key_cmp(__cmp), _M_node_cnt(0) {
			this->_M_header._color = _red;
			this->_M_header._parent = NULL; //header's parent is begin
			this->_M_header._left = &this->_M_header; //maintain leftmost
			this->_M_header._right = &this->_M_header;
		}
	};

	_RB_tree_impl<_Compare> _M_impl;

	protected:
	/*
	 * internal methods
	 * */
	/*
	 * return first node
	 * if empty, return null
	*/
	node_ptr _M_root() {
		return this->_M_impl._M_header._parent;
	}
	
	node_ptr _M_leftmost() {
		return this->_M_impl._M_header._left;
	}

	node_ptr _M_rightmost() {
		return this->_M_impl._M_header._right;
	}

	//return header's parent == begin(root)
	Link_Type _M_begin() {
		return static_cast<Link_Type>(this->_M_impl._M_header._parent);
	}

	//return header node
	Link_Type _M_end() {
		return static_cast<Link_Type>(this->_M_impl._M_header);
	}

	//get node's value reference
	//const link type-> _RB_tree_node<_Tp>*
	static const_reference _S_value(Const_Link_Type __n) {
		return __n->_value_field;
	}
	static const_reference _S_value(_const_ptr __n) {
		return static_cast<Const_Link_Type>(__n)->_value_fieldl;
	}

	//get node's key
	static const _Key& _S_key(Const_Link_Type __n) {
		return _KeyOfValue()(_S_value(__n));
	}
		//get node's key
	static const _Key& _S_key(_ptr __n) {
		return _KeyOfValue()(_S_value(__n));
	}

	static Link_Type _S_left(_ptr __n) {
		return static_cast<Link_Type>(__n->_left);
	}
	static Const_Link_Type _S_left(_const_ptr __n) {
		return static_cast<Const_Link_Type>(__n->_left);
	}

	static Link_Type _S_right(_ptr __n) {
		return static_cast<Link_Type>(__n->_right);
	}
	static Const_Link_Type _S_right(_const_ptr __n) {
		return static_cast<Const_Link_Type>(__n->_right);
	}

	static _ptr _S_minimum(_ptr __n){
		return _rb_tree_sentinel_node::_node_mininum(__n);
	}
	static _const_ptr _S_minimum(_const_ptr __n){
		return _rb_tree_sentinel_node::_const_node_mininum(__n);
	}

	static _ptr _S_maximum(_ptr __n){
		return _rb_tree_sentinel_node::_node_maxinum(__n);
	}
	static _const_ptr _S_maximum(_const_ptr __n){
		return _rb_tree_sentinel_node::_const_node_maxinum(__n);
	}

	public:
		_RB_tree() {}
		_RB_tree(const _Compare& __cmp, const allocator_type &__a) : _M_impl(__a, __cmp)
		{}
		_RB_tree(const _Compare& __cmp) : _M_impl(allocator_type(), __cmp)
		{}
		_RB_tree(const _RB_tree<_Key, _Value, _KeyOfValue, _Compare>& __o): _M_impl() {
			
		}

};



};

#endif
