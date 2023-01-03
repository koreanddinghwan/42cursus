# std::stack


## 정의

```cpp
  template<typename _Tp, typename _Sequence = deque<_Tp> >
    class stack;
  /**
   *  @brief  A standard container giving FILO behavior.
   *
   *  @ingroup Containers
   *  @ingroup Sequences
   *
   *  Meets many of the requirements of a
   *  <a href="tables.html#65">container</a>,
   *  but does not define anything to do with iterators.  Very few of the
   *  other standard container interfaces are defined.
   *
   *  This is not a true container, but an @e adaptor.  It holds
   *  another container, and provides a wrapper interface to that
   *  container.  The wrapper is what enforces strict
   *  first-in-last-out %stack behavior.
   *
   *  The second template parameter defines the type of the underlying
   *  sequence/container.  It defaults to std::deque, but it can be
   *  any type that supports @c back, @c push_back, and @c pop_front,
   *  such as std::list, std::vector, or an appropriate user-defined
   *  type.
   *
   *  Members not found in "normal" containers are @c container_type,
   *  which is a typedef for the second Sequence parameter, and @c
   *  push, @c pop, and @c top, which are standard %stack/FILO
   *  operations.
  */
```

- std::stack은 iterator가 구현되어있지 않는 것으로 알려져있다.
- std::stack은 컨테이너가 아닌 디자인 패턴 중 adaptor 구현에 가깝다.
- 다른 컨테이너를 wrapping하는 인터페이스를 제공한다.
- 이 wrapping하는 인터페이스는 stack의 연산, `FILO 연산`을 지원한다.

<br>

- 템플릿의 두번째 인자로 기반 sequence, container를 받는다.
- 기본적으로 std::deque이며, back, push_back, pop_front와 같은 연산을 지원하는 std::list, std::vector, 또는 사용자 정의 유형이 올 수 있다.

<br><br>

## adaptor design pattern

<img width="612" alt="스크린샷 2023-01-03 15 25 59" src="https://user-images.githubusercontent.com/76278794/210308938-e2d480e3-6128-44e0-a96d-ee8e9a9b6a60.png">

- adaptor 패턴은 한 클래스의 인터페이스를 client가 기대하는 interface로 변환한다.
- adaptor 디자인 패턴은 널리 사용되는 모든 프로그래밍 언어로 구현될 수 있다.
- std::stack은 adaptor의 구현이며 
  - 이 클래스를 사용하는 프로그래머(client)가 기대하는
  - stack의 interface를 
  - 기본적으로는 deque, 혹은 list, vector, user defined class를 wrapping해서 제공한다.

<br>
<br>

# std::map


```c++
template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
	  typename _Alloc = std::allocator<std::pair<const _Key, _Tp> >>
/**
 *  @brief A standard container made up of (key,value) pairs, which can be
 *  retrieved based on a key, in logarithmic time.
 *
 *  @ingroup associative_containers
 *
 *  @tparam _Key  Type of key objects.
 *  @tparam  _Tp  Type of mapped objects.
 *  @tparam _Compare  Comparison function object type, defaults to less<_Key>.
 *  @tparam _Alloc  Allocator type, defaults to
 *                  allocator<pair<const _Key, _Tp>.
 *
 *  Meets the requirements of a <a href="tables.html#65">container</a>, a
 *  <a href="tables.html#66">reversible container</a>, and an
 *  <a href="tables.html#69">associative container</a> (using unique keys).
 *  For a @c map<Key,T> the key_type is Key, the mapped_type is T, and the
 *  value_type is std::pair<const Key,T>.
 *
 *  Maps support bidirectional iterators.
 *
 *  The private tree data is declared exactly the same way for map and
 *  multimap; the distinction is made entirely in how the tree functions are
 *  called (*_unique versus *_equal, same as the standard).
*/
```

- 표준 컨테이너를 (key, value) pair를 통해 생성한다.
- key를 기반해 원소를 받으며, log시간 안에 만들어진다.

<br>

- 파라미터로 받는 값들은 4가지가 있다.
  1. _Key : key 객체의 type
  2. _Tp : mapped된 객체의 type
  3. _Compare : 객체 type의 비교연산을 수행하는 함수, 기본적으로 `std::lest<_Key>`이다.
  4. _Alloc : Allocator type, 기본적으로 `allocator<std::pair<const _Key, _Tp>>`이다.

<br>
