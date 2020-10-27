---
title: "[C++] C++에서의 구조체"
description: "[C++] C++에서의 구조체"
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## C++에서의 구조체

#### 구조체의 등장배경

+ 연관 있는 데이터를 하나로 묶으면, 프로그램의 구현 및 관리가 용이하다.
+ 구조체
  +  연관있는 데이터를 묶을 수 있는 문법적 장치



#### C++에서의 구조체 변수의 선언

+ C언어에서 구조체 변수를 선언하는 방법
  + struct Car basicCar;
  + struct Car simpleCar;
+ C++에서 구조체 변수를 선언하는 방법
  + Car basicCar;
  + Car simpleCar;
+ C++에서는 별도의 typedef선언 없이도 변수를 선언할 수 있다.



##### 구조체 예제1 - RacingCar.cpp

---------

````c++
#include <iostream>
using namespace std;

#define ID_LEN 	20
#define MAX_SPD 200
#define FUEL_STEP 	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car{
    char gamerID[ID_LEN]; 	// 소유자의 아이디
 	int fuelGauge; 			// 연료량
    int curSpeed;			//현재속도
};

void ShowCarState(const car &car){ //참조자 생성
	cout<<"소유자 ID: "<<car.gamerID<<endl;
    cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
    cout<<"현재속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
}

Void Accel(Car &car){
    if(car.fuelGauge<=0)
        return;
    else
        car.fuelFauge -=FUEL_STEP;
    
    if(car.curSpeed+ACC_STEP>=MAXSPD){
        car.curSpeed = MAX_SPD;
        return;
    }
    car.curSpeed-= BRK_STEP;
}
   
int main(void){
   	Car run99 = {"run99",100,0};
   	Accel(run99);
   	Accel(run99);
   	ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);
    
    Car sped77 = {"sped77",100,0};
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);
    return 0;  	
}
````

> 실행 결과

```
소유자 ID: run99
연료량: 96%
현재 속도: 20km/s

소유자 ID: run99
연료량: 96%
현재 속도: 10km/s

소유자 ID: run77
연료량: 98%
현재 속도: 0km/s
```

+ 위의 함수들은 구조체 Car에 종속적인 함수들이라고 말할 수 있다. 하지만 전역함수의 형태를 띠기 때문에, 이 함수들이 구조체 Car에 종속적임을 나타내지 못하고 있는 상황이다.



#### 구조체 안에 함수 삽입하기

+ 구조체 Car에 종속적인 함수들을 구조체 안에 함께 묶어버리면 어떨끼? 보다 확실한 구분이 가능할 것이다.

~~~C++
struct Car{
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;
    
    void ShowCarState(){
        cout<<"소유자 ID: "<<gamerID<<endl;//위에 선언된 gamerID에 접근
        cout<<"연료량: "<<fuelGauge<<"%"<<endl;
        cout<<"현재속도: "<<curSpeed<<"km/s"<<endl;endl;
    }
    void Accel(){
        if(fuelGauge<=0){
           	return;
        }
        else
            fuelFauge -= FUEL_STEP;
        if(curSpeed+ACC_STEP >= MAX_SPD){
            curSpeed = MAX_SPD;
            return;
        }
        curSpeed+=ACC_STEP;
    }
    void Break(){
        if(curSpeed<BRK_STEP){
            curSpeed = 0; // 위에 선언된 curSpeed에 접근
            return;
        }
        curSpeed -= BRK_STEP;
    }
};

~~~

+ 다음은 삽입되기 이전의 함수이다.

```c++
void ShowCarState(const Car &car){
	cout<<"소유자 ID: "<<car.gamerID<<endl;
    cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
}
```

+ 이 함수는 매개 변수를 통해 연산의 대상 정보를 전달 받는다. 그리고 함수 내에서도 참조자 car를 대상으로 출력을 진행한다. 
+ 구조체 안에 삽입된 함수의 정의에는 이들 정보가 존재하지 않는다.

```c++
void ShowCarState(const Car &car){
	cout<<"소유자 ID: "<<gamerID<<endl;
    cout<<"연료량: "<<fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<curSpeed<<"km/s"<<endl<<endl;
}
```

+ 함수가 구조체 내에 삽입되면서 구조체 내에 선언된 변수에 직접 접근이 가능해졌기 때문이다.



