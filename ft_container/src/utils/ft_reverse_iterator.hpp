#ifndef FT_REVERSE_ITERATOR_H
#define FT_REVERSE_ITERATOR_H

#include "ft_iterator_traits.hpp"
#include <iterator>

namespace ft {

// member type들은 std::iterator에서 상속
template <typename Iter>
class reverse_iterator
    : public std::iterator<
          typename std::iterator_traits<Iter>::iterator_category,
          typename std::iterator_traits<Iter>::value_type,
          typename std::iterator_traits<Iter>::difference_type,
          typename std::iterator_traits<Iter>::pointer,
          typename std::iterator_traits<Iter>::reference> {
protected:
  Iter _current;

public:
  typedef Iter iterator_type;
  typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
  typedef typename ft::iterator_traits<Iter>::pointer pointer;
  typedef typename ft::iterator_traits<Iter>::reference reference;

public:
  // constructors
  //  _current()로 초기화
  reverse_iterator() : _current() {}
  // copy constructor
  reverse_iterator(const reverse_iterator &__x) : _current(__x._current) {}
  // x를 통해 초기화
  explicit reverse_iterator(iterator_type __x) : _current(__x) {}
  // other를 통해 초기화
  template <typename _Iter>
  reverse_iterator(const reverse_iterator<_Iter> &__other)
      : _current(__other.base()) {}

public:
  //현재 위치 리턴
  iterator_type base() const { return _current; }

  template <class _Iter>
  reverse_iterator &operator=(const reverse_iterator<_Iter> &__x) {
    _current = __x.base();
    return *this;
  }

  reference operator*() const {
    Iter tmp = _current;
    return *--tmp;
  }
  pointer operator->() const { return std::addressof(operator*()); }

  reverse_iterator &operator++() {
    _current--;
    return *this;
  }
  reverse_iterator &operator--() {
    _current++;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator __tmp = *this;
    --_current;
    return __tmp;
  }
  reverse_iterator operator--(int) {
    reverse_iterator __tmp = *this;
    ++_current;
    return __tmp;
  }
  reverse_iterator operator+(difference_type __n) const {
    return (reverse_iterator(base() - __n));
  }
  reverse_iterator operator-(difference_type __n) const {
    return (reverse_iterator(base() + __n));
  }

  reverse_iterator &operator+=(difference_type __n) {
    _current -= __n;
    return (*this);
  }
  reverse_iterator &operator-=(difference_type __n) {
    _current += __n;
    return (*this);
  }

  reference operator[](difference_type __n) const { return base()[-__n - 1]; }
};
template <class Iterator1, class Iterator2>
bool operator==(const std::reverse_iterator<Iterator1> &lhs,
                const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const std::reverse_iterator<Iterator1> &lhs,
                const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const std::reverse_iterator<Iterator1> &lhs,
               const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const std::reverse_iterator<Iterator1> &lhs,
                const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const std::reverse_iterator<Iterator1> &lhs,
               const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const std::reverse_iterator<Iterator1> &lhs,
                const std::reverse_iterator<Iterator2> &rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iter>
reverse_iterator<Iter>
operator+(typename reverse_iterator<Iter>::difference_type __n,
          const reverse_iterator<Iter> &it) {
  return reverse_iterator<Iter>(it.base() - __n);
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type
operator-(const reverse_iterator<Iterator1> &lhs,
          const reverse_iterator<Iterator2> &rhs) {
  return (rhs.base() - lhs.base());
}

} // namespace ft
#endif
