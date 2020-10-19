---
title: "[C++] Chapter 02의 시작에 앞서서..."
description: "[C++] Chapter 02의 시작에 앞서서..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---

## Chapter 02의 시작에 앞서서

#### 문제 1. 키워드 const의 의미

+ 키워드 const는 어떤한 의미를 갖는가?

  + ```c
    const int num = 20;
    ```

    +  변수 num 을 상수화

  + ```c
    const int * ptr1 = &val1;
    ```

    + 포인터 ptr1을 이용해서 val1의 값을 변경할 수 없음

  + ```c
    int * const ptr2 = &val2;
    ```

    + 포인터 ptr2가 상수화됨

  + ```c
    const int * const ptr3 = &val3;
    ```

    + 포인터 ptr3가 상수화 되었으며, ptr3를 이용해서 val3의 내용을 변경할 수 없음

#### 실행중인 프로그램의 메모리 공간

+ 실행중인 프로그램은 운영체제로부터 메모리 공간을 할당 받는데, 이는 크게 데이터, 스택, 힙 영역으로 나뉜다. 각각의 영역에는 어떠한 형태의 변수가 할당되는지 설명해보자. 특히 c언어의 malloc과 free함수와 관련해서도 설명해보자.
  + **데이터** : 전역변수가 저장되는 영억
  + **스택** : 지역변수 및 매개변수가 저장되는 영역 (= 프로그램을 실행하는 과정에서 필요로하는 메모리 공간)
  + **힙** : malloc 함수 호출에 의해 프로그램이 실행되는 과정에서 동적으로 할당이 이뤄지는 영역
  + **malloc & free** : malloc함수 호출에 의해 할당된 메모리 공간은 free함수 호출을 통해 소멸하지 않으면 해제되지 않는다.

#### Call - by - value vs. Call - by - reference

+ call-by-value

   ```c++
  void SwapByValue(int num1, int num2){
  	int temp = num1;
  	num1 = num2;
  	num2 = temp;
  } 
   ```

+ call-by-reference

  ```c++
  void SwapByRef(int *ptr1, int * ptr2){
  	int temp = *ptr1;
  	*ptr1 = *ptr2;
  	*ptr1 = *ptr2
  	*ptr2 = temp;
  }
  ```




제작일 : 2020-10-18

<참고 : 열혈 C++ 프로그래밍 >

