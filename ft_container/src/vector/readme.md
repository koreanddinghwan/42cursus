# std::vector

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

## _Vector_base

### 정의

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

