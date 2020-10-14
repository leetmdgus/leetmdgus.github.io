---
title: "[C++] 함수의 오버로딩을 배워보자..."
description: "[C++] 함수의 오버로딩을 배워 보자..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## 함수 오버로딩(Function Overloading)

#### 함수 오버로딩의 이해

+ C언어에서는 아래와 같이 동일한 이름의 함수가 정의되는 것을 허용하지 않는다. 두
+ 즉,  함수의 이름이 같기 때문에 컴파일 오류가 발생한다.

~~~
int MyFunc(int num){
	num ++;
	return num;
}
int MyFunc(int a, int b){
	return a+b;
}
~~~

+  하지만 C++에서는 다른데 아래의 예시와 함께 설명하겠다.

~~~c++
int main(void){
	MyFunc(20) //MyFunc(int num)호출  
	MyFunc(30,40); //int MyFunc(int a, int b) 호출
    return 0;0
}
~~~

+ C++에서는 함수 호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 하다. 즉,  매개변수의 선언 형태가 다르면, 동일한 이름의 함수 정의를 허용한다.
+ 이러한 형태의 함수 정의를  '함수 오버로딩(Function Overloading)'이라 한다.

> C언어에서 오버로딩을 허용하지 않는 이유는 무엇인가?

> + MyFunc(30,40);
>
> C++과 C는 다음과 같이 판단하고 함수를 찾는다. 
>
> C++에서는 "두 개의 int형 정수를 인자로 전달받을 수 있는 MyFunc이라는 이름의 함수를 찾아야겠군!"이라고 판단하여 함수를 찾지만, C에서는 "MyFunC 어디 있어? MyFunc!"라고 생각한다. 따라서 C언어에서는 함수의 오버로딩이 불가능하며, 이를 문법적으로 허용하지도 않는다.



#### 함수 오버로딩의 예

함수의 오버로딩이 가능 하려면 매개 변수의 선언이 달라야 한다. 예를 들어 다음 두 함수는 오버로딩이 가능하다. 

```c++
int MyFuc(char c){...}
int MmyFunc(int n){...}
```

+ 매개 변수의 자료형이 다르므로, **전달인자의 자료형**을 통해서 호출할 함수의 구분이 가능하기 때문이다.

마찬가지로 다음 두 함수도 오버로딩이 가능하다.

```c++
int MyFunc(int n){...}
int MyFunc(int n1, int n2){...}
```

+ 이 경우는 매개변수의 개수가 다르므로, 전달되는 **인자의 개수**를 통해서 호출할 함수의 구분이 가능하기 때문이다.

정리하자면 함수의 오버로딩이 가능하려면 다음 조건을 만족해야 한다.

> "매개변수의 자료형 또는 개수가 다르다."

반면, 다음은 대표적인, 잘못된 함수 오버로딩의 예이다.

```c++
Void MyFunc(int n){...}
int MyFunc(int n){...}
```

+ 위의 두 함수는 반환형이 다르다. 하지만 반환형은 함수 호출 시, 호출되는 함수를 구분하는 기준이 될 수 없다. 



#### 함수 오버로딩 예제

```C++
#include <iostream>

void MyFunc(void){
	std::cout << "MyFunc(void) called"<<std::endl;
}

void MyFunc(char c){
	std::cout<<"MyFunc(char c) called" <<std::endl;
}

void MyFunc(int a, int b){
	std::cout << "MyFunc(int a, int b) called"<<std::endl;
}

int main(void){
	MyFunc();
	MyFunc('A');
	MyFunc(12,13);
	return 0;
}
```

> 실행 결과

```
MyFunc(void) called
MyFunc(char c) called
MyFunc(int a, int b) called
```



#### 문제 함수 오버로딩

+ 다음 main 함수에서 필요로 하는 swap 함수를 오버로딩 해서 구현해보자.

```c++
int main(void) {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout<< ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;
	return 0;
}
```

> 실행의 예

```
30 20
Z A
5.555 1.111
```

> 답

```c++
void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void swap(char *a, char *b){
	char c;
	c = *a;
	*a = *b;
	*b = c;
	
}
void swap(double* a, double* b) {
	double c;
	c = *a;
	*a = *b;
	*b = c;
}
```

이로써 우리는 오늘 함수 오버로딩에 대한 개념을 알아보았다.



글 제작일 : 2020-10-14

<참고 : 열혈 C++ 프로그래밍>