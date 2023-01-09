#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include "../utils/utils.hpp"
#include <algorithm>
#include <cstddef>
#include <cstring>
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
    }
  };

  /*
   * constructor, destructor
   * */
protected:
  _Vector_impl _M_impl;
  typedef _Alloc allocator_type;
  typedef _Tp* pointer;
  typedef const _Tp& const_reference;

  /*
   * important
   * */
  _Vector_base(size_t __n, const allocator_type &__a) : _M_impl(__a) {
    this->_M_impl._M_start = this->_M_allocate(__n);
    this->_M_impl._M_finish =
        this->_M_impl._M_start; //_M_finish를 _M_start로 초기화
    this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
  }

  _Vector_base(const allocator_type &__a) : _M_impl(__a) {
  }

  ~_Vector_base() {
    _M_deallocate(this->_M_impl._M_start,
                  this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
  }

protected:
  _Tp *_M_allocate(size_t __n) { return _M_impl.allocate(__n); }

  void _M_deallocate(_Tp *__p, size_t __n) {
    if (__p)
      _M_impl.deallocate(__p, __n);
  }

  void _M_destroy(_Tp *__p) {
	  if (__p)
	  	this->_M_impl.destroy(__p);
  }

  void _M_construct(pointer __p, const_reference __v){
	  _M_impl.construct(__p, __v);
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
private:  
  typedef _Vector_base<_Tp, _Alloc> _Base;
  typedef vector<_Tp, _Alloc> vector_type;

public: 
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef typename _Base::allocator_type allocator_type;
  typedef _Tp value_type;
  typedef typename _Alloc::pointer pointer;
  typedef typename _Alloc::const_pointer const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef ft::random_access_iterator<_Tp> iterator;
  typedef ft::random_access_iterator<_Tp> const_iterator;
  typedef typename ft::reverse_iterator<iterator> reverse_iterator;
  typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
  template<typename _Integeral>
    void _M_initialize_dispatch(_Integeral __n, _Integeral __v, ft::true_type)
    {
		this->_M_impl._M_start = this->_M_allocate(__n);
		std::fill_n(this->_M_impl._M_start, __n, __v);
		this->_M_impl._M_finish = this->_M_impl._M_start + __n;
		this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
    }

  /*
   *
   * */
  template<typename _It>
    void _M_initialize_dispatch(_It __first, _It __last, ft::false_type)
    {
		size_type _n = __last - __first;
		this->_M_impl._M_start = this->_M_allocate(_n);
		this->_M_impl._M_finish = &(*std::copy(__first, __last, this->begin()));
		this->_M_impl._M_end_of_storage = this->_M_impl._M_finish;
    }

	/*
	 * copy num of __n elements from __first to __last
	 * */
	pointer _M_allocate_copy(const_iterator __first, const_iterator __last, size_type __n) 
	{
		pointer _result = this->_M_allocate(__n);
		this->_M_copy_construct(__first, __last, _result);
		return (_result);
	}

  /*
   * copy from rend to begin + pos
   * and @fill __n number of element with __v
   * */
  void _M_insert_fill(const_iterator __pos, const _Tp &__v, size_type __n) {

	difference_type __pos_d = (__pos - this->begin());

	//reallocation
	if (this->capacity() < this->size() + __n)
	{
		if (this->capacity() * 2 >= this->size() + __n)
			this->reserve(this->capacity() * 2);
		else
			this->reserve(this->size() + __n);
	}
	std::copy_backward(this->begin() + __pos_d, this->end(), this->begin() + __pos_d + __n);
	for (size_type i = 0; i < __n; i++){
		this->_M_construct(this->_M_impl._M_start + __pos_d + i, __v);
	}
	this->_M_impl._M_finish = &(*(this->end() + __n));
  }

  /*
   * @copy from __first to __last to __des
   * */
  template<typename It>
  void _M_copy_construct(It __first, It __last, pointer __dest){
	for (;__first != __last; __first++, __dest++) {
		this->_M_construct(__dest, *(__first));
	}
  }

  /*
   * @param __pos : position to insert start
   * @param __first : value to insert first
   * @param __last : value to insert last
   * */
  template <typename __InputIt>
  void _M_insert_range(const_iterator __pos, __InputIt __first,
                       __InputIt __last) {

    difference_type __n = __last - __first;
	difference_type __pos_d = (__pos - this->begin());
	size_type _old_size = this->size();

	std::cout<<"reserving"<<std::endl;
	if (this->capacity() < _old_size + __n)
	{
		if (this->capacity() * 2 >= _old_size + __n)
			this->reserve(this->capacity() * 2);
		else
			this->reserve(_old_size + __n);
	}
	std::copy_backward(this->begin() + __pos_d, this->end(), this->begin() + __pos_d + __n);
	_M_copy_construct(__first, __last, this->_M_impl._M_start);
	this->_M_impl._M_finish = &(*(this->begin() + _old_size + __n));
  }

  /*
   * if template second, third param is iterator
   * */
  template<typename _It>
	void _M_insert_dispatch(const_iterator __pos, _It __first, _It __last, ft::false_type){
		this->_M_insert_range<_It>(__pos, __first, __last);
	}

  /*
   * if template second, third param is integral
   * */
  template<typename _Integral>
	void _M_insert_dispatch(const_iterator __pos, _Integral __n, const _Tp &__v, ft::true_type) {
		this->_M_insert_fill(__pos, __v, __n);
	}

  /*
   * @param __start : pointer to call destructor
   * @param __n : # of element to call destructor
   * */
  void _M_range_destroy(pointer __start, size_type __n) {
	for (size_type i = 0; i < __n; i++) {
		this->_M_destroy(__start + i);
	}
  }

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
  explicit vector(size_t __n, const _Tp &__v = _Tp(), const _Alloc &__a = _Alloc())
      : _Base(__n, __a) {
    std::fill_n(this->_M_impl._M_start, __n, __v);
	this->_M_impl._M_finish = this->begin() + __n;
  }

  vector(const vector &__x) : _Base(__x.size(), __x.get_allocator()) {
    this->_M_impl._M_finish = std::copy(__x.begin(), __x.end(), this->_M_impl._M_start);
  }

  /*
   * enable_if
   * InputIt 가 is_integral이 false면 아래 생성자 호출되게
   * */
  template <typename _It>
  vector(_It __first, _It __last, const _Alloc &__a = _Alloc())
      : _Base(__a) {
	  typedef typename ft::is_integral<_It>::type _Integral;
	  _M_initialize_dispatch(__first, __last, _Integral());
	  }

  ~vector() {
  }

  /*
   * operator= do not care about capacity
   * */
  vector &operator=(const vector &__x) {
    if (this != &__x) {
		size_type __x_size = __x.size();
		if (__x_size > this->capacity()) {
			size_type __x_size = __x.size();
			iterator __new = _M_allocate_copy(__x.begin(), __x.end(), __x_size);
			this->_M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
			this->_M_impl._M_start = &(*__new);
			this->_M_impl._M_end_of_storage = &(*(__new + __x_size));
		} else {
			std::copy(__x.begin(), __x.end(), this->begin());
		}
		this->_M_impl._M_finish = this->_M_impl._M_start + __x_size;
    }
    return (*this);
  }


	/*
	 * function for interator if _It is iterator type
	 * */
	template<typename _It>
	void _M_assign_dispatch(_It __first, _It __last, ft::false_type) {
		size_type __n = __last - __first;
		this->_M_range_destroy(this->_M_impl._M_start, this->size());

		//reallocation need
		if (this->capacity() < this->size() + __n) {
			pointer _new = this->_M_allocate(__n);

			//deallocate old
			this->_M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
			this->_M_copy_construct(__first, __last, _new);
			this->_M_impl._M_start = _new;
			this->_M_impl._M_finish = _new + __n;
			this->_M_impl._M_end_of_storage = _new + __n;
		} else {
			this->_M_copy_construct(__first, __last, this->_M_impl._M_start);
			this->_M_impl._M_finish = this->_M_impl._M_start + __n;
		}
	}


	template <typename _Integral>
	void _M_assign_dispatch(_Integral __n, _Integral &__v, ft::true_type) {
		this->_M_range_destroy(this->_M_impl._M_start, this->size());
		//reallocation need
		if (this->capacity() < this->size() + __n) {
			pointer _new = this->_M_allocate(__n);

			//deallocate old
			this->_M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
			for (size_type i = 0; i < __n; i++) {
				this->_M_construct(_new + i, __v);
			}
			this->_M_impl._M_start = _new;
			this->_M_impl._M_finish = _new + __n;
			this->_M_impl._M_end_of_storage = _new + __n;
		}//do not need reallocation
		else {
			for (size_type i = 0; i < __n; i++) {
				this->_M_construct(this->_M_impl._M_start + i, __v);
			}
			this->_M_impl._M_finish = this->_M_impl._M_start + __n;
		}
	}


/*
 * assign num of __n elements by __v
 * this function do not have to call any destrcutor or constructors
 * */
	void assign(size_type __n, const _Tp &__v) {
		this->_M_assign_dispatch(__n, __v, true);
	}


	template <typename _It> 
	void assign(_It __first, _It __last) {
		typedef typename ft::is_integral<_It>::type _Integral;
		_M_assign_dispatch(__first, __last, _Integral());
  }

  /*
   * iterators
   * */
public:
  iterator begin() { return (this->_M_impl._M_start); }
  const_iterator begin() const {
    return const_iterator(this->_M_impl._M_start);
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
      return false;
    else
      return true;
  }

  size_type size() const { return static_cast<size_type>(this->_M_impl._M_finish - this->_M_impl._M_start); }
  size_type max_size() const { return static_cast<size_type>(size_type(-1) / sizeof(_Tp)); }
  size_type capacity() const {
    return (size_type(this->_M_impl._M_end_of_storage - this->_M_impl._M_start));
  }

  void reserve(size_type __new_cap) {
    if (!(__new_cap > this->capacity()))
      return;
    if (__new_cap > this->max_size())
      throw std::length_error("std::length error");
    // reallocation
    pointer _new_pointer = this->_M_allocate(__new_cap);
	pointer _to_free = this->_M_impl._M_start;
    size_type _size = this->size();

	_M_copy_construct(this->begin(), this->end(), _new_pointer);
	_M_range_destroy(this->_M_impl._M_start, this->size());
    this->_M_deallocate(_to_free, this->_M_impl._M_end_of_storage - _to_free);
    this->_M_impl._M_start = _new_pointer;
    this->_M_impl._M_finish = _new_pointer + _size;
    this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __new_cap;
  }


  /*
   * resize container to contain __n element
   * 1. this->size() > __n => reduce size to __n
   * 2. this->size() < __c
   * 	2-a : _Alloc으로 채우던가
   * 	2-b : value로 채워라
   * */
  void resize(size_type __n, _Tp __v = _Tp()) {
	if (__n == this->size())
		return ;
    if (__n < this->size())
      erase(begin() + __n, end());
    else
      insert(end(), __n - this->size(), __v);
  }

  /*
   * modifiers
   * */
public:
  void push_back(const value_type &__v) {
	if (this->_M_impl._M_finish == this->_M_impl._M_end_of_storage)
	{
		if (this->capacity() * 2 >= this->size() + 1)
			this->reserve(this->capacity() * 2);
		else
			this->reserve(this->size() + 1);
	}
	this->_M_construct(this->_M_impl._M_finish, __v);
    this->_M_impl._M_finish++;
  }

  void pop_back() { 
	this->_M_destroy(this->_M_impl._M_finish);
	this->_M_impl._M_finish--; 
  }

  /*
   * 0 1 2 3 4 5 6
   * 4 5 1 2 3 4 9
   * insert(5,6) =>
   * 4 5 1 2 3 6 4 9
   * */

  iterator insert(const_iterator __pos, const _Tp &__v) {
	difference_type _d = static_cast<difference_type>(__pos - this->begin());

    this->_M_insert_fill(__pos, __v, 1);
	return (static_cast<iterator>(this->begin() + _d));
  }

  iterator insert(const_iterator __pos, size_type __n, const _Tp &__v) {
	difference_type _d = static_cast<difference_type>(__pos - this->begin());

	this->_M_insert_fill(__pos, __v, __n);
	return (static_cast<iterator>(this->begin() + _d));
  }

  template <class _It>
  iterator insert(const_iterator __pos, _It __first, _It __last) {
	  typedef typename ft::is_integral<_It>::type _Integral;
	difference_type _d = static_cast<difference_type>(__pos - this->begin());

	(_M_insert_dispatch(__pos, __first, __last, _Integral()));
	return (static_cast<iterator>(this->begin() + _d));
  }

  /*
   * |0|1|2|3|4|5|
   * |a|b|c|d|e|f|
   * erase(4)
   * |a|b|c|d|f|
   */
  iterator erase(iterator __pos) {
	typedef typename ft::is_integral<_Tp>::type _Integral;
	size_type __pos_d = __pos - this->begin();
	pointer rtn = &(*(this->begin() + __pos_d));

    if (__pos + 1 == this->end()) {
		this->_M_destroy(this->_M_impl._M_start + __pos_d);
	} else {
		size_type __pos_to_end = this->size() - __pos_d;
		if (!_Integral()) {
			/*
			 * integral type need to call destroy and construct for internal element
			 * */
			this->_M_destroy(this->_M_impl._M_start + __pos_d);
			for (size_type i = 0; i < __pos_to_end; i++) {
				this->_M_construct(this->_M_impl._M_start + __pos_d + i, *(this->_M_impl._M_start + __pos_d + i + 1));
				this->_M_destroy(this->_M_impl._M_start + __pos_d + i + 1);
			}
		} else {
			size_type __pos_to_end = this->size() - __pos_d;
			std::memmove(this->_M_impl._M_start + __pos_d, this->_M_impl._M_start + __pos_d + 1, __pos_to_end);
		}
	}
    --this->_M_impl._M_finish;
    return rtn;
  }

  /* |0|1|2|3|4|5|
   * |a|b|c|d|e|f|
   * erase(2,3)
   * |a|b|d|e|f|
   * */
  iterator erase(iterator __first, iterator __last) {
	typedef typename ft::is_integral<_Tp>::type _Integral;
	size_type __first_d = __first - this->begin();
	size_type __last_d = __last - this->begin();
	size_type __range_d = __last - __first;
	size_type __last_to_end = this->size() - __last_d;
	pointer rtn = &(*(this->begin() + __last_d));

	if (__first == __last)
		return __last;

    if (__last == this->end()) {
		this->_M_range_destroy(this->_M_impl._M_start + __first_d, __range_d);
		/*
		 * return updated end() iterator
		 * */
		rtn = &(*(this->begin() + __first_d + __last_to_end));
	} else {
		if (!_Integral()) {
			/*
			 * integral type need to call destroy and construct for internal element
			 * */
			this->_M_range_destroy(this->_M_impl._M_start + __first_d, __range_d);
			for (size_type i = 0; i < __last_to_end; i++) {
				this->_M_construct(this->_M_impl._M_start + __first_d + i, *(this->_M_impl._M_start + __first_d + __range_d + i));
				this->_M_destroy(this->_M_impl._M_start + __last_d + i); //destroy from __last
			}
		} else {
			std::memmove(this->_M_impl._M_start + __first_d, this->_M_impl._M_start + __last_d, __last_to_end);
		}
	}
    this->_M_impl._M_finish -= __range_d;
	return rtn;
  }

  /* void swap(vector &x) {} */
  void clear() {
	  erase(this->begin(), this->end());
  }
};



template< class _Tp, class _Alloc >
bool operator==( const vector<_Tp,_Alloc>& lhs,
                 const vector<_Tp,_Alloc>& rhs ) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class _Tp, class _Alloc >
bool operator!=( const vector<_Tp,_Alloc>& lhs,
                 const vector<_Tp,_Alloc>& rhs ) {
	return (!(lhs == rhs));
}

template< class _Tp, class _Alloc >
bool operator<( const vector<_Tp,_Alloc>& lhs,
                const vector<_Tp,_Alloc>& rhs ) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class _Tp, class _Alloc >
bool operator<=( const vector<_Tp,_Alloc>& lhs,
                 const vector<_Tp,_Alloc>& rhs ) {
	return !(rhs < lhs);
}

template< class _Tp, class _Alloc >
bool operator>( const vector<_Tp,_Alloc>& lhs,
                const vector<_Tp,_Alloc>& rhs ) {
	return (rhs < lhs);
}

template< class _Tp, class _Alloc >
bool operator>=( const vector<_Tp,_Alloc>& lhs,
                 const vector<_Tp,_Alloc>& rhs ) {
	return !(lhs < rhs);
}





} // namespace ft

#endif
