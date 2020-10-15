---
title: "[C++] 매개변수의 디폴드 값을 배워보자..."
description: "[C++] 매개변수의 디폴트 값을 배워 보자..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false

---

## 매개변수의 디폴트값(Default Value)

+ C++의 함수에는 '디폴트 값'이라는 것을 설정할 수 있다.
+ 여기서 '디폴트 값'이란 '기본적으로 설정되어 있는 값'을 의미한다.

```C++
int MyFucOne(int num = 7){
    return num+1;
}
int MyFuncTwo(int num1 = 5, int num2 = 7){
    return num1+num2;
}
```

여기서 MyFuncOne의 매개변수 선언은 다음과 같다.

```C++
int num = 7
```

+ 그리고 이는 다음의 의미를 지니고, 아래의 두 호출문은 완전히 동일하다.

> 함수호출 시 인자를 전달하지 않으면 7이 전달된 것으로 간주하겠다.

```C++
MyFuncOne();  // 7이 전달된 것으로 간주!!
MyFuncOne(7);
```

이어서 MyFunTwo의 매개변수 선언은 다음과 같다.

```
int num1 = 5, int num2 = 7;
```

> 함수 호출 시 인자를 전달하지 않으면 num1에 5가, num2에 7이 전달된 것으로 간주하겠다.

+ 따라서 아래 두 호출문은 완전히 동일하다.

```
MyFuncOne();    //5와 7이 전달된 것으로 간주!!!
MyFuncTwo(5,7);
```

자세한 건 예제를 통해 확인해보자.



#### DefaultValue 예제

```c++
#include <iostream>
int Adder(int num1 = 1, int num2 = 2){
	return num1+num2;	
}

int main(void){
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3,5)<<std::endl;
	return 0;
}
```

> 실행 결과

```
3
7
8
```

+ 매개변수에 디폴트 값이 설정되어 있으면, 전달되는 인자는 왼쪽에서부터 채워져 나가고, 부족분은 디폴트 값으로 채워진다.



#### 디폴트 값은 함수의 선언 부분에만 표현하면 된다.

```C++
#include <iostream>
int Adder(int num=1,int num2 = 2);

int main(void){
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3,5)<<std::endl;
	return 0;
}

int Adder(int num1, int num2){
	return num1+num2;	
}
```

+ 함수의 원형을별도로 선언하는 경우, 매개변수의 디폴트값은 **함수의 원형 선언**에만 위치시켜야 한다.



#### 부분적 디폴트 값 설정

다음과 같이 정의된 함수가 있다고 가정해보자.

~~~c++
int YourFunc(int num1, int num2, int num3){ . . . }
~~~

+ 이러한 경우, 다음과 같이 디폴트 값을 전부 지정할 수 있지만, 

~~~c++
int YourFunc(int num1 = 3, int num2 = 5, int num3 = 7){ . . . }
~~~

+ 다음과 같이 일부분만 디폴트 값을 지정할 수도 잇다.

~~~c++
int YourFunc(int num1, int num2 = 5, int num3 = 7){ . . . }
~~~

+ 그리고 이렇게 일부분만 디폴트 값을 지정하면, 다음의 형태로도 함수 호출이 가능하다. 

```
YourFunc(10);     //YourFunc(10,5,7);
YourFunc(10,20);  //YourFunc(10,20,7);
```

+ 하지만, 다음과 같이 **오른쪽 매개변수의 디폴트 값을 비우는 형태로는 디폴트 값을 지정할 수 없다.**

```c++
int YourFunc(int num1 = 3, int num2 = 5, int num3){ . . . }
```

+ 반드시 오른쪽 매개변수의 디폴트 값부터 채우는 형태로 정의해야 한다. 즉, 다음의 정의는 모두 유효하다.

```C++
int YourFunc(int num1, int num2, int num3 = 30){ . . . }
int YourFunc(int num1, int num2=20, int num3 = 30){ . . . }
int YourFunc(int num1=10, int num2=20, int num3 = 30){ . . . }
```

+ 다음의 정의는 모두 유효하지 않다.

```C++
int YourFunc(int num1=10, int num2, int num3 { . . . }
int YourFunc(int num1=10, int num2=20, int num3){ . . . }
```

> 함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문이다.



### 문제 [매개 변수의 디폴트 값]

#### 문제 1

+ 아래 예제에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정'형태가 아닌, '함수오버로딩'의 형태로 재 구현해보자. 물론 main함수는 변경하지 않아야 하며, 실행결과도 동일해야 한다.

> 예제

```
#include <iostream>
int BoxVolume(int length, int width = 1, int height = 1);

int main(void){
	std::cout<<"[3,3,3] : "<<BoxVolume(3,3,3)<<std::endl;
	std::cout<<"[5,5,D] : "<<BoxVolume(5,5)<<std::endl;
	std::cout<<"[7,D,D] : "<<BoxVolume(7)<<std::endl;
	// std::cout<<"[D,D,D] : "<<boxVolume()<<std::endl;
	return 0;
}

int BoxVolume(int length, int width, int height){
	return length*width*height;
}
```

>실행결과

```
[3,3,3] : 27 
[5,5,D] : 25
[3,D,D] : 7
```



> 정답

~~~c++
#include <iostream>
int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width );
int BoxVolume(int length);

int main(void) {
	std::cout << "[3,3,3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5,5,D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7,D,D] : " << BoxVolume(7) << std::endl;
	// std::cout<<"[D,D,D] : "<<boxVolume()<<std::endl;
	return 0;
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int BoxVolume(int length, int width) {
	int height = 1;
	return length * width * height;
}

int BoxVolume(int length) {
	int width = 1, height = 1;
	return length * width * height;
}
~~~



#### 문제 2

+ 다음과 같은 형태로의 함수 오버로딩은 문제가 있다.  어떠한 문제가 있는지 설명해보자.

```c++
int SimpleFunc(int a = 10){
	reuturn a+1;
}

int SimpleFunc(void){
	return 10;
}
```

> 인자를 전달하지 않으면서 함수를 호출하는 경우 두 함수 모두 호출조건을 만족하기 때문에 컴파일 에러가 발생한다.



오늘은 매개변수(파라미터)의 디폴트값에 대해 배워보았다.



제작일 : 2020-10-15

<참고 : 열혈 C++ 프로그래밍>