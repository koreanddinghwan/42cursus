#ifndef FT_INTEGRAL_CONSTANT_HPP
#define FT_INTEGRAL_CONSTANT_HPP

namespace ft {

template <typename T, T v> struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef ft::integral_constant<T, v> type;
	operator T() { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

}
#endif
