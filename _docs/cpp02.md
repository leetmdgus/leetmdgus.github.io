---
title: "[C++] 기본 입출력을 배워 보자..."
description: "[C++] 기본 입출력을 배워 보자..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## C++ 공부 (2020-10-13)

####  1. C++에서의 pintf와 scanf

+ 기본적인 실행방식은 C 프로그램과 동일하다.

+ **단, 확장자는 반드시 .c가 아닌 .cpp로 해야한다.**

  

### 문자열 "Hello World의 출력"

모든 프로그램이 그렇듯 첫 시작을 "Hello World" 출력으로 시작하겠다.

~~~c++
#include <iostream>

int main(void){
    int num = 20;
    std::cout << "Hello World!"<< std::endl;
    std::cout << "Hello "<< "World!"<< std::endl;
    std::cout::num<<''<<'A';
    std::cout<<''<<3.14<<std::endl;
    return 0;
}
~~~

> 실행 결과

~~~
Hello World!
Hello World!
20 A 3.14
~~~

여기서 가장 큰 특징 몇 가지를 확인 할 수 있다.

+ 헤더파일 선언문 #include <iostream>
+ std::cout 과 <<을 이용한 출력
+ std::endl을 이용한 개행(c언어에서의 \n)



#### 헤더파일 선언문 `#include <iostream>`

+ std, cout, enl과 같은 것을 사용하려면 위와 같은 헤더파일 선언문이 추가되어야 한다.
+ C++의 헤더파일 확장자는 C와 마찬가지로 .h이다.
+ 그러나 C++에서는 생략하기로 약속되어 있다.

> 과거에는 입력 및 출력에 관한 일을 하기 위해 iostream에 헤더파일 확장자를 붙여 선언했는데, 새로운 C++ 표준의 도입으로 인해 C++의 표준 라이브러리에 변화가 있었다.
>
> + 과거의 표준 라이브러리와 새로운 표준 라이브러리의 구분
> + 새로운 표준 라이브러리를 사용하는 형태로 소스코드를 쉽게 변경할 수 있도록
>
> 위와 같은 이유로 헤더파일 확장자를 생략하기로 했다.
>
> 때문에 `<iostream.h>`는 과거의 표준 입출력 라이브러리 및 헤더를 의미하는 것으로 통용이 되고 C++ 컴파일러는 점차 `<iostream.h>`을 지원하지 않는 추세로 접어들었다.



#### std::cout 과 <<을 이용한 출력



#### std::endl을 이용한 개행(c언어에서의 \n)



### scanf를 대신하는 데이터의 입력







<참고 : 열혈 C++ 프로그래밍>