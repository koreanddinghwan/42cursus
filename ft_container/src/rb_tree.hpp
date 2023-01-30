#ifndef RB_TREE_HPP
#define RB_TREE_HPP

/*
 * actual implement of red-black tree
 * */

#include "utils/ft_pair.hpp"
#include "utils/ft_reverse_iterator.hpp"
#include "utils/utils.hpp"
#include <cstddef>
#include <iterator>
#include <memory>

namespace ft {

// tree color
enum _rb_tree_color { _red = 0, _black = 1 };

// tree sentinel node
// have only color, parent, left, right
class _rb_tree_sentinel_node {
public:
  typedef _rb_tree_sentinel_node *_node_ptr;
  typedef const _rb_tree_sentinel_node *_const_node_ptr;

  _rb_tree_color _color;
  _node_ptr _parent;
  _node_ptr _left;
  _node_ptr _right;

  // get a minimum node
  static _node_ptr _node_mininum(_node_ptr __n) {
    while (__n && __n->_left) {
      __n = __n->_left;
    }
    return __n;
  }

  static _node_ptr _node_maxinum(_node_ptr __n) {
    while (__n && __n->_right) {
      __n = __n->_right;
    }
    return __n;
  }

  static _const_node_ptr _const_node_mininum(_const_node_ptr __n) {
    while (__n && __n->_left) {
      __n = __n->_left;
    }
    return __n;
  }

  static _const_node_ptr _const_node_maxinum(_const_node_ptr __n) {
    while (__n && __n->_right) {
      __n = __n->_right;
    }
    return __n;
  }
}; // sentinel node end

/* insert */
inline void _rb_tree_insert_rebalance(const bool _insert_left,
                                      _rb_tree_sentinel_node *__n,
                                      _rb_tree_sentinel_node *__p,
                                      _rb_tree_sentinel_node &__h);

/* remove */

// tree node
template <typename _T> class _rb_tree_node : public _rb_tree_sentinel_node {

public:
  _T _value_field;
  typedef _rb_tree_node<_T> *_Link_Type;
}; // tree node end

class _rb_tree_iterator_base {
public:
  typedef _rb_tree_sentinel_node::_node_ptr _ptr;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ptrdiff_t diffrerence_type;

  // member
  _ptr __n;

  void _tree_iterator_increment() {
    if (__n->_right != NULL) {
      __n = __n->_right;
      __n = _rb_tree_sentinel_node::_node_mininum(__n);
    } else {
      //__n이 부모의 왼쪽자식이면 부모 그대로 반환
      //__n이 부모의 오른쪽 자식이면 부모를 left로 가지는 부모의 부모를 타고
      // 올라가서 끝을 반환.
      _rb_tree_sentinel_node *__p = __n->_parent;
      while (__n == __p->_right) {
        __n = __p;
        __p = __p->_parent;
      }
      // stl rbtree의 sentinel node는 left, right, parent가 동일한 노드를
      // 가리킨다.
      if (__n->_right != __p)
        __n = __p;
    }
  }

  void _tree_iterator_decrement() {

    // 현재 노드가 sentinel node인경우, decrement는
    if (__n->_color == _red && __n->_parent->_parent == __n)
      __n = __n->_right;
    else if (__n->_left != NULL) {
      // left에서 right most
      _rb_tree_sentinel_node *__left = __n->_left;
      __left = _rb_tree_sentinel_node::_node_maxinum(__left);
      __n = __left;
    } else {
      _rb_tree_sentinel_node *__p = __n->_parent;
      while (__n == __p->_left) {
        __n = __p;
        __p = __p->_parent;
      }
      __n = __p;
    }
  }
};

template <typename _V, typename _R, typename _P>
class _rb_tree_iterator : public _rb_tree_iterator_base {
  typedef _V value_type;
  typedef _R reference;
  typedef _P pointer;
  typedef _rb_tree_iterator<_V, _V &, _V *> iterator;
  typedef _rb_tree_iterator<_V, const _V &, const _V *> const_iterator;
  typedef _rb_tree_iterator<_V, _R, _R> self;
  typedef _rb_tree_node<_V> *link_type;

