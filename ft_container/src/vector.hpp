#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include "ft_iterator_traits.hpp"
#include "ft_reverse_iterator.hpp"
#include <cstddef>
#include <iterator>
#include <iostream>

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
	    std::cout<<"vector_impl constructed"<<std::endl;
	}
  };

  /*
   * constructor, destructor
   * */
public:
  _Vector_impl _M_impl;
  typedef _Alloc allocator_type;

  _Vector_base(size_t __n, const allocator_type &__a) : _M_impl(__a) {
      std::cout<<"vector_base constructor"<<std::endl;
    this->_M_impl._M_start = this->_M_allocate(__n);
    this->_M_impl._M_finish =
        this->_M_impl._M_start; //_M_finish를 _M_start로 초기화
    this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
  }

  _Vector_base(const allocator_type &__a) : _M_impl(__a) {
      std::cout<<"empty vector base constructed"<<std::endl;
  }

  ~_Vector_base() {
      std::cout<<"vector base destructed"<<std::endl;
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
template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
class vector : protected _Vector_base<_Tp, _Alloc> {

  typedef _Vector_base<_Tp, _Alloc> _Base;
  typedef vector<_Tp, _Alloc> vector_type;

  typedef _Tp value_type;
  typedef typename _Alloc::pointer pointer;
  typedef typename _Alloc::const_pointer const_pointer;
  typedef typename _Alloc::reference reference;
  typedef typename _Alloc::const_reference const_reference;
  /*  
   *  inline __normal_iterator(const __normal_iterator<_Iter, _Container> &__i)
   *  : _M_current(__i.base()) {}
*/
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef typename _Base::allocator_type allocator_type;

protected:
  // protected 상속한 vector_base의 멤버함수 2개와 멤버구조체 변수 M_impl을
  // 가져온다.
  using _Base::_M_allocate;
  using _Base::_M_deallocate;
  using _Base::_M_impl;

public:
  // default constructed allocator로 빈 컨테이너를 생성한다.
  explicit vector(const _Alloc &__a = _Alloc()) : _Base(__a)
  {
      std::cout<<"empty vector container constructed"<<std::endl;
  }

  explicit vector(size_type __n, const _Tp &__v = _Tp(),
                  const _Alloc &__a = _Alloc()) : _Base(__n, __a)
  {
      std::cout<<"fill vector container constructed"<<std::endl;
  }

  explicit vector(size_type count)
  {}

  template <class InputIt>
  vector(InputIt first, InputIt last, const _Alloc &alloc = _Alloc());

  vector(const vector &other){}

  ~vector(){
      std::cout<<"vector destructed"<<std::endl;
  }
};

} // namespace ft

#endif
