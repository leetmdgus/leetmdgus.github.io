---
title: "[C++] 이름공간을 배워보자..."
description: "[C++] 이름공간을 배워 보자..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## 이름공간(namespace)에 대한 소개

#### 이름공간의 등장배경

+ 프로그램이 대형화되어 가면서 이름의 충돌문제가 등장하였다. 
+ C++의 표준에서는 '이름공간(namespace)'이라는 문법을 정의해서 이러한 문제에 대한 근본적인 해결책을 제시하고 있다.



#### 이름공간의 기본 원리

+ 한 집에 승현이라는 이름의 사람이 두 명 산다면, 상황에 따라 문제가 될 수 있다. 그냥 '승현아!'라고 부르면, 어떤 승현이를 부르는지 알 수 없기 때문이다. 그러나 서로 살고 있는 집이 다르다면 문제 될 것이 없다. '104동에 사는 승현'이와 '504호에 사는 승현'이로 구분되기 때문이다.
+ 이것이 이름공간의 기본 원리이다. 아래는 앞서 이야기한 이름충돌의 문제점을 간단히 코드로 옮겨놓은 것이다.

~~~c++
#include <iostream>

void SimpleFunc(void){
	std::cout<<"GREEN이 정의한 함수"<<std::endl;
}
void SimpleFunc(void){
	std::cout<<"Tmdgus가 정의한 함수"<<std::endl;
}
int main(void){
	SimpleFunc();
	return 0;
}
~~~

+ 위의 예제는 이름과 파라미터가 동일하기 때문에 문제가 됨을 알 수 있다.
+ 아래의 예시를 통해 실제 이름공간과 관련된 내용을 설명하겠다.

~~~c++
#include <iostream>

namespace Green{
	void SimpleFunc(void){
		std::cout<<"Green이 정의한 함수"<<std:;endl;
	}
}
namespace Tmdgus{
	void SimpleFunc(void){
		std::cout<<"Tmdgus이 정의한 함수"<<std:;endl;
	}
}

int main(void){
	Green::simpleFunc();
	Tmdgus::simpleFunc();
    return 0;
}
~~~

> 실행결과

~~~
Green이 정의한 함수
Tmdgus이 정의한 함수
~~~

+ 이런식으로 이름공간을 만들고 이 안에 함수를 정의하거나 변수를 선언한다면, 이름충돌은 발생하지 않는다.

+ 위 예제에서 사용된 **연산자 ::을 가리켜 '범위지정 연산자(scope resolution operator)**'라 한다.



#### 이름공간 기반의 함수 선언과 정의의 구분

+ 보통 함수는 선언과 정의를 분리하는 것이 일반적이다.
+ '함수의 선언'은 헤더파일에 지정하고, '함수의 정의'는 소스파일에 저장하는 것이 보통이다.
+ 다음예제를 통해 이름공간 기반에서 함수의 선언과 정의를 구분하는 방법을 확인해보자.

~~~C++
#include <iostream>

namespace Green{
	void SimpleFunc(void);
}

namespace Tmdgus{
	void SimpleFunc(void);
}

int main(void){
	Green::SimpleFunc();
	Tmdgus::SimpleFunc();
	return 0;
}

void Green::SimpleFunc(void){
	std:;cout<<"Green이 정의한 함수"<<std::endl;
}

void Tmdgus::SimpleFunc(void){
	std:;cout<<"Tmdgus이 정의한 함수"<<std::endl;
}
~~~

> 실행결과

~~~
Green이 정의한 함수
Tmdgus이 정의한 함수
~~~

+ 참고로 **동일한 이름공간에 정의된 함수를 호출할 때는 이름공간을 명시할 필요가 없다.**



#### 이름공간의 중첩

+ 이름공간은 다른 이름공간 안에 삽입될 수 있다.

~~~C++
namespace Parent{
	int num = 2;
	
	namespace SubOne{
		int num = 3;
	}
	
