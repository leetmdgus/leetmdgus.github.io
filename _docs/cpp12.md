---
title: "[C++] malloc & free를 대신하는 new & delete"
description: "[C++] malloc & free를 대신하는 new & delete"
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## malloc & free를 대신하는 new & delete

#### C언어에서의 동적 할당

> 길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 그 배열의 조소값을 반환하는 함수를 만들어 보자.

```c++
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len){
	char * str = (char*)malloc(sizeof(char)*len);
    return str;
}

int main(void){
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout<<str<<endl;
    free(str);
    return 0;
}
```

+ C++에서 C언어의 헤더파일을 추가하는 것이 가능하다.
+ malloc을 통해 문자열 저장을 위한 배열을 힙 영역에 할당하고 있다.
+ free를 통해 힙에 할당된 메모리 공간을 소멸하고 있다.

> 실행결과

~~~
I am so happy~
~~~

+ C언어에서의 동적할당에는 다음 두 가지 불편함이 존재한다.

  + 할당할 대상의 정보를 무조건 바이트 크기 단위로 전달해야 한다.
  + 반환형이 void형 포인터기 때문에 적절한 형 변환을 거쳐야 한다.

+ 하지만, C++에서 제공하는 키워드 new와 delete를 사용하면 이러한 불편한 점이 사라진다.

  + int 형 변수의 할당 / 소멸

    ```c++
    int * ptr1 = new int;
    delete ptr1;
    ```

  + double형 변수의 할당 / 소멸

    ```c++
    double * ptr2 = new double;
    delete ptr2;
    ```

  + 길이가 3인 int형 배열의 할당 / 소멸

    ~~~c++
    int * arr1 = new int[3];
    delete []arr1;
    ~~~

  + 길이가 7인 double형 배열의 할당 / 소멸

    ```c++
    double * arr2 = new doublep[7];
    delete []arr2;
    ```

+ new 연산 시 반환된 주소 값을 대상으로 delete 연산을 진행하되, 할당된 영역이 배열의 구조라면 []를 추가로 명시해주기만 하면 된다.



#### delete 사용 해보기

```c++
#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len){
	//char * str = (char *)malloc(sizeof(char)*len);
	char * str = new char[len];
	return str;
}

int main(void){
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	//free(str);
	delete[str];
	return 0;
}
```

> 실행 결과

~~~
I am so happy~
~~~

+ C++에서는 malloc과 free함수의 호출이 문제가 될 수도 있다
+ 



#### 객체의 생성에서는 반드시 new & delete

+ new와 malloc 함수의 동작방식에는 차이가 있다.
+ 이 외에는 클래스와 객체, 그리고 생성자에대해 알고 추가하도록 하겠다.



#### 힙에 할당된 변수

+ new연산자를 이용해서 할당된 메모리 공간에도 참조자의 선언이 가능할까?
+ 흔히 사용되는 문장은 아니지만, 참조자의 선언을 통해서, 포인터 연산없이 힙 영역에 접근할 수 있다.

~~~c++
int *ptr = new int;
int &ref = *ptr;		//힙 영역에 할당된 변수에 대한 참조자 선언
ref = 20;
cout<<*ptr<<endl; 		//출력결과는 20!
~~~



> 문제 02-3 [구조체에 대한 new & delete 연산]

+ 2차원 평면상에서의 좌표를 표현할 수 잇는 구조체를 다음과 같이 정의했다.

```c++
typedef struct __Point{
	int xpos;
	int ypos;
}Point;
```

+ 위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고 (덧셈결과는 함수의 반환을 통해서 얻게 한다.)

  Point& PntAdder(const Point &p1, const Point &p2);

+ 임의의 두 점을 선언하여, 위 함수를 이용한 덧셈 연산을 진행하는 main함수를 정의해보자. 단, 구조체 Point관련 변수의 선언은 무조건 new연산자를 이용해서 진행해야 하며, 할당된 메모리 공간의 소멸도 철저해야 한다.

  + 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
  + 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?



+ 문제 풀이

~~~
#include 
~~~



제작일 : 2020-10-24

<참고 : 열혈 C++ 프로그래밍>