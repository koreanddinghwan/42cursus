#ifndef FT_IS_INTEGRAL_H
#define FT_IS_INTEGRAL_H
namespace ft {
template <typename T, T v> struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <typename T> struct is_integral : public false_type {};

} // namespace ft
#endif
