#ifndef FT_ITERATOR_TRAITS_H
#define FT_ITERATOR_TRAITS_H

#include <cstddef>
#include <iterator>

namespace ft {

template <typename Iterator> class iterator_traits {
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;
};

//템플릿 특수화
template <typename T> class iterator_traits<T *> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};

//템플릿 특수화
template <typename T> class iterator_traits<const T *> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T *pointer;
  typedef const T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};

} // namespace ft

#endif