  _rb_tree_iterator() {}
  _rb_tree_iterator(link_type __o) { __n = __o; }
  _rb_tree_iterator(iterator __it) { __n = __it.__n; }
  _rb_tree_iterator(const_iterator __it) { __n = __it.__n; }

  reference operator*() const { return link_type(__n)->_value_field; }

  pointer operator->() const { return &(operator*()); }

  self &operator++() {
    _tree_iterator_increment();
    return *this;
  }

  self operator++(int) {
    self tmp = *this;
    _tree_iterator_increment();
    return tmp;
  }

  self &operator--() {
    _tree_iterator_decrement();
    return *this;
  }

  self &operator--(int) {
    self tmp = *this;
    _tree_iterator_decrement();
    return tmp;
  }
};

/*
 * utils
 * */

inline _rb_tree_sentinel_node *
_get_node_grand_parent(_rb_tree_sentinel_node *__n) {
  return (__n->_parent->_parent);
}

inline _rb_tree_sentinel_node *_get_node_uncle(_rb_tree_sentinel_node *__n) {
  // 부모의 오른쪽 자식인 경우,
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
  if (__n->_color == _black && !(__n->_left) && !(__n->_right))
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
inline void _rb_tree_rotate_left(_rb_tree_sentinel_node *const __n,
                                 _rb_tree_sentinel_node *&__root) {

  _rb_tree_sentinel_node *__c = __n->_right;

  //__cl
  __n->_right = __c->_left;
  if (__c->_left != NULL)
    __c->_left->_parent = __n;
  __c->_parent = __n->_parent;

  //__p
  if (__n == __root) // header node specification
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
inline void _rb_tree_rotate_right(_rb_tree_sentinel_node *const __n,
                                  _rb_tree_sentinel_node *&__root) {

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

inline void rebalancing_case1(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h);

// ll, rr case
inline void rebalancing_case5(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h) {
  _rb_tree_sentinel_node *__gp = _get_node_grand_parent(__n);

  __n->_parent->_color = _black;
  __gp->_color = _red;
  if (__n == __n->_parent->_left) // ll case
    _rb_tree_rotate_right(__gp, __h._parent);
  else // rr case
    _rb_tree_rotate_left(__gp, __h._parent);
}

// lr, rl case to ll, rr case
inline void rebalancing_case4(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h) {

  _rb_tree_sentinel_node *__gp = _get_node_grand_parent(__n);

  if ( // lr case to ll case
      __n == __n->_parent->_right && __n->_parent == __gp->_left) {
    _rb_tree_rotate_left(__n->_parent, __h._parent);
    __n = __n->_left; // old parent
  } else if (         // rl case to rr case
      __n == __n->_parent->_left && __n->_parent == __gp->_right) {
    _rb_tree_rotate_right(__n->_parent, __h._parent);
    __n = __n->_right;
  } // ll, rr case and transformed ll, rr case by upper if, else if
  rebalancing_case5(__n, __h);
}

inline void rebalancing_case3(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h) {
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

inline void rebalancing_case2(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h) {
  if (__n->_parent->_color == _black)
    return;
  else
    rebalancing_case3(__n, __h);
}

inline void rebalancing_case1(_rb_tree_sentinel_node *__n,
                              _rb_tree_sentinel_node &__h) {

  if (__n == &(__h))
    __n->_color = _black;
  else
    rebalancing_case2(__n, __h);
}

/*
 * @param _insert_left determine whether insert left or right
 * @param __n node to insert
 * @param __p parent node
 * @param __h header node(end node)
 * */
inline void _rb_tree_insert_rebalance(const bool _insert_left,
                                      _rb_tree_sentinel_node *__n,
                                      _rb_tree_sentinel_node *__p,
                                      _rb_tree_sentinel_node &__h) {

  // 삽입 노드 초기화
  __n->_color = _red;
  __n->_left = NULL;
  __n->_right = NULL;
  __n->_parent = __p;

  if (_insert_left) {
    __p->_left = __n;

    // 삽입된 노드가 맨 처음 노드라면 header node의 모든 포인터가 자신을
    // 가리키도록
    if (__p == &__h) {
      __h._parent = __n;
      __h._right = __n;
    }
    // 삽입된 노드가 가장 왼쪽노드라면 해당 포인터를 header노드에서 유지
    else if (__p == __h._left)
      __h._left = __n;
  } else {
    __p->_right = __n;

    if (__p == __h._right)
      __h._right = __n;
  }

  // rebalancing
  rebalancing_case1(__n, __h);
}

/*
 * @param __n : node to delete
 * @param __header : header node
 * case1 : delete node with 2 child => copy left subtree's rightmost || right
 * subtree's leftmost
 *
 * case2 : delete node who have only left child
 * case3 : delete node who have only right child
 * */
inline void _rb_tree_erase_rebalancing(_rb_tree_sentinel_node *const __z,
                                       _rb_tree_sentinel_node &__header) {
  _rb_tree_sentinel_node *&__root = __header._parent;
  _rb_tree_sentinel_node *&__leftmost = __header._left;
  _rb_tree_sentinel_node *&__rightmost = __header._right;
  _rb_tree_sentinel_node *__y = __z;
  _rb_tree_sentinel_node *__x = NULL;
  _rb_tree_sentinel_node *__x_parent = NULL;

  //////////prerequisite
  if (__y->_left == NULL)       //__z at most one non-null child, __y == __z
    __x = __y->_right;          //__x might be null
  else if (__y->_right == NULL) //__z have exact one child, __y == __z
    __x = __y->_left;           //__x is not null
  else {                        //__z has two non-null child
    __y = __y->_right;
    while (__y->_left != NULL) {
      __y = __y->_left;
    }
    __x = __y->_right;
  }

  ///////////////
  if (__y != __z) { //=> z has two non-null child
                    // relink __z(deleted node) with childs
    __z->_left->_parent = __y;
    __y->_left = __z->_parent;
    // if __y is exact child of __z
    if (__y != __z->_right) {
      __x->_parent = __y->_parent;
      if (__x) //_x might be null
        __x->_parent = __y->_parent;
      __y->_parent->_left = __x;  // update __y parent
      __y->_right = __z->_right;  // update __y's right child link
      __z->_right->_parent = __y; //
    } else                        //__y is not child of __z
      __x_parent = __y;
    if (__root == __z) // update root
      __root = __y;
    else if (__z->_parent->_left == __z) // update left child of __z's parent
      __z->_parent->_left = __y;
    else // update right child of __z's parent
      __z->_parent->_right = __y;
    __y->_parent = __z->_parent;
    std::swap(__y->_color, __z->_color);
    __y = __z;
  } else {                       //=> z has at most one non-null child
    __x->_parent = __y->_parent; //__y == __z
    if (__x)                     //__x might be null
      __x->_parent = __y->_parent;
    if (__root == __z) // update root
      __root = __x;
    else if (__z->_parent->_left == __z) // update __z parent's link
      __z->_parent->_left = __x;
    else
      __z->_parent->_right = __x;
    if (__leftmost == __z) // if __z == leftmost
    {
      if (__z->_right == NULL) // if __x is null, left most is __z's parent
        __leftmost = __z->_parent;
      else // else, __x's leftmost
        __leftmost = _rb_tree_sentinel_node::_node_mininum(__x);
    }
    if (__rightmost == __z) { //__z == rightmost
      if (__z->_left == NULL) {
        __rightmost = __z->_parent;
      } else {
        __rightmost = _rb_tree_sentinel_node::_node_maxinum(__x);
      }
    }
  }
  if (__y->_color != _red) {
    while () {
    }

    if (__x)
      __x->_color = _black;
  }
  return __y;
}

template <typename _Key, typename _Value,
          typename _KeyOfValue, // if map-> select1st, set-> identity
          typename _Compare, typename _Alloc = std::allocator<_Value>>
class _RB_tree {

  // binding allocator with node_allocator
  typedef typename _Alloc::template rebind<_rb_tree_node<_Value>>::other
      node_allocator;

public:
  typedef _Key key_type;
  typedef _Value value_type;
  typedef _Compare compare_type;
  typedef _Alloc allocator_type;

  typedef value_type *pointer;
  typedef const value_type *const_pointer;
  typedef value_type &reference;
  typedef const value_type &const_reference;

  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  // iterators
  typedef _rb_tree_iterator<_Value, reference, pointer> iterator;
  typedef _rb_tree_iterator<_Value, const_reference, const_pointer>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

protected:
  typedef _rb_tree_sentinel_node *_ptr;
  typedef const _rb_tree_sentinel_node *_const_ptr;
  typedef _rb_tree_node<_Value> _rb_tree_node;

private:
  typedef _rb_tree_sentinel_node::_node_ptr node_ptr;
  typedef _rb_tree_sentinel_node::_const_node_ptr const_node_ptr;
  typedef _rb_tree_node *Link_Type;
  typedef const _rb_tree_node *Const_Link_Type;

public:
  // get allocator of node, not _Alloc<_Val>
  allocator_type get_allocator() const {
    return *(static_cast<const node_allocator>(&this->_M_impl));
  }

protected:
  /*
   * implementation of internal rb_tree
   * @param _Key_Compare equals to _Compare function object
   */
  template <typename _Key_Compare> class _RB_tree_impl : public node_allocator {
    // key compare
    _Key_Compare _M_key_cmp;
    // header node
    _rb_tree_sentinel_node _M_header;
    // maintain node counts
    size_type _M_node_cnt;

    // constructor
    _RB_tree_impl(const node_allocator &__a = node_allocator(),
                  const _Key_Compare &__cmp = _Key_Compare())
        : node_allocator(__a), _M_key_cmp(__cmp), _M_node_cnt(0) {
      this->_M_header._color = _red;
      this->_M_header._parent = NULL;           // header's parent is begin
      this->_M_header._left = &this->_M_header; // maintain leftmost
      this->_M_header._right = &this->_M_header;
    }
  };

  _RB_tree_impl<_Compare> _M_impl;

protected:
  /*
   * internal methods
   * */

  Link_Type _M_get_node() { return this->_M_impl.node_allocator::allocate(1); }

  void _M_put_node(Link_Type p) {
    this->_M_impl.node_allocator::deallocate(p, 1);
  }

  Link_Type _M_create_node(const value_type &__v) {
    Link_Type tmp = _M_get_node();
    try {
      this->get_allocator().construct(&tmp->_value_field, __v);
    } catch (...) {
      this->_M_put_node(tmp);
      throw;
    }
    return tmp;
  }

  Link_Type _M_clone_node(Const_Link_Type __o) {
    Link_Type tmp = this->_M_create_node(__o->_value_field);
    tmp->_color = __o->_color;
    tmp->_left = NULL;
    tmp->_right = NULL;
    return tmp;
  }

  // call destructors
  void destroy_node(Link_Type __o) {
    get_allocator().destroy(&__o->_value_field);
    _M_put_node(__o);
  }

  /*
   * return first node
   * if empty, return null
   */
  node_ptr _M_root() { return this->_M_impl._M_header._parent; }

  node_ptr _M_leftmost() { return this->_M_impl._M_header._left; }

  node_ptr _M_rightmost() { return this->_M_impl._M_header._right; }

  // return header's parent == begin(root)
  Link_Type _M_begin() {
    return static_cast<Link_Type>(this->_M_impl._M_header._parent);
  }

  // return header node
  Link_Type _M_end() { return static_cast<Link_Type>(this->_M_impl._M_header); }

  // get node's value reference
  // const link type-> _RB_tree_node<_Tp>*
  static const_reference _S_value(Const_Link_Type __n) {
    return __n->_value_field;
  }
  static const_reference _S_value(_const_ptr __n) {
    return static_cast<Const_Link_Type>(__n)->_value_fieldl;
  }

  // get node's key
  static const _Key &_S_key(Const_Link_Type __n) {
    return _KeyOfValue()(_S_value(__n));
  }
  // get node's key
  static const _Key &_S_key(_ptr __n) { return _KeyOfValue()(_S_value(__n)); }

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

  static _ptr _S_minimum(_ptr __n) {
    return _rb_tree_sentinel_node::_node_mininum(__n);
  }
  static _const_ptr _S_minimum(_const_ptr __n) {
    return _rb_tree_sentinel_node::_const_node_mininum(__n);
  }

  static _ptr _S_maximum(_ptr __n) {
    return _rb_tree_sentinel_node::_node_maxinum(__n);
  }
  static _const_ptr _S_maximum(_const_ptr __n) {
    return _rb_tree_sentinel_node::_const_node_maxinum(__n);
  }

public:
  _RB_tree() {}
  _RB_tree(const _Compare &__cmp, const allocator_type &__a)
      : _M_impl(__a, __cmp) {}
  _RB_tree(const _Compare &__cmp) : _M_impl(allocator_type(), __cmp) {}
  _RB_tree(const _RB_tree<_Key, _Value, _KeyOfValue, _Compare> &__o)
      : _M_impl(__o.get_allocator(), __o._M_impl._M_key_cmp) {
    if (__o._M_root() != NULL) {
      // copy
    }
  }

  ~_RB_tree() {
    // erase
  }

  // iterators : bidirectional_iterator,
  iterator begin() { return static_cast<Link_Type>(this->_M_impl._M_left); }
  const_iterator begin() const {
    return static_cast<Const_Link_Type>(this->_M_impl._M_left);
  }

  iterator end() { return static_cast<Link_Type>(this->_M_impl._M_right); }
  const_iterator end() const {
    return static_cast<Const_Link_Type>(this->_M_impl._M_right);
  }

  reverse_iterator rbegin() { return reverse_iterator(this->end()); }
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(this->end());
  }

  reverse_iterator rend() { return reverse_iterator(this->begin()); }

  // interface methods
  size_type size() const { return (this->_M_impl._M_node_cnt); }
  size_type max_size() const { return size_type(-1); }

  size_type count(const _Key &__v) const {
    size_type cnt = 0;

    iterator __begin = this->begin();
    iterator __end = this->end();

    for (; __begin != __end; __begin++) {
      if (this->_M_impl._KeyOfValue()(__v) == _S_key(*__begin)) {
        cnt++;
        break;
      }
    }
    return cnt;
  }

  /*
   * create node by __v and insert
   *@param __n node
   *@param __p position to insert node
   *@param __v value to insert
   * */
  typename _RB_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
  _M_insert(_ptr __n, _ptr __p, const _Value &__v) {
    bool __insert_left =
        (__n != NULL              // first arg == not null
         || __p == this->_M_end() // header node
         || this->_M_impl._M_key_cmp(_KeyOfValue()(__v),
                                     _S_key(__p))); // key of __v < key of __p

    Link_Type __new = this->_M_create_node(__v);
    _rb_tree_insert_rebalance(__insert_left, __new, __p,
                              this->_M_impl._M_header);
    this->_M_impl._M_node_cnt++;
    return iterator(__new);
  }

  /*
   * @param __v value to insert
   * @return value : iterator-> inserted
   * */
  ft::pair<
      typename _RB_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator,
      bool>
  insert_unique(const _Value &__v) {
    Link_Type __a = this->_M_begin();
    Link_Type __b = this->_M_end();
    bool comp = true;

    // find position to insert __v
    // if key of __v < key of __a => comp true
    // else false
    // then, __a is updated to left node if true, otherwise, right node
    // until __a is to be nil node
    while (__a != NULL) {
      __b = __a;
      comp = this->_M_impl._M_key_cmp(_KeyOfValue()(__v),
                                      _S_key(__a)); // key of __v < key of __a;
      __a = comp ? _S_left(__a) : _S_right(__a);
    }
    //__a is node to insert. and NULL
    //__b is __a's parent

    iterator __p = iterator(__b);
    if (comp) // comp true means that found exact position at last without key
              // of __v >= key of __a;
    {
      // if upper while statement only looped once -> normally insert
      if (__p == begin())
        return ft::pair<iterator, bool>(_M_insert(__a, __b, __v), true);
      else
        --__b;
    }
    if (this->_M_impl._M_key_cmp(_S_key(__p.__n), _KeyOfValue()(__v)))
      return ft::pair<iterator, bool>(_M_insert(__a, __b, __v), true);
    // insert falled
    return ft::pair<iterator, bool>(__p, false);
  }

  typename _RB_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
  insert_unique(iterator __pos, const _Value &__v) {

    // case 1: __pos == header pos
    if (__pos.__n == this->_M_end()) {
      // case 1-1:  inserted position is rightmost
      if (this->size() > 0 &&
          this->_M_impl._M_key_cmp(_S_key(_M_rightmost(), _KeyOfValue()(__v))))
        return _M_insert(0, _M_rightmost(), __v);
      else
        // case 1-2 : inserted position is have to be find
        return insert_unique(__v).first;

      // case 2 : key of  __v < key of __pos
    } else if (this->_M_impl._M_key_cmp(_KeyOfValue()(__v),
                                        _S_key(__pos.__n))) {
      iterator __b = iterator(__pos);
      // case 2-1 : pos is leftmost, simply insert in leftmost
      if (__pos.__n == this->_M_leftmost())
        return _M_insert(this->_M_leftmost(), this->_M_leftmost(), __v);
      // case 2-2 : key of __b < key of __v < __pos =>
      else if (this->_M_impl._M_key_cmp(_S_key(--__b.__n),
                                        _KeyOfValue()(__v))) {
        // simply insert in right
        if (_S_right(__b.__n) == NULL)
          return _M_insert(NULL, __b.__n, __v);
        else // insert into __pos
          return _M_insert(__pos.__n, __pos.__n, __v);
      } else // case 2-3 : key of __b >= key of __v < __pos
        return insert_unique(__v).first;

      // case 3 key of __pos < key of __v
    } else if (this->_M_impl._M_key_cmp(_S_key(__pos.__n),
                                        _KeyOfValue()(__v))) {
      iterator __a = iterator(__pos);
      // case 3-1 __pos == rightmost
      if (__pos.__n == this->_M_rightmost())
        return _M_insert(NULL, _M_rightmost(), __v);
      // case 3-2 __pos < __v < __a
      else if (this->_M_impl._M_key_cmp(_KeyOfValue()(__v),
                                        _S_key((++__a).__n))) {
        if (_S_right(__pos.__n) == NULL)
          return _M_insert(NULL, __pos.__n, __v);
        else
          return _M_insert(__a.__n, __a.__n, __v);
      } else
        return insert_unique(__v).first;
    } else // case 4, key of __pos == key of __v
           // not insert
      return __pos;
  }

  template <typename _It> void insert_unique(_It first, _It last) {
    for (; first != last; first++) {
      insert_unique(*first);
    }
  }

  // boundary
  iterator upper_bound(const _Key &__k) {
    Link_Type __a = this->_M_begin();
    Link_Type __b = this->_M_end(); // returning node that greater than _k

    while (__a != NULL) {
      if (this->_M_impl._M_key_cmp(__k, _S_key(__a))) {
        __b = __a;
        __a = _S_left(__a);
      } else
        __a = _S_right(__a);
    }
    return iterator(__b);
  }

  const_iterator upper_bound(const _Key &__k) const {
    Const_Link_Type __a = this->_M_begin();
    Const_Link_Type __b = this->_M_end();

    while (__a != NULL) {
      if (this->_M_impl._M_key_cmp(__k, _S_key(__a))) {
        __b = __a;
        __a = _S_left(__a);
      } else
        __a = _S_right(__a);
    }
    return const_iterator(__b);
  }

  iterator lower_bound(const _Key &__k) {
    Link_Type __a = this->_M_begin();
    Link_Type __b = this->_M_end(); // returning node that is not less than _k

    while (__a != NULL) {
      //__a >= __k
      if (!this->_M_impl._M_key_cmp(_S_key(__a), __k)) {
        __b = __a;
        __a = _S_left(__a);
      } else
        __a = _S_right(__a);
    }
    return iterator(__b);
  }

  const_iterator lower_bound(const _Key &__k) const {
    Const_Link_Type __a = this->_M_begin();
    Const_Link_Type __b = this->_M_end();

    while (__a != NULL) {
      //__a >= __k
      if (!this->_M_impl._M_key_cmp(_S_key(__a), __k)) {
        __b = __a;
        __a = _S_left(__a);
      } else
        __a = _S_right(__a);
    }
    return const_iterator(__b);
  }

  inline ft::pair<iterator, iterator> equal_range(const _Key &__k) {
    return ft::pair<iterator, iterator>(lower_bound(__k), upper_bound(__k));
  }
  inline ft::pair<const_iterator, const_iterator>
  equal_range(const _Key &__k) const {
    return ft::pair<const_iterator, const_iterator>(lower_bound(__k),
                                                    upper_bound(__k));
  }

}; // class _RB_tree

}; // namespace ft

#endif
