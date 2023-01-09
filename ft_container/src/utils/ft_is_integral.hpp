#ifndef FT_IS_INTEGRAL_H
#define FT_IS_INTEGRAL_H

#include "ft_integral_constant.hpp"

namespace ft {

template <typename T> struct is_integral : public false_type {
};

template <>
struct is_integral<bool> : public true_type {
};

template <>
struct is_integral<char> : public true_type {
};

template <>
struct is_integral<wchar_t> : public true_type {
};

template <>
struct is_integral<signed char> : public true_type {
};

template <>
struct is_integral<short int> : public true_type {
};

template <>
struct is_integral<int> : public true_type {
};

template <>
struct is_integral<long int> : public true_type {
};

template <>
struct is_integral<long long int> : public true_type {
};

template <>
struct is_integral<unsigned char> : public true_type {
};

template <>
struct is_integral<unsigned short int> : public true_type {
};

template <>
struct is_integral<unsigned int> : public true_type {
};

template <>
struct is_integral<unsigned long int> : public true_type {
};

template <>
struct is_integral<unsigned long long int> : public true_type {
};

} // namespace ft
#endif
