#ifndef FT_PAIR_H
#define FT_PAIR_H

namespace ft {

template <typename T1, typename T2> struct pair {
  typedef T1 first_type;
  typedef T2 second_type;
  T1 first;
  T2 second;

  //해당 type으로 value initialization
  pair() : first(T1()), second(T2()) {}

  // const 생성자
  pair(const T1 &a, const T2 &b) : first(a), second(b) {}

  //복사생성자
  template <typename U, typename V>
  pair(const pair<U, V> &p) : first(p.first), second(p.second){};
};

// inline functions -> compiler preprocessor's
template <typename T1, typename T2>
inline bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return (x.first == y.first && x.second == y.second);
}

// Use == operator
template <typename T1, typename T2>
inline bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return !(x == y);
}

// lexicographical_compare
// x(1,5), y(1,6)
template <typename T1, typename T2>
inline bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
}

// use < operator
template <typename T1, typename T2>
inline bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return (y < x);
}

// x <= y -> reverse of y < x
template <typename T1, typename T2>
inline bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return !(y < x);
}

// x >= y -> reverse of y > x
template <typename T1, typename T2>
inline bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return !(x < y);
}

// make_pair
template <typename T1, typename T2> inline pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

} // namespace ft
#endif
