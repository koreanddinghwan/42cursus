#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include "ft_iterator_traits.h"
#include "ft_reverse_iterator.h"
#include <cstddef>
#include <iterator>

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
     * struct constructor
     * */
    _Vector_impl(_Alloc const &__a)
        : _Alloc(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
  };

public:
  typedef _Alloc allocator_type;

  _Vector_base(size_t __n, const allocator_type &__a) : _M_impl(__a) {
    this->_M_impl._M_start = this->_M_allocate(__n);
    this->_M_impl._M_finish = this->_M_impl._M_start;
    this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
  }

  _Vector_base(const allocator_type &__a) : _M_impl(__a) {}

  ~_Vector_base() {
    _M_deallocate(this->_M_impl._M_start,
                  this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
  }

public:
  _Vector_impl _M_impl;

  _Tp *_M_allocate(size_t __n) { return _M_impl.allocate(__n); }
  void _M_deallocate(_Tp *__p, size_t __n) {
    if (__p)
      _M_impl.deallocate(__p, __n);
  }

  //_M_impl 의 부모클래스 _Alloc으로 업캐스팅해서 allocator를 리턴한다.
  allocator_type get_allocator() const {
    return *static_cast<const _Alloc *>(&this->_M_impl);
  }
};

// vector 클래스는 _Vector_base를 protected 상속
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
class vector : protected _Vector_base<_Tp, _Alloc> {

  typedef _Tp value_type;
  typedef _Alloc allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef std::iterator<std::random_access_iterator_tag, _Tp> iterator;
  typedef std::iterator<std::random_access_iterator_tag, _Tp> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef
      typename ft::iterator_traits<iterator>::difference_type difference_type;
  typedef std::size_t size_type;

public:
  vector();

  explicit vector(const _Alloc &alloc);

  explicit vector(size_type count, const _Tp &value = _Tp(),
                  const _Alloc &alloc = _Alloc());

  explicit vector(size_type count);

  template <class InputIt>
  vector(InputIt first, InputIt last, const _Alloc &alloc = _Alloc());

  vector(const vector &other);

  ~vector();
};
} // namespace ft

#endif
