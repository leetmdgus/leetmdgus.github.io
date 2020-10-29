---
title: "[C++] 클래스와 객체"
description: "[C++] 클래스와 객체"
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## 클래스와 객체

+ 접근 제어 지시자( 접근제어 레이블)

  + public	//어디서든 접근 허용
  + protected    //상속관계에 놓여있을 때, 유도 클래스에서의 접근 허용
  + private        // 클래스 내(클래느 내에 정의된 함수)에서만 접근 허용
  + 오늘은 public과 private에 대해서만 이야기 하겠다.

  

+ RacingCarClassBase.cpp

  ```c++
  #include <iostream>
  #include <cstring>
  using namespace std;
  
  namespace CAR_CONST{
      enum{
          ID_LEN = 20, MAX_SPD = 200, FUEL_STEP =2,
          ACC_STEP = 10, BRK_STEP = 10 
      };
  }
  
  class Car{
      private:
          char gamerID[CAR_CONST::ID_LEN];
          int fuelGauge;
          int curSpeed;
      public:
          void InitMembers(const char * ID, int fuel);
          void ShowCarState();
          void Accel();
          void Break();
  };
  
  void Car::InitMembers(const char * ID, int fuel){
      strcpy(gamerID, ID);
      fuelGauge = fuel;
      curSpeed = 0;
  }
  void Car::ShowCarState(){
  	cout<<"user ID: "<<gamerID<<endl;
      cout<<"fuel gauge: "<<fuelGauge<<"%"<<endl;
      cout<<"Car Speed: "<<curSpeed<<"km/s"<<endl<<endl;
  }
  void Car::Accel(){
      if(fuelGauge<=0)
          return;
      else
          fuelGauge -=CAR_CONST::FUEL_STEP;
  
      if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD){
          curSpeed = CAR_CONST::MAX_SPD;
          return;
      }
      curSpeed += CAR_CONST::ACC_STEP;
  }
  void Car::Break(){
      if(curSpeed<CAR_CONST::BRK_STEP){
          curSpeed = 0;
          return;
      }
      curSpeed -= CAR_CONST::BRK_STEP;
  }
  
  int main(void){
      Car run99;
      run99.InitMembers("run99",100);
      run99.Accel();
      run99.Accel();
      run99.Accel();
      run99.ShowCarState();
      run99.Break();
      run99.ShowCarState();
  
      return 0;    
  }
  
  ```

  > 실행결과

  ```
  user ID: run99
  fuel gauge: 94%
  Car Speed: 30km/s
  
  user ID: run99
  fuel gauge: 94%
  Car Speed: 20km/s
  ```

  + 접근제어 지시자 A가 선언되면, 그 이후에 등장하는 변수나 함수는 A에 해당하는 범위 내에서 접근이 가능하다.
  + 함수의 정의를 클래스 밖으로 빼도, 이는 클래스의 일부이기 때문에, 함수 내에서는 private으로 선언된 변수에 접근이 가능하다.
  + 키워드 class을 이용해서 정의한 클래스에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 private으로 선언된다.



+ 레이블
  + 접근제어 지시자의 뒤에는 세미콜론이 아닌 콜론이 붙는데, 이는 접근지시자가 특정 위치정보를 알리는 레이블'라벨'이기 때문이다. 우리가 알고 있는, siwitch문에 사용되는 case도 레이블이기 때문에 콜론이 붙는다.



+ 용어 정리 : 객체, 멤버변수, 멤버함수
  + 객체(Instance)
    + 위 예제에서 run99는 변수가 아닌 객체이다.
    + 정확한 내용은 객체지향을 알아보면서 진행한 후 추후 추가하겠다.
  + 멤버변수
    + 클래스를 구성하는 (클래스 내에 선언된) 변수를 가리켜 멤버변수라 한다.
  + 멤버함수
    + 클래스를 구성하는(클래스 내에 정의된) 함수를 가리켜 멤버함수라고 한다.