#### 예제 RacingCarFuncAdd.cpp

---------------------

```c++
#include <iostream>
using namespace std;

#define ID_LEN	20
#define MAX_SPD	200
#define FUEL_STEP		2
#define ACC_STEP		10
#define BRK_STEP		10

struct Car{
    char gamerID[ID_LEN]; 	//소유자 ID
    int fuelGauge;		//연료량
    int curSpeed;		//현재 속도	
    
    void ShowCarState(){
        cout<<"소유자 ID: "<<gamerID<<endl;
        cout<<"연료량: "<<fuelGauge<<"%"<<endl;
        cout<<"현재 속도"<<curSpeed<<"km/s"<<endl<<endl;
    }
    void Accel(){
        if(fuelGauge<=0)
            return;
        else
            fuelGauge -= FUEL_STEP;
        
        if(curSpeed+ACC_STEP>=MAX_SPD){
            curSpeed = MAX_SPD;
            return;
        }
        
        curSpeed+=ACC_STEP;
    }
    void Break(){
        if(curSpeed<BRK_STEP){
            curSpeed = 0;
            return;
        }
        curSpeed -= BRK_STEP;
    }
};

int main(void){
    Car run99 = {"run 99", 100, 0};
    run99.Accel();
    run99.Accel();
	run99.ShowCarState();
    run99.Break();
	run99.ShowCarState();
	
    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    return 0;
    
}

```

> 실행 결과

```
소유자ID: run99
연료량: 96%
현재속도: 20km/s

소유자ID: run99
연료량: 96%
현재속도: 10km/s

소유자ID: sped77
연료량: 98%
현재속도: 0km/s
```



#### 구조체 안에 enum 상수의 선언

+ 위에 예제 RacingCarFuncAdd.cpp를 보면 , 다음의 매크로 상수들이 존재한다.

~~~c++
#define ID_LEN	20
#define MAX_SPD	200
#define FUEL_STEP		2
#define ACC_STEP		10
#define BRK_STEP		10
~~~

+ 이들 상수는 구조체 Car에게만 의미가 있는 상수들이다. 
+ 이 경우 열거형 enum을 이용해서 다음과 같이 구조체 내에서만 유효한 상수를 정의할 수 있다.

```c++
struct Car{
    enum{
        ID_LEN	= 20,
        MAX_SPD	= 200,
        FUEL_STEP	=2,
        ACC_STEP	=10,
        BRK_STEP	=10
    };
    
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;
    
    void ShowCarState(){ . . . }
    void Accel(){ . . . }
    void Break(){ . . . }
};
```

+ 이름공간을 이용해 상수가 사용되는 영역을 명시하는 것도 또 다른 방법이 될 수 있다.
+ 이름 공간을 이용하면, 몇몇 구조체들 사이에서만 사용하는 상수들을 선언할 때 특히 도움이 되며, 위에서 보인 방법보다 가독성도 좋아지는 경향이 있다.

```C++
#include <iostream>
using namespace std;

namespace CAR_CONST{
	enum{
		ID_LEN 	=20,
		MAX_SPD	=200,
		FUEL_STEP	=2,
		ACC_STEP 	=10,
		BRK_STEP	=10
	};
}

struct Car{
    char gamerID[CAR_CONST::ID_LEN]; 	//소유자 ID
    int fuelGauge;		//연료량
    int curSpeed;		//현재 속도	
    
    
    void ShowCarState(){
        cout<<"소유자 ID: "<<gamerID<<endl;
        cout<<"연료량: "<<fuelGauge<<"%"<<endl;
        cout<<"현재 속도"<<curSpeed<<"km/s"<<endl<<endl;
    }
    void Accel(){
        if(fuelGauge<=0)
            return;
        else
            fuelGauge -= CAR_CONST::FUEL_STEP;
        
        if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD){
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }
        
        curSpeed+=CAR_CONST::ACC_STEP;
    }
    void Break(){
        if(curSpeed<CAR_CONST::BRK_STEP){
            curSpeed = 0;
            return;
        }
        curSpeed -= CAR_CONST::BRK_STEP;
    }
};

int main(void){
    Car run99 = {"run 99", 100, 0};
    run99.Accel();
    run99.Accel();
	run99.ShowCarState();
    run99.Break();
	run99.ShowCarState();
	
    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    return 0;
    
}
```



