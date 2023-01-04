#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"
#include "ft_iterator_traits.hpp"
#include "ft_reverse_iterator.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>

// std::vector는 sequence design pattern의 예시이다.
//
namespace ft {

// vector의 멤버 변수를 가지는 vector_base
// NVI pattern의 예시. allocate, deallocate 함수를 매핑하는 _M_deallocate,
// _M_allocate함수를 정의한다. 내부적으로만 사용
template <typename _Tp, typename _Alloc> struct _Vector_base {
  // vector_base의 data member 가지는 Vector_impl 정의
  // Alloc을 상속해 allocate, deallocate를 사용할 수 있다.
  struct _Vector_impl : public _Alloc {
    _Tp *_M_start;
    _Tp *_M_finish;
    _Tp *_M_end_of_storage;
    /*
     * constructor
     * */
    _Vector_impl(_Alloc const &__a)
        : _Alloc(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0) {
      std::cout << "vector_impl constructed" << std::endl;
    }
  };

  /*
   * constructor, destructor
   * */
public:
  _Vector_impl _M_impl;
  typedef _Alloc allocator_type;

  _Vector_base(size_t __n, const allocator_type &__a) : _M_impl(__a) {
    std::cout << "vector_base constructor" << std::endl;
    this->_M_impl._M_start = this->_M_allocate(__n);
    this->_M_impl._M_finish =
        this->_M_impl._M_start; //_M_finish를 _M_start로 초기화
    this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
  }

  _Vector_base(const allocator_type &__a) : _M_impl(__a) {
    std::cout << "empty vector base constructed" << std::endl;
  }

  ~_Vector_base() {
    std::cout << "vector base destructed" << std::endl;
    _M_deallocate(this->_M_impl._M_start,
                  this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
  }

public:
  _Tp *_M_allocate(size_t __n) { return _M_impl.allocate(__n); }

  void _M_deallocate(_Tp *__p, size_t __n) {
    if (__p)
      _M_impl.deallocate(__p, __n);
  }

  //_M_impl 의 부모클래스 _Alloc으로 업캐스팅해서 allocator를 리턴한다.
  allocator_type get_allocator() const {
    return *static_cast<const _Alloc *>(&this->_M_impl);
  }
}; // vector_base end

/* vector 클래스는 _Vector_base를 protected 상속
 * 인자로 받은 std::allocator를 vector_base의 template인자로 넘긴다.
 */
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
class vector : protected _Vector_base<_Tp, _Alloc> {

  typedef _Vector_base<_Tp, _Alloc> _Base;
  typedef vector<_Tp, _Alloc> vector_type;

  typedef _Tp value_type;
  typedef typename _Alloc::pointer pointer;
  typedef typename _Alloc::const_pointer const_pointer;
  typedef typename _Alloc::reference reference;
  typedef typename _Alloc::const_reference const_reference;
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef typename _Base::allocator_type allocator_type;

  /*
   * constructors and destructor
   * */
public:
  // default constructed allocator로 빈 컨테이너를 생성한다.
  explicit vector(const _Alloc &__a = _Alloc()) : _Base(__a) {}

  /*
   * @param __n : initial container size
   * @param __v : value to fill container with
   * */
  vector(size_t __n, const _Tp &__v, const _Alloc &__a = _Alloc())
      : _Base(__n, __a) {
    std::uninitialized_fill_n(this->_M_impl._M_start, __n, __v, __a);
  }

  vector(const vector &__x) : _Base(__x.size(), __x.get_allocator()) {
    this->_M_impl._M_finish =
        std::uninitialized_copy(__x.begin(), __x.end(), this->_M_impl._M_start);
  }

  /*
   * enable_if
   * InputIt 가 is_integral이 false면 아래 생성자 호출되게
   * */
  template <
      typename InputIt,
      typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type>
  vector(InputIt __first, InputIt __last, const _Alloc &__a = _Alloc())
      : _Base(__a) {
    std::uninitialized_copy(__first, __last, this->_M_impl._M_start);
  }

  /*!!!!*/
  ~vector() { this->_M_deallocate(); }

  /*!!!!*/
  vector &operator=(const vector &__x) {
    if (this != __x) {
    }
    return (*this);
  }

  /*
   * iterators
   * */
public:
  iterator begin() { return iterator(this->_M_impl._M_start); }
  const_iterator begin() const {
    return const_iterator(this->_M_impl._M_finish);
  }

  iterator end() { return iterator(this->_M_impl._M_finish); }
  const_iterator end() const { return const_iterator(this->_M_impl._M_finish); }

  reverse_iterator rbegin() {
    return reverse_iterator(this->_M_impl._M_finish);
  }
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(this->_M_impl._M_finish);
  }

  reverse_iterator rend() { return reverse_iterator(this->_M_impl._M_start); }
  const_reverse_iterator rend() const {
    return const_reverse_iterator(this->_M_impl._M_start);
  }

  /*
   * Element access
   * */
protected:
  void _M_out_of_range_check(size_type __pos) {
    if (__pos >= this->size())
      throw std::out_of_range("vector::_M_range_check");
  }

public:
  reference at(size_type __pos) {
    _M_out_of_range_check(__pos);
    return (this->_M_impl._M_start[__pos]);
  }
  const_reference at(size_type __pos) const {
    _M_out_of_range_check(__pos);
    return (this->_M_impl._M_start[__pos]);
  }

  reference operator[](size_type __pos) {
    return *(this->_M_impl._M_start + __pos);
  }
  const_reference operator[](size_type __pos) const {
    return *(this->_M_impl._M_start + __pos);
  }

  reference front() { return *(this->_M_impl._M_start); }
  const_reference front() const { return *(this->_M_impl._M_start); }

  reference back() { return *(this->_M_impl._M_finish - 1); }
  const_reference back() const { return *(this->_M_impl._M_finish - 1); }

  _Tp *data() { return (this->begin()); }
  const _Tp *data() const { return (this->begin()); }

  /*
   * capacity
   * */
public:
  bool empty() const {
    if (this->size())
      return true;
    else
      return false;
  }

  size_type size() const { return (this->end() - this->begin()); }
  size_type max_size() const { return (size_type(-1) / sizeof(_Tp)); }
  size_type capacity() const {
    return (size_type(this->_M_impl._M_end_of_storage - this->begin()));
  }

  void reserve(size_type new_cap) {
    if (!(new_cap > this->capacity()))
      return;
    if (new_cap > this->max_size())
      throw std::length_error("std::length error");
    // reallocation
    pointer _new_pointer = this->_M_allocate(new_cap);
    pointer _invalid_first = this->begin();
    size_type _size = this->size();
    std::uninitialized_copy_n(_invalid_first, this->size(), _new_pointer);
    this->_M_deallocate(_invalid_first, this->_M_impl._M_end_of_storage -
                                            this->_M_impl._M_start);
    this->_M_impl._M_start = _new_pointer;
    this->_M_impl._M_finish = _new_pointer + _size;
    this->_M_impl._M_end_of_storage = _new_pointer + new_cap;
  }
};

} // namespace ft

#endif
