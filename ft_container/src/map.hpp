#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/ft_pair.hpp"
#include "rb_tree.hpp"
#include "utils/ft_function.hpp"
#include <__functional/binary_function.h>
#include <cstddef>
#include <memory>
#include <stdexcept>

namespace ft {

/*
 * unique key를 가지는 key-value pari를 가지는 정렬된 컨테이너.
 * key는 __Compare함수를 통해 정렬된다.
 * Search, removal, insertion 연산은 로그 시간 복잡도를 가진다.
 * 일반적으로 rb tree를 통해 구현된다.
 * */
template <typename __Key, typename __Tp, typename __Compare = std::less<__Key>,
          typename __Alloc = std::allocator<ft::pair<const __Key, __Tp>>>
class map {

public:
  typedef __Key key_type;
  typedef __Tp mapped_type;
  typedef __Compare key_compare;
  typedef ft::pair<const __Key, __Tp> value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef typename __Alloc::pointer pointer;
  typedef typename __Alloc::const_pointer const_pointer;
  typedef typename __Alloc::reference reference;
  typedef typename __Alloc::const_reference const_reference;

  /*
   * iterator uses RBtree iterators
   * */

  /*
   * member class
   * value_compare : function object
   * */
  class value_compare : std::binary_function<value_type, value_type, bool> {
    friend class map<__Key, __Tp, __Compare, __Alloc>;

  protected:
    /*
     * function object
     * */
    __Compare _comp;
    value_compare(__Compare c) : _comp(c) {}

  public:
    bool operator()(const value_type &_lhs, const value_type &_rhs) {
      return (this->_comp(_lhs.first, _rhs.first));
    }
  };

private:
  // adapt _RB_tree <----> map
  typedef _RB_tree<__Key, __Tp, _Select1st<__Tp>, __Compare> _Rb_Tree_Type;
  _Rb_Tree_Type _M_tree;

public:
  typedef typename _Rb_Tree_Type::allocator_type allocator_type;
  typedef typename _Rb_Tree_Type::iterator iterator;
  typedef typename _Rb_Tree_Type::const_iterator const_iterator;
  typedef typename _Rb_Tree_Type::reverse_iterator reverse_iterator;
  typedef typename _Rb_Tree_Type::const_reverse_iterator const_reverse_iterator;

public:
  // construct empty container
  map(void) : _M_tree(__Compare(), allocator_type()) {}

  // construct empty container
  explicit map(const __Compare &comp, const __Alloc &alloc = __Alloc())
      : _M_tree(comp, alloc) {}

  // construct with contents of range [first, last)
  // 동일한 원소가 first, last사이에 있다면, 어떤 원소가 삽입될 지 정의되지
  // 않는다.
  template <typename __It>
  map(__It first, __It last, const __Compare &comp = __Compare(),
      const __Alloc &alloc = __Alloc())
      : _M_tree(__Compare(), allocator_type()) {
    _M_tree.insert_unique(first, last);
  }

  // copy construct, other container의 내용의 복사로 컨테이너를 만든다.
  map(const map &__o) : _M_tree(__o._M_tree) {}

  // 원소의 소멸자를 호출하며 사용된 storaged도 deallocate한다.
  // pointer라면, pointed된 object는 destroy되지 않는다.
  ~map() { ~_M_tree(); }

  // other의 content의 복사를 통해 content를 교체한다.
  map &operator=(const map &__o) {
    this->_M_tree = __o._M_tree;
    return *this;
  }

  allocator_type get_allocator() const { return this->_M_tree.get_allocator(); }

  // key에 있는 값과 동일한 key를 가진 원소의 value를 가져온다.
  // 없다면 std::out_of_range exception throw
  __Tp &at(const __Key &__k) {
    iterator f = this->_M_tree.find(__k);
    if (f == this->_M_tree.end())
      throw std::out_of_range("out of range");
    else
      return ft::_RB_tree<__Key, __Tp, __Key, __Compare, __Alloc>::_S_value(f);
  }
};
} // namespace ft
#endif
