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



