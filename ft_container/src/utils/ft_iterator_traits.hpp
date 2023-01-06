#ifndef FT_ITERATOR_TRAITS_H
#define FT_ITERATOR_TRAITS_H

#include <cstddef>
#include <iterator>

namespace ft {

template <class _Iter> 
struct iterator_traits {
  typedef typename _Iter::difference_type difference_type;
  typedef typename _Iter::value_type value_type;
  typedef typename _Iter::pointer pointer;
  typedef typename _Iter::reference reference;
  typedef typename _Iter::iterator_category iterator_category;
};

//템플릿 특수화
template <class _Tp> 
struct iterator_traits<_Tp *> {
  typedef ptrdiff_t difference_type;
  typedef _Tp value_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

//템플릿 특수화
template <class _Tp> 
struct iterator_traits<const _Tp *> {
  typedef ptrdiff_t difference_type;
  typedef _Tp value_type;
  typedef const _Tp* pointer;
  typedef const _Tp& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

} // namespace ft

#endif