+ C++에서의 파일 분할

  + 어떠한 프로그램이건 하나의 파일에 모든 것을 담진 않는다. 특히  C++은 클래스 별로 헤더파일과 소스파일을 생성해서 클래스의 선언과 정의를 분리하는 경우가 많기 때문에 많은 수의 파일이 만들어진다.

  + 다음은 클래스를 대상으로, 파일을 나누는 기준이다.

    + Car.h // 클래스의 선언을 담는다.
    + Car.cpp // 클래스의 정의(멤버함수의 정의)를 담는다.

  + 여기서 말하는 클래스의 선언은 다음과 같다. 

    ```c++
    class Car{
        private:
            char gamerID[CAR_CONST::ID_LEN];
            int fuelFauge;
        	int curSpeed;
        public:
        	void InitMembers(const char * ID, int fuel);
        	void ShowCarState();
        	void Accel();
        	void Break();
    }
    ```

    + 이는 컴파일러가 Car클래스와 관련된 문장의 오류를 잡아내는데 필요한 최소한의 정보로써, 클래스를 구성하는 외형적인 틀을 보여준다. 이를 가리켜 클래스의 선언(declaration)이라고 한다.

      ```c++
      int main(void){
      	Car run99;
      	run99.fuelGauge = 100;    // fuelGauge가 private임을 확인하고 에러를 발생
      	run99.Accel(20);          //Accel 함수의 매개변수가 void형임을 알고 에러를 발생
      }	
      ```

  + 클래스의 정의(definition)에 해당하는 다음 함수의 정의는 다른 문장의 컴파일에 필요한 정보를 가지고 있지 않다. 

    ```c++
    void Car:InitMembers(const char * ID, int fuel){ . . . }
    void Car::ShowCarState(){ . . . }
    void Car::Accel(){ . . . }
    void Car::Break(){ . . . }
    ```

    클래스의 선언은 헤더파일에 저장을 해서 필요한 위치에 쉽게 포함될 수 있도록 해야하며, 클래스의 정의는 소스파일에 저장해서 컴파일이 되도록 하면 된다.

  

  + Car.h

    ```c++
    #ifndef __CAR_H__
    #define __CAR_H__
    
    namespace CAR_CONST{
        enum{
            ID_LEN = 20, MAX_SPD = 200, FUEL_STEP =2,
            ACC_STEP = 10, BRK_STEP = 10 
        };
    }
    
    class Car{
        private:
            char gamerID[CAR_CONST::ID_LEN];
            int fuelGauge;
            int curSpeed;
        public:
            void InitMembers(char * ID, int fuel);
            void ShowCarState();
            void Accel();
            void Break();
    };
    
    #endif
    ```

  + Car.cpp

    ```c++
    #include <iostream>
    #include <cstring>
    #include "Car.h"
    using namespace std;
    
    void Car::InitMembers(const char * ID, int fuel){
        strcpy(gamerID, ID);
        fuelGauge = fuel;
        curSpeed = 0;
    }
    void Car::ShowCarState(){
    	cout<<"user ID: "<<gamerID<<endl;
        cout<<"fuel gauge: "<<fuelGauge<<"%"<<endl;
        cout<<"Car Speed: "<<curSpeed<<"km/s"<<endl<<endl;
    }
    void Car::Accel(){
        if(fuelGauge<=0)
            return;
        else
            fuelGauge -=CAR_CONST::FUEL_STEP;
    
        if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD){
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }
        curSpeed += CAR_CONST::ACC_STEP;
    }
    void Car::Break(){
        if(curSpeed<CAR_CONST::BRK_STEP){
            curSpeed = 0;
            return;
        }
        curSpeed -= CAR_CONST::BRK_STEP;
    }
    
    ```

  + RacingMain.cpp

    ```c++
    #include "Car.h"
    
    int main(void){
        Car run99;
        run99.InitMembers("run99",100);
        run99.Accel();
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();
    
        return 0;    
    }
    ```

    > error 발생!
    >
    > ​	undefined reference to `WinMain@16'
    >
    > ​	ctrl +s 를 누른후 실행하는 방법이 있다고 하는데 해결되지 않는다. 나중에 확인해 볼 것 .



+ 인라인 함수는 헤더파일에 함께 넣어야 한다.

  + 앞서 보인 파일 분할 예제에서 Car.cpp에 정의된 함수 ShowCarState를 다음과 같이 인라인화 한 다음에 그대로 Car.cpp에 두면 컴파일 에러가 발생한다.

  ```c++
  inline void Car::ShowCarStae(){
  	cout<<"user ID: "<<gamerID<<endl;
      cout<<"fuel gauge: "<<fuelGauge<<"%"<<endl;
      cout<<"Car Speed: "<<curSpeed<<"km/s"<<endl<<endl;
  }
  ```

  + 인라인 함수의 특징은 다음과 같다.
    + 컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 함



+ 문제 03-2 [클래스의 정의]

  + 계산기 기능의 Carculator 클래스를 정의해보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눈셈이며, 연산을 할 때마다 어떠한 연산을 몇 번 수행햇는지 기록되어야 한다.아래의 main함수와 실행의 예에 부합하는 Calculato클래스를 정의하면 된다. 단, 멤버변수는 private으로, 멤버함수는 public으로 선언하자. 

  + main 함수

    ```c++
    int main(void){
    	Carculator cal;
    	cal.Init();
    	cout<<"3.2 + 2.4 = " <<car.Add(3.2, 2.4)<<enl;
    	cout<<"3.5 / 1.7 = " <<cal.Div(3.5,1.7)<<endl;
    	cout<<"2.2 - 1.5 = " <<cal.Min(2.2,1.5)<<endl;
    	cout<<"4.9 / 1.2 = " <<cal.Div(4.9, 1.2)<<endl;
    	cal.ShowOpCount();
    }
    ```

  + 실행의 예

    ```
    3.2 + 2.4 = 5.6
    3.5 / 1.7 = 2.05882
    2.2 - 1.5 = 0.7
    4.9 / 1.2 = 4.08333
    add: 1 min: 1 mul: 0 div: 2
    ```

  + 문제 풀이

    ```c++
    #include <iostream>
    
    using namespace std;
    
    class Calcul{
        private:
            int addnum;
            int minnum;
            int divnum;
            int mulnum;
    
        public:
            void Init();
            double Add(double num1, double num2);
            double Min(double num1, double num2);
            double Mul(double num1, double num2);
            double Div(double num1, double num2);
            void ShowOpCount();
    };
    
    void Calcul::Init(){
            addnum = 0;
            minnum = 0;
            divnum = 0;
            mulnum = 0;
    }
    
    double Calcul::Add(double num1, double num2){
        addnum += 1;
        return num1+num2;
    }
    double Calcul::Min(double num1, double num2){
        minnum +=1;
        return num1-num2;  
    }
    double Calcul::Mul(double num1, double num2){
        mulnum +=1;
        return num1*num2;
    
    }
    double Calcul::Div(double num1, double num2){
        divnum +=1 ;
        return num1/num2;
    
    }
    void Calcul::ShowOpCount(){
        cout<<"add: "<<addnum<< "min: "<<minnum<< "mul: "<<mulnum<<"div: "<<divnum<<endl;
    }
    
    ```



+ 문제 2

  + 문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자. 이 클래스의 두 가지 기능은 다음과 같다. 
    + 문자열 저장
    + 문자열 출력
  + 아래의 main함수와 실행의 예에 부합하는 Printer 클래스를 정의하되, 이번에도 역시 멤버변수는 private으로 멤버함수는 public으로 선언하자.

  ```c++
  int main(void){
  	Printer pnt;
      pnt.SetString("Hello world!");
      pnt.ShowString();
      
      pnt.SetString("I love C++");
      pnt.ShowString();
      return 0;
  }
  ```

  + 실행의 예

  ```
  Hello world!
  I love C++
  ```

  + 문제 풀이

  ```c++
  #include <iostream>
  #include <cstring>
  
  using namespace std;
  
  
  class Printer{
      private:
          char str[50];
      public:
          void SetString(const char * st);
          void ShowString();
  };
  
  void Printer::SetString(const char * st){
      strcpy(str, st);
  }
  void Printer::ShowString(){
      cout<<str<<endl;
  }
  ```

  



제작일 : 2020-10-29

<참고 : 열혈 C++ 프로그래밍>