#### 함수는 외부로 뺄 수 있다.

+ 함수가 포함되어 있는 C++의 구조체를 보는 순간 다음의 정보들이 쉽게 눈에 들어와야 한다.
  + 선언되어 있는 변수 정보
  + 정의되어 있는 함수 정보

```C++
Struct Car{
	. . . .
	void ShowCarState();
	void Accel();
	. . . .
};

void Car::ShowCarState(){
	. . . .
}
void Car:;Accel(){
	. . . .
}

```

+ 함수의 원형선언을 구조체 안에 두고, 함수의 정의를 구조체 밖으로 빼낸다.
+ 단, 빼낸 다음 해당 함수가 어디에 정의되어 있는지에 대한 정보만 추가해주면 된다.



#### RacingCarOuterFunc.cpp

```c++
#include <iostream>
using namespace std;

namespace CAR_CONST{
	enum{
		ID_LEN 	=20,
		MAX_SPD	=200,
		FUEL_STEP	=2,
		ACC_STEP 	=10,
		BRK_STEP	=10
	};
}

struct Car{
    char gamerID[CAR_CONST::ID_LEN]; 	//소유자 ID
    int fuelGauge;		//연료량
    int curSpeed;		//현재 속도	
    
    
};

void Caf::ShowCarState(){
    cout<<"소유자 ID: "<<gamerID<<endl;
    cout<<"연료량: "<<fuelGauge<<"%"<<endl;
    cout<<"현재 속도"<<curSpeed<<"km/s"<<endl<<endl;
    void ShowCarState();
    void Accel();
    void Break();
}

void Car::Accel(){
    if(fuelGauge<=0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed+=CAR_CONST::ACC_STEP;
}
void Car::Break(){
    if(curSpeed<CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void){
    Car run99 = {"run 99", 100, 0};
    run99.Accel();
    run99.Accel();
	run99.ShowCarState();
    run99.Break();
	run99.ShowCarState();
	
    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    return 0;
    
}
```

+ 구조체 안에 함수가 정의도어 있으면 함수를 인라인으로 처리하란 의미가 내포된다.

+ 반면, 위의 예제와 같이 함수를 구조체 밖으로 빼내면 이러한 의미가 사라진다.
+ 따라서 인라인의 의미를 유지하려면 다음과 같이 키워드 inline을 이용해서 인라인 처리를 명시적으로 지시해야한다.

```c++
inline void Car:ShowCarState(){ . . . }
inline void Car::Accel(){ . . . }
inline void Car::Break(){ . . . }
```



> 문제 03-1 [구조체 내에 함수 정의하기]

+ 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.

```c++
struct Point{
	int xpos;
	int ypos;
};
```

+ 위의 구조체를 기반으로 다음의 함수를 정의하고자 한다.

```c++
void MovePos(int x, int y);			//점의 좌표 이동
void AddPoing(const Point &pos);	//점의 좌표 증가
void ShowPosition();				//현재 x,y좌표 정보 출력
```

+ 단, 위의 함수들은 구조체 안에 정의를 해서 다음의 형태로 main함수를 구성할 수 있어야 한다.

```c++
int main(void){
	Point pos1 = {12,4};
    Point pos2 = {20,30};
    
    pos1.MovePos(-7,10);
    pos1.ShowPosition();	// [5,14] 출력
    
    pos1.AddPoint(pos2);
    pos1.ShowPosition();	//[25,44] 출력
    return 0;
}
```

+ 실행결과

```
[5,14]
[25,44]
```



+ 프로그램 

```C++
#include <iostream>
using namespace std;

struct Point{
	int xpos;
	int ypos;
    void MovePos(int x, int y){
        xpos += x;
        ypos += y;
    }		//점의 좌표 이동
	void AddPoint(const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
    }	//점의 좌표 증가
	void ShowPosition(){
    	cout<<"["<<xpos<<", "<<ypos<<"]" <<endl;
    }	
};

int main(void){
	Point pos1 = {12,4};
    Point pos2 = {20,30};
    
    pos1.MovePos(-7,10);
    pos1.ShowPosition();	// [5,14] 출력
    
    pos1.AddPoint(pos2);
    pos1.ShowPosition();	//[25,44] 출력
    return 0;
}
```





제작일 : 2020-10-27

<참고 : 열혈 C++ 프로그래밍>