	namespace SubTwo{
		int num = 4;
	}
}
int main(void){
    std::cout<<Parent::num<<std::endl;
    std::cout<<Parent::SubOne::num<<std::endl;
    std::cout<<Parent::SubTwo::num<<std::endl;
    return 0;
}
~~~

> 실행결과

~~~
2
3
4
~~~



#### std::cout, std::cin, std::endl

+ :: 연산자의 의미를 기반으로 다음 세가지가 뜻하는 바를 확인하겠다.

  ​	std::cout

  ​	std::cin

  ​	std::endl

+ 순서대로

  "이름공간 std에 선언된 cout"

  "이름공간 std에 선언된 cin"

  "이름공간 std에 선언된 endl"

+ 헤더파일 <iostream>에 선언되어 있는 cout, cin 그리고 endl은 이름공간 std 안에 선언되어 있다.

+ 이름충돌을 막기 위해서, C++표준에서 제공하는 다양한 요소들은 이름공간 std 안에 선언되어 있다.



#### using을 이용한 이름공간의 명시

~~~c++
#include <iostream>

namespace Hybrid{
	void HyFunc(void){
		std::cout<<"So simple function!"<<std::endl;
		std::cout<<"In namespace Hybrid!"<<std::endl;
	}
}

int main(void){
	using Hybrid::HyFunc;
	HybFunc();
	return 0;
}
~~~

> 실행 결과

~~~
So simple function!
In namespace Hybrid!
~~~

+ 다음 예제를 보면 Hybrid라는 이름 공간안에 선언된 함수를 범위지정없이 그냥 호출할 수 있음을 알 수 있다.
+ 위 예제에서 보이듯이 다음의 선언은 'HybFunc를 이름공간 Hybrid에서 찾으라'는 일종의 선언이다.

~~~C++
using Hybrid::HybFunc;
~~~

+ 이때, HyFunc는 함수의 이름도 될 수 있고, 변수의 이름도 될 수 있다.
+ 프로그램 전체영역에 효력을 미치게 하려면 전역변수와 마찬가지로 함수 밖에 선언을 해야 한다.

+ 다음을 통해 **이름공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략**을 명령할 수 있다.

~~~c++
using namespace std;
~~~

+ 예제를 통해 확인하겠다.

```
#incldue <iostream>
using namespace std;

int main(void){
	int num = 20;
	cout<<"Hello World!"<<endl;
	cout<<"Hello"<<"World!"<<endl;
}
```

+ 물론 using namespace선언은 매력적이나, 이름충돌이 발생할 확률이 상대적으로 높아진다. 따라서 무조건 편한 것을 선호하기 보다는 상황을 판단해서 적절히 혼용하는 자세가 필요하다.



#### 이름공간의 별칭지정

+ 상황에 따라서는 다음과 같이 이름공간이 과도하게 사용될 수 있다.

~~~C++
namespace AAA{
	namespace BBB{
		namespace CCC{
			int num1; 
			int num2;
		}
	}
}
~~~

+ 이러한 경우에는 AAA::BBB::CCC와 같은 이름에 별칭을 줄 수 있다.

~~~
namespace ABC = AAA::BBB::CCC;
~~~



#### 범위지정 연산자(Scope Resilution Operator)의 또 다른 기능

+ 지역변수의 이름이 전역변수의 이름과 같을 경우, 전역변수는 지역변수에 의해 가려진다는 특징이 있다. 
+ 다음 코드를 보자.

~~~c++
int val = 100; //전역변수

int SimpleFunc(void){
	int val = 20; // 지역변수
	val+=3; // 지역변수 val의 값 3증가
}
~~~

+ 그렇다면 함수내에서 전역변수 val에 접근하려면 '범위지정 연산자'를 사용하면 된다.

~~~C++
int val = 100;

int SimpleFunc(void){
	int val = 20;
	val +=3; //지역변수 val의 값 3 증가
	::val +=7; //전역변수 val의 값 7증가
}
~~~



이로써 네임스페이스에 대한 모든 내용이 끝났다. 

제작일 : 2020-10-16

<참고 : 열혈 C++ 프로그래밍>