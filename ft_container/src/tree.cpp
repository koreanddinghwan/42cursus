#ifndef _TREE_CPP
#define _TREE_CPP

#include "rb_tree.hpp"
#include <cstddef>

namespace ft
{




/*
 * utils
 * */

_rb_tree_sentinel_node *_get_node_grand_parent(_rb_tree_sentinel_node *__n) {
	return (__n->_parent->_parent);
}

_rb_tree_sentinel_node *_get_node_uncle(_rb_tree_sentinel_node *__n) {
	//부모의 오른쪽 자식인 경우,
	_rb_tree_sentinel_node *_gp = _get_node_grand_parent(__n);

	if (_gp->_right == __n->_parent)
		return (_gp->_left);
	else
		return (_gp->_right);
}

const bool _is_root(_rb_tree_sentinel_node *__n) {
	_rb_tree_sentinel_node *_gp = _get_node_grand_parent(__n);
	if (_gp == __n)
		return true;
	else
		return false;
}

const bool _is_leaf(_rb_tree_sentinel_node *__n) {
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
void _rb_tree_rotate_left(
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
void _rb_tree_rotate_right(
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


void rebalancing_case1(
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
);

//ll, rr case
void rebalancing_case5(
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
void rebalancing_case4(
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

void rebalancing_case3 (
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

void rebalancing_case2 (
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	if (__n->_parent->_color == _black)
		return ;
	else
		rebalancing_case3(__n, __h);
}

void rebalancing_case1 (
		_rb_tree_sentinel_node *__n,
		_rb_tree_sentinel_node &__h
		) {
	
	if (_is_root(__n))
		__n->_color = _black;
	else
		rebalancing_case2(__n, __h);
}


void _rb_tree_insert_rebalance(
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

};

#endif
