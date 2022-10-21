# Intro

## 과제소개 

- 42의 ft_containers 과제
- C++의 template library인 stl을 만드는 과제이다.
- 각 표준 컨테이너의 구조를 참고해야하고, Orthodox Canonical form이 구현되어있지 않다면, 생략해도된다.
- C++98 표준을 맞춰야하며, 이후의 컨테이너 특징은 구현되어선 안된다.
- 98++의 특징은 맞춰져야한다.



<br>

## 요구사항


### Mandatory

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


### Requirements

- namespace는 ft여야한다.
- map에 array쓰는건 정당화될 수 없음.
- 표준 컨테이너에서 만들어진 것 외의 public 함수 만들지말것.
- 표준컨테이너의 멤버함수, 비멤버함수, 오버로딩 구현
- `original naming` 따를 것
- 컨테이너가 `iterator 시스템`이있으면 구현해라
- `std::allocator` 사용해라
- 비멤버함수 오버로딩을위해 `friend`키워드 사용
	- map::value_compare을 위해 사용하는 것을 예시로한다.


<br>
<br>


# REF : GCC

C++98버전의 기능을 구현해야하므로, 이를 만족하는 최소한의 기능만 구현된 레퍼런스가 필요하다. 이를 찾기위해 GCC 소스코드에서 브랜치를 구경해보자.  

[GCC-MIRROR](https://github.com/gcc-mirror/gcc)

<img width="550" alt="스크린샷 2022-10-18 오후 6 27 35" src="https://user-images.githubusercontent.com/76278794/196392409-87234828-fd96-4df4-9eb9-9e6f08b858f0.png">

<br>

- 수많은 버전 중에 C++98 표준이 적용되어있고, 가장 적은 기능만 구현되어있는 GCC 버전을 골라야한다.

- 공식홈페이지에서 GCC의 C++98버전 지원 정보를 알려주는데, 모든 GCC가 C++98표준을 지원한다는 것을 알 수 있다.
	- [GCC C++98 Support 정보](https://gcc.gnu.org/projects/cxx-status.html)

<br>


- 과제에 필요한 주된 레퍼런스는 cppreference에서, 
- 기능상 구현해야할 세세한 것들은 여기서 확인하자.
	- <img width="219" alt="스크린샷 2022-10-18 오후 7 49 25" src="https://user-images.githubusercontent.com/76278794/196410055-37670d22-43f4-4e03-8fdf-faafddc84bd4.png">

<br><br>




# KEYWORD

## SGI

- 2.95버전에서는 alloc.h가 include되어있으나, gcc 4.3버전 이상부터는 alloc.h header가 memory라는 헤더로 변경되었다.
	- <img width="420" alt="스크린샷 2022-10-18 오후 8 08 17" src="https://user-images.githubusercontent.com/76278794/196413645-2c7daaa5-1c0a-4aaf-8558-70bae0a314eb.png">
	- [gcc4.3 version update](https://gcc.gnu.org/gcc-4.3/porting_to.html)

<br>

- 과제를 진행하면서 gcc의 소스코드를 버전별로 checkout 하면서 확인해보고있는데, 주석도 천차만별이다.
- 특히 2.95버전은 기능상으로 모든 부분(std::pair의 operator들)이 부족하기때문에 다른 version으로 checkout해서 구현을 확인했다.
- 낮은 버전을 checkout 해나가면서 참고하자.

<br>

[SGI란](https://www.boost.org/sgi/stl/alloc.html)  

default allocator인 alloc은 작은 객체를 위한 자유로운 리스트를 유지한다.  
큰 요청사항(큰 메모리 할당)을 만족하고, 작은 객체로 분리될 수 있는 더 큰 크기의 메모리를 할당하기위해 시스템이 제공하는 allocator를 사용한다.  

<br>



# std::vector

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


## stl_algobase.h


