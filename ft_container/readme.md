# ReadMe

## Intro

- 42의 ft_containers 과제
- C++의 template library인 stl을 만드는 과제이다.
- 각 표준 컨테이너의 구조를 참고해야하고, Orthodox Canonical form이 구현되어있지 않다면, 생략해도된다.
- C++98 표준을 맞춰야하며, 이후의 컨테이너 특징은 구현되어선 안된다.
- 98++의 특징은 맞춰져야한다.



- Library for ft_containers
  0. [requirements, tips](# requirements)
  1. [vector](# vector): readmeUpdated
  2. [stack](# stack)
  3. [map](# map)
  4. [set](# map)

# requirements

- 제출양식
	- `<container>.hpp`로 제출.

- 구현해야하는 컨테이너 종류
	- `vector`
		- vector<bool> 특수화는 구현하지 않아도된다.
	- `map`
	- `stack`
		- vector 클래스를 기본 컨테이너로 만든다.
		- 다른 컨테이너와는 비교가능해야한다.

<br>

- implements
	1. iterators_traits
	2. reverse_iterator
	3. enable_if
		- C++98 방식으로 구현할것.
		- `SFINAE`에 대해 공부해라.
	4. is_integral
	5. equal and/or lexicographical_compare
	6. std::pair
	7. std::make_pair

<br>

## std::allocator

- allocate 메서드

```cpp
_LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
    const _Tp* allocate(size_t __n) {
        if (__n > allocator_traits<allocator>::max_size(*this))
            __throw_bad_array_new_length();
        if (__libcpp_is_constant_evaluated()) {
            return static_cast<const _Tp*>(::operator new(__n * sizeof(_Tp)));
        } else {
            return static_cast<const _Tp*>(_VSTD::__libcpp_allocate(__n * sizeof(_Tp), _LIBCPP_ALIGNOF(_Tp)));
        }
    }
```

- 일반적으로 사용하는 new 연산자와 다르게 ::operator new는 C의 malloc과 동일하게 작동한다.
- 일반적인 new가 작동하는 방식을 pseudo code로 나타내면 아래와 같다.

```c++
Fred* p;
void* tmp = ::operator new(sizeof(Fred)); //heap allocation
try {
  new(tmp) Fred();  // Placement new
  p = (Fred*)tmp;   // The pointer is assigned only if the constructor succeeds
}
catch (...) {
  operator delete(tmp);  // Deallocate the memory
  throw;                 // Re-throw the exception
}
```

- try ~ catch block내에 Placement new가 있다.
- 인자로 받은 포인터에 생성자를 호출해 값을 채운다.
- 이 부분에서 만약 error가 throw된다면 동적할당했던 메모리를 해제하고, stack unwinding으로 예외를 throw하게된다.

<br>


## std::iterator

### iterator design pattern

- iterator는 list, stack, tree등 `자료구조의 기본 표현을 노출하지 않고` 컬렉션의 요소를 탐색할 수 있도록 하는 `동작디자인 패턴`이다.
- 컬렉션? 
	- 컬렉션은 프로그래밍에서 사용되는 데이터 유형 중 하나이다.
	- 개체 그룹의 컨테이너이며, list, map, vector 등 자료구조를 기반으로 데이터를 저장한다.
- iterator 동작 디자인 패턴의 목적은 내부의 자료구조가 무엇인가에 관계없이 원소에 접근하는 방법을 제공한다.
- iterator 패턴의 주요 아이디어는 이러한 컬렉션의 순회동작을 iterator라는 별도의 개체로 추출하는 것이다.

```c++
// std::iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
  int* p;
public:
  MyIterator(int* x) :p(x) {}
  MyIterator(const MyIterator& mit) : p(mit.p) {}
  MyIterator& operator++() {++p;return *this;}
  MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
  bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
  bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
  int& operator*() {return *p;}
};

int main () {
  int numbers[]={10,20,30,40,50};
  MyIterator from(numbers);
  MyIterator until(numbers+5);
  for (MyIterator it=from; it!=until; it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
```

- MyIterator 클래스는 std::iterator를 상속하는 클래스이다.
- 남은 원소의 개수가 몇개이고, 현재위치가 어디인지에 대한 정보들이 캡슐화되어있는 상태로 사용한다.

<br>

## iterator_traits

```cpp
template< class Iter >
struct iterator_traits;
template< class T >
struct iterator_traits<T*>;
template< class T >
struct iterator_traits<const T*>;
```
- traits 클래스는 iterator의 특성을 정의한다.
- 표준 algorithm 헤더는 iterator들에게 주어지는의 특성을 정의하고, iterator들이 표현하는 범위를 그에 상응하는 `iterator_traits`의 인스턴스화를 통해 정의한다.
- 모든 iterator type에 대해 상승하는 iterator_traits 클래스의 인스턴스화는 최소한 밑의 멤버 유형이 정의된 상태에서 정의되어야한다.
	1. difference_type : iterator끼리의 뺄셈의 결과를 표현할때 사용하는 type
	2. value_type : iterator가 point할 원소의 type
	3. pointer : iterator가 point하는 원소의 pointer type
	4. reference : iterator가 point할 원소의 reference type
	5. iterator_category: 아래 중 1개
		1. input_iterator_tag : iterator가 가리키는 값은 1번만 읽어지고, iterator는 증가한다.
			- forward, bidirectional, random_access iterator들도 유효한 input iterator이다.
		2. output_iterator_tag : iterator가 가리키는 값은 1번만 쓰여질 수 있고, iterator는 증가한다.
		3. forward_iterator_tag : 범위 내의 연속적인 원소에 begin부터 end까지 접근한다.
			- bidirectional, random_access iterator모두 유효한 forward_iterator이다.
		4. bidirectional_iterator_tag : forward와 달리, end->begin, begin->end까지 모두 가능하다.
		5. random_access_iterator_tag : 포인터처럼 임의접근이 가능한 iterator이다.
			- pointer-types 또한 random_access iterator이다.

<br>

- 구현되어야하는 최소한의 템플릿 특수화는 다음과 같다.

```cpp
template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;
```

<br>


## std::reverse_iterator

### 정의

<img width="595" alt="Screen Shot 2023-01-02 at 11 22 41 AM" src="https://user-images.githubusercontent.com/76278794/210191211-fe4d65ff-d604-4a8e-81b3-9af0ababb585.png">


```cpp
template< class Iter >
class reverse_iterator;
```

- reverse_iterator는 주어진 iterator의 방향을 바꾸는 어댑터이다.
- 최소한 legacyBidirectionalIterator혹은 bidirectional_iterator 이어야한다.
- 만약 bidirectional_iterator가 제공되면 end->begin으로 향하는 새로운 iterator를 생성한다.
- 만약 iterator i로 reverce_iterator r이 생성된다면
	- `&*r == &*(i-1)`은 항상 참이다.


<br>

## std::enable_if

```cpp
template< bool B, class T = void >
struct enable_if;
```

- 만약 B가 true라면, std::enable_if는 public member typedef type T를 가진다.
- B가 false라면 가지지 않는다.
- 이 메타함수는 특히 trait type을 기반으로 candidate set에서 조건부로 함수를 제거하기위해 `SFINAE`를사용하는 편리한 방법이다.
- 다양한 형태로 사용될 수 있다.
	1. 추가 함수 인수로 사용된다.
	2. return type으로써 사용
	3. class template이나 function template 파라미터로 사용
- enable_if에 대한 specialization은 undefined된다.

<br>

- 치환오류가 발생하는 경우, 오버로딩할 candidate set에서 제외한다.
- Boost 라이브러리에서 오랜 기간 사용되어 왔고, C++ 11에서 정식 편입되었다.
	- 우리가 구현하는건 std::enable_if로 편입되기 전이다.

### SFINAE

- `substitution failure is not an error`
- 템플릿 매개변수에 자료형이나 값을 넣을 수 없음애도 오류가 발생하지 않는 것을 이용한 프로그래밍 방식이다.

<br>


## std::lexicographical_compare

```c++
template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2 );

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2, Compare comp );
```

- [first1, last1] 범위 내 값들이 [first2, last2]범위 내 값들보다 작은지 사전순으로 비교한다.
	- < 연산자를 통해 비교한다.
	- 또는 comp함수를 통해 비교한다.


<br><br>


# vector

## class diagram

<img src="https://user-images.githubusercontent.com/76278794/210253699-12970c34-b59e-427d-bb34-2e36d2e984e2.png">

## design pattern

- std::vector는 `sequence design pattern`의 예시이다.
- linear한 원소를 표현한다.
- dynamic array를 자료구조를 사용해 이 패턴을 구현한다.

<br>

- 특징
	1. template클래스로써, template 파라미터로 원소의 type을 받는다.
	2. operator[]로 상수시간에 임의접근이 가능하다.
	3. push_back, pop_back은 마지막 원소에 대해 상수시간에 삽입, 삭제가 가능하다.
	4. insert, erase 멤버함수로 어느 위치의 원소에대해서든 선형시간에 삽입, 삭제가 가능하다.
	5. 보관하는 원소의 갯수에 따라 크기가 커지거나 작아진다.

<br><br>

```c
#include <bits/functexcept.h>
#include <bits/stl_algobase.h>
#include <bits/allocator.h>
#include <bits/stl_construct.h>
#include <bits/stl_uninitialized.h>
#include <bits/stl_vector.h>
#include <bits/stl_bvector.h> 

#ifndef _GLIBCXX_EXPORT_TEMPLATE
# include <bits/vector.tcc>
#endif

#ifdef _GLIBCXX_DEBUG
# include <debug/vector>
#endif
```

std_vector.h의 헤더에는 이러한 헤더들이 Include되어있다. 하나씩 확인해보자  

<br>

## bits/functexcept.h


<img width="525" alt="스크린샷 2022-10-21 오후 12 52 43" src="https://user-images.githubusercontent.com/76278794/197107775-0a110fee-8feb-4b60-8744-d42f64c30be0.png">

<br>

### exception_defines.h

```c
//gcc 4.0
#ifndef _EXCEPTION_DEFINES_H
#define _EXCEPTION_DEFINES_H 1

#ifndef __EXCEPTIONS
// Iff -fno-exceptions, transform error handling code to work without it.
# define try      if (true)
# define catch(X) if (false)
# define __throw_exception_again
#else
// Else proceed normally.
# define __throw_exception_again throw
#endif

#endif
```

- internal header file로써, library header에 의해 include되어 사용된다. 직접저긍로 사용되지 말라고 명시되어있다.
- 최신버전의 컴파일러 소스코드에서는 아래와 같이 구현되어있다.

```c
//gcc 12.2.0
#ifndef _EXCEPTION_DEFINES_H
#define _EXCEPTION_DEFINES_H 1

#if ! __cpp_exceptions
// Iff -fno-exceptions, transform error handling code to work without it.
# define __try      if (true)
# define __catch(X) if (false)
# define __throw_exception_again
#else
// Else proceed normally.
# define __try      try
# define __catch(X) catch(X)
# define __throw_exception_again throw
#endif

#endif
```

- 컴파일 옵션에서 -fno-exceptions 가 켜져있으면, try는 항상 true, catch는 항상 False가 된다.  

- 내부 헤더에서 `__throw_exception_again` 키워드가 사용되면 컴파일러단에서 -fno-exceptions가 켜져있는지 유무에따라 exception을 throw할지, 말지 결정하게된다.

<br>

### __attribute__


```c
namespace std
{
  // Helper for exception objects in <except>
  void
  __throw_bad_exception(void) __attribute__((__noreturn__));

  // Helper for exception objects in <new>
  void
  __throw_bad_alloc(void) __attribute__((__noreturn__));

  // Helper for exception objects in <typeinfo>
  void
  __throw_bad_cast(void) __attribute__((__noreturn__));
```

[gcc.gnu.org](https://gcc.gnu.org/onlinedocs/gcc-4.6.1/gcc/Function-Attributes.html#Function-Attributes)

- 컴파일러 소스코드에서 자주 나오는데, `__attribute__`로 컴파일러의 함수 호출을 최적화하고, 코드를 안전하게 검사할 수 있게끔 해주는 것을 선언해줄 수 있다.
- `noreturn`의 경우, exit, abort와 같은 특정 함수들로 인해 이를 호출한 함수가 `절대로 리턴될 수 없는 경우!`에 사용된다.

<br><br>

### noreturn 예시

- 어셈블리를 제대로 배운적은 없지만, 대략적인 코드의 차이는 간단하게 확인가능하다.

<br>

- 사용하지 않은경우

```c
#include <unistd.h>
#include <stdlib.h>

//void f()__attribute__((noreturn));

void f(){
	write(1,"a", 1);
	exit(1);
};

void b()
{
	write(1, "b", 1);
}

int main(void)
{
	f();
	b();
	return 0;
}
```

```asm
0000000100003f1c <_f>:
100003f1c: ff 83 00 d1 	sub	sp, sp, #32
100003f20: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f24: fd 43 00 91 	add	x29, sp, #16
100003f28: 20 00 80 52 	mov	w0, #1
100003f2c: a0 c3 1f b8 	stur	w0, [x29, #-4]
100003f30: 01 00 00 90 	adrp	x1, 0x100003000 <_f+0x14>
100003f34: 21 d0 3e 91 	add	x1, x1, #4020
100003f38: 22 00 80 d2 	mov	x2, #1
100003f3c: 1b 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f40: a0 c3 5f b8 	ldur	w0, [x29, #-4]
100003f44: 16 00 00 94 	bl	0x100003f9c <_write+0x100003f9c>

0000000100003f48 <_b>:
100003f48: fd 7b bf a9 	stp	x29, x30, [sp, #-16]!
100003f4c: fd 03 00 91 	mov	x29, sp
100003f50: 20 00 80 52 	mov	w0, #1
100003f54: 01 00 00 90 	adrp	x1, 0x100003000 <_b+0xc>
100003f58: 21 d8 3e 91 	add	x1, x1, #4022
100003f5c: 22 00 80 d2 	mov	x2, #1
100003f60: 12 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f64: fd 7b c1 a8 	ldp	x29, x30, [sp], #16
100003f68: c0 03 5f d6 	ret

0000000100003f6c <_main>:
100003f6c: ff 83 00 d1 	sub	sp, sp, #32
100003f70: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f74: fd 43 00 91 	add	x29, sp, #16
100003f78: 08 00 80 52 	mov	w8, #0
100003f7c: e8 0b 00 b9 	str	w8, [sp, #8]
100003f80: bf c3 1f b8 	stur	wzr, [x29, #-4]
100003f84: e6 ff ff 97 	bl	0x100003f1c <_f>
100003f88: f0 ff ff 97 	bl	0x100003f48 <_b>
100003f8c: e0 0b 40 b9 	ldr	w0, [sp, #8]
100003f90: fd 7b 41 a9 	ldp	x29, x30, [sp, #16]
100003f94: ff 83 00 91 	add	sp, sp, #32
100003f98: c0 03 5f d6 	ret
```

<br>

- noreturn을 제대로 사용한 경우

```c
#include <unistd.h>
#include <stdlib.h>

void __attribute__((noreturn))f(){
	write(1,"a", 1);
	exit(1);
};

void b()
{
	write(1, "b", 1);
}

int main(void)
{
	f();
	b();
	return 0;
}
```

```asm
0000000100003f38 <_f>:
100003f38: ff 83 00 d1 	sub	sp, sp, #32
100003f3c: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f40: fd 43 00 91 	add	x29, sp, #16
100003f44: 20 00 80 52 	mov	w0, #1
100003f48: a0 c3 1f b8 	stur	w0, [x29, #-4]
100003f4c: 01 00 00 90 	adrp	x1, 0x100003000 <_f+0x14>
100003f50: 21 d0 3e 91 	add	x1, x1, #4020
100003f54: 22 00 80 d2 	mov	x2, #1
100003f58: 14 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f5c: a0 c3 5f b8 	ldur	w0, [x29, #-4]
100003f60: 0f 00 00 94 	bl	0x100003f9c <_write+0x100003f9c>

0000000100003f64 <_b>:
100003f64: fd 7b bf a9 	stp	x29, x30, [sp, #-16]!
100003f68: fd 03 00 91 	mov	x29, sp
100003f6c: 20 00 80 52 	mov	w0, #1
100003f70: 01 00 00 90 	adrp	x1, 0x100003000 <_b+0xc>
100003f74: 21 d8 3e 91 	add	x1, x1, #4022
100003f78: 22 00 80 d2 	mov	x2, #1
100003f7c: 0b 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f80: fd 7b c1 a8 	ldp	x29, x30, [sp], #16
100003f84: c0 03 5f d6 	ret

0000000100003f88 <_main>:
100003f88: ff 83 00 d1 	sub	sp, sp, #32
100003f8c: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f90: fd 43 00 91 	add	x29, sp, #16
100003f94: bf c3 1f b8 	stur	wzr, [x29, #-4]
100003f98: e8 ff ff 97 	bl	0x100003f38 <_f>
```

<br>

- noreturn을 사용했으나, exit하지 않은경우
	- SIGTRAP으로 프로그램이 종료된다.

```c
#include <unistd.h>
#include <stdlib.h>

void f()__attribute__((noreturn));

void f(){
	write(1,"a", 1);
//	exit(1);
};

void b()
{
	write(1, "b", 1);
}

int main(void)
{
	f();
	b();
	return 0;
}
```

```asm
0000000100003f50 <_f>:
100003f50: fd 7b bf a9 	stp	x29, x30, [sp, #-16]!
100003f54: fd 03 00 91 	mov	x29, sp
100003f58: 20 00 80 52 	mov	w0, #1
100003f5c: 01 00 00 90 	adrp	x1, 0x100003000 <_f+0xc>
100003f60: 21 d0 3e 91 	add	x1, x1, #4020
100003f64: 22 00 80 d2 	mov	x2, #1
100003f68: 10 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f6c: 20 00 20 d4 	brk	#0x1

0000000100003f70 <_b>:
100003f70: fd 7b bf a9 	stp	x29, x30, [sp, #-16]!
100003f74: fd 03 00 91 	mov	x29, sp
100003f78: 20 00 80 52 	mov	w0, #1
100003f7c: 01 00 00 90 	adrp	x1, 0x100003000 <_b+0xc>
100003f80: 21 d8 3e 91 	add	x1, x1, #4022
100003f84: 22 00 80 d2 	mov	x2, #1
100003f88: 08 00 00 94 	bl	0x100003fa8 <_write+0x100003fa8>
100003f8c: fd 7b c1 a8 	ldp	x29, x30, [sp], #16
100003f90: c0 03 5f d6 	ret

0000000100003f94 <_main>:
100003f94: ff 83 00 d1 	sub	sp, sp, #32
100003f98: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f9c: fd 43 00 91 	add	x29, sp, #16
100003fa0: bf c3 1f b8 	stur	wzr, [x29, #-4]
100003fa4: eb ff ff 97 	bl	0x100003f50 <_f>
```



<br>

- noreturn attribute가 사용된 함수를 호출한 main함수부를 보자.
	- 일반적인 exit 호출
		```asm
		0000000100003f6c <_main>:
		100003f6c: ff 83 00 d1 	sub	sp, sp, #32
		100003f70: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
		100003f74: fd 43 00 91 	add	x29, sp, #16
		100003f78: 08 00 80 52 	mov	w8, #0
		100003f7c: e8 0b 00 b9 	str	w8, [sp, #8]
		100003f80: bf c3 1f b8 	stur	wzr, [x29, #-4]
		100003f84: e6 ff ff 97 	bl	0x100003f1c <_f>
		100003f88: f0 ff ff 97 	bl	0x100003f48 <_b>
		100003f8c: e0 0b 40 b9 	ldr	w0, [sp, #8]
		100003f90: fd 7b 41 a9 	ldp	x29, x30, [sp, #16]
		100003f94: ff 83 00 91 	add	sp, sp, #32
		100003f98: c0 03 5f d6 	ret
		```
	- noreturn 함수에서의 exit호출
		```asm
		0000000100003f88 <_main>:
		100003f88: ff 83 00 d1 	sub	sp, sp, #32
		100003f8c: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
		100003f90: fd 43 00 91 	add	x29, sp, #16
		100003f94: bf c3 1f b8 	stur	wzr, [x29, #-4]
		100003f98: e8 ff ff 97 	bl	0x100003f38 <_f>
		```
	- main문에서 noreturn attribute가 붙은 코드를 호출하면 그 아래의 함수부는 main부에 작성되지 않는다.

<br><br>

### _Vector_base

## 정의

```cpp
template <typename _Tp, typename _Alloc> struct _Vector_base {
  struct _Vector_impl : public _Alloc {
    _Tp *_M_start;
    _Tp *_M_end;
    _Tp *_M_end_of_storage;
  };
};
```

- std::vector 클래스 템플릿은 _Vector_base를 기반으로한다.
- std::vector를 구현하기위한 기본적인 data member를 가지고 있다.
- dynamic array의 start, end, 그리고 end_of_storage에 대한 포인터를 들고있다.

<br>

- template parameter로 _Tp, _Alloc을 받는다.
	- _Tp : vector에 저장된 원소의 type
	- _Alloc : vector의 메모리를 관리하는 allocator object의 type

<br>

- member
	1. _Vector_impl
		- _Alloc 즉 std::allocator 객체를 상속한다.
		- _Alloc 객체에서 allocator 객체의 멤버함수에 대한 접근권한을 받는다.
		- _M_start, _M_finish, _M_end_of_storage의 멤버변수는 vector의 dynamic array에 대한 포인터를 의미한다.
	2. allocator_type
		- _Alloc type의 typedef이다. vector가 사용하는 allocator object의 type을 표현한다.
	3. get_allocator()
		- vector가 사용하는 allocator 객체의 복사본을 리턴한다.
	4. _M_impl
		- vector 구현에 사용되는 멤버변수를 저장하는 _Vector_impl의 인스턴스
	5. _M_allocate(size_t __n)
		- _Vector_impl의 allocate함수를 호출하는 멤버함수인데, _Vector_impl이 allocator 객체를 상속하고있으므로, allocator 객체의 멤버함수 allocate를 호출하는 것이다.
	6. _M_deallocate(_Tp *__p, size_t __n)
		- 이전에 할당된 메모리를 해제한다.

<br><br>

- _Vector_base class template의 경우
	- `get_allocator()`
	- `_M_allocate()`
	- `_M_deallocate()`
	- 위 함수들은 _Alloc(std::allocator)의 allocate, deallocate를 통해 정의된다.
		- allocate, deallocate 멤버함수는 항상 std::allocator에 의해 제공된다.

- _Vector_base는 자신의 _M_allocate, _M_deallocate메서드를 _Alloc(std::allocator)의 allocate, deallocate메서드로 구현한다.
- vector는 `allocate, deallocate 멤버함수를 제공하는 여러개의 allocator class로 구현될 수 있다.`

<br><br>

# stack

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

# map

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


# set
