---
title: "[C++]새로운 자료형 bool..."
description: "[C++] 새로운 자료형 bool..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---

## 새로운 자료형 bool

#### '참'을 의미하는 true와  '거짓'을 의미하는 false

+ C와 C++모두, 정수 0은 '거짓'을 의미하는 숫자로, 그리고 0이 아닌 모든 정수는 '참'을 의미하는 숫자로 정의하고 있다. 

```c
#define TRUE   1
#define FALSE  0
```

+ C++에서는 참과 거짓의 표현을 위한 키워드 true와 false를 정의하고 있기 때문에 굳이 매크로 상수를 이용해서 참과 거짓을 표현할 필요가 없다.

> true 와 false는 각각 1과 0을 의미하는 **키워드가 아니다**.

+ true와 false는 각각 '참'과 '거짓'을 표현하기 위한 1바이트 크기의 데이터일 뿐이다.
+ 다만, true와 false가 정의되기 이전에 참을 표현하기 위해 1을, 거짓을 표현하기 위해 0을 사용했기 때문에 이 둘을 출력하거나 정수의 형태로 형 변환하는 경우 각각 1과 0으로 변환되도록 정의되어 있다.

```c++
int num1 = true; //num1에는 1이 저장된다.
int num2 = false; // num2에는 0이 저장된다.
int nu3 = true+false; // num3에는 1+0 이저장된다.
```



#### 자료형 bool

+ true와 false를 가리켜 bool형 데이터라 한다.

~~~c++
bool isTrueOne = true;
bool isTrueTwo = false;
~~~

+ bool도 기본 자료형이기 때문에 함수의 반환형으로도 선언 가능하다.






제작일 : 2020-10-20

<참고 : 열혈 C++ 프로그래밍 >

