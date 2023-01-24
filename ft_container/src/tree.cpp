#ifndef _TREE_CPP
#define _TREE_CPP

#include "rb_tree.hpp"
#include <cstddef>

namespace ft
{

/* increment */
_rb_tree_centinel_node* _rb_tree_increment(_rb_tree_centinel_node* __n) {
	if (__n->_right != NULL)
	{
		__n = __n->_right;
		__n = _rb_tree_centinel_node::_node_mininum(__n);
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
		//stl rbtree의 sentinel node는 left, right, parent가 동일한 노드를 가리킨다.
		if (__n->_right != __p)
			__n = __p;
	}
	return __n;
}

const _rb_tree_centinel_node* _rb_tree_const_increment(const _rb_tree_centinel_node* __n) {
	return _rb_tree_increment(const_cast<_rb_tree_centinel_node *>(__n));	
}


_rb_tree_centinel_node* _rb_tree_decrement(_rb_tree_centinel_node* __n) {

	//현재 노드가 sentinel node인경우, decrement는 
	if (__n->_color == _red && __n->_parent->_parent == __n)
		__n = __n->_right;
	else if (__n->_left != NULL)
	{
		//left에서 right most
		_rb_tree_centinel_node *__left = __n->_left;
		__left =  _rb_tree_centinel_node::_node_maxinum(__left);
		__n = __left;
	}
	else
	{
		_rb_tree_centinel_node *__p = __n->_parent;
		while (__n == __p->_left)
		{
			__n = __p;
			__p = __p->_parent;
		}
		__n = __p;
	}
	return __n;
}

const _rb_tree_centinel_node* _rb_tree_const_decrement(const _rb_tree_centinel_node* __n) {
	return _tree_decrement(const_cast<_rb_tree_centinel_node *>(__n));	
}

_rb_tree_centinel_node *_get_node_grand_parent(_rb_tree_centinel_node *__n) {

	if (__n->_parent->_parent == __n)
		return NULL;
	else
		return (__n->_parent->_parent);
}

_rb_tree_centinel_node *_get_node_uncle(_rb_tree_centinel_node *__n) {
	//부모의 오른쪽 자식인 경우,
	_rb_tree_centinel_node *_gp = _get_node_grand_parent(__n);

	if (!_gp)
		return NULL;

	if (_gp->_right == __n->_parent)
		return (_gp->_left);
	else
		return (_gp->_right);
}

const bool _is_root(_rb_tree_centinel_node *__n) {
	_rb_tree_centinel_node *_gp = _get_node_grand_parent(__n);
	if (_gp == __n)
		return true;
	else
		return false;
}

void rebalancing_case1(
		_rb_tree_centinel_node *__n,
		_rb_tree_centinel_node *__p,
		_rb_tree_centinel_node &__h
);

void rebalancing_case4(
		_rb_tree_centinel_node *__n,
		_rb_tree_centinel_node *__p,
		_rb_tree_centinel_node &__h
		) {

}

void rebalancing_case3 (
		_rb_tree_centinel_node *__n,
		_rb_tree_centinel_node *__p,
		_rb_tree_centinel_node &__h
		) {
	_rb_tree_centinel_node *__gp;
	_rb_tree_centinel_node *__u = _get_node_uncle(__n);

	if ((__u != NULL) && (__u->_color == _red)) {
		__n->_parent->_color = _black;
		__u->_color = _black;
		__gp = _get_node_grand_parent(__n);
		__gp->_color = _red;
		rebalancing_case1(__gp, __gp->_parent, __h);
	} else {

	}

}

void rebalancing_case2 (
		_rb_tree_centinel_node *__n,
		_rb_tree_centinel_node *__p,
		_rb_tree_centinel_node &__h
		) {
	if (__p->_color == _black)
		return ;
	else
		rebalancing_case3(__n, __p, __h);
}

void rebalancing_case1 (
		_rb_tree_centinel_node *__n,
		_rb_tree_centinel_node *__p,
		_rb_tree_centinel_node &__h
		) {
	
	if (_is_root(__n))
		__n->_color = _black;
	else
		rebalancing_case2(__n, __p, __h);
}


void _rb_tree_insert_rebalance(
		const bool _insert_left,
		_rb_tree_centinel_node* __n,
		_rb_tree_centinel_node* __p,
		_rb_tree_centinel_node& __h
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
	rebalancing_case1(__n, __p, __h);
}

};

#endif
