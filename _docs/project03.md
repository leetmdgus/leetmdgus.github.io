---
title: "[C++] '객체지향연습..."
description: "[C++] '코레일톡을 구현해보자..."
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---

## 코레일톡

+ 기능:
  + 역명검색기능(출발 / 도착 바꿔서 바로 선택가능)
  + 날짜 시간 입력
    + 오늘을 기준으로 하는 일주일 달력 제공
  + 열차조회결과
    + 일반식 특실 좌석 현황 조회 및 가격 확인
  + 열차표확인
    + 출발 도착점
    + 출발 도착시간
    + 열차이름
    + 객실위치
    + 발권일시
  + 실시간 운행 정보

+ 구조

  + 발권
    + 출발 지점, 도착 지점 선택
    + 날짜 선택
    + 인원 선택(어른 ㅁ명, 아이 ㅁ명)
    + 열차정보 확인
    + 객실 선택
  + 승객
    + 표보기
    + 환불하기
    + 표사기
  + 열차 정보

  

+ 코드 구현

  1. 발권하기 2. 발권한 표 확인 3. 환불하기 4. 열차 정보 확인

```c++
#include <iostream>
using namespace std;

class Train{
private:
    int adult_num;
    int child_num;
    int price;
    string train_name;
    int departure_hour;
    int departure_minute;
    int arrival_hour;
    int arrival_minute;
    string arrival_spot;
    string departure_spot;

public:
    Train();
    Train(int adult);
    Train(int adult, int child);

    void ticketing();
    void show_ticket() const;
    void train_info() const;      
    void refund();  
};

Train::Train(): adult_num(1),child_num(0), train_name("NULL"){}
Train::Train(int adult): adult_num(adult), child_num(0),train_name("NULL"){}
Train::Train(int adult, int child): adult_num(adult),child_num(child),train_name("NULL"){}

void Train::ticketing(){
    cout<<"departure spot (Seoul / Suwon)"<<endl;
    cin>>departure_spot;
    cout<<"arrival spot (Busan / Busan)" <<endl;
    cin>> arrival_spot;  
    
    int time_choice;
    if(departure_spot == "Seoul"){
        cout<<"1. [" <<departure_spot<<" -> "<<arrival_spot<<"]"<<"09:10 ~ 11:10 [KTX]"<<endl;
        cout<<"2. [" <<departure_spot<<" -> "<<arrival_spot<<"]"<<"13:30 ~ 15:30 [KTX]"<<endl;
        cout<<"3. [" <<departure_spot<<" -> "<<arrival_spot<<"]"<<"16:00 ~ 18:00 [KTX]"<<endl;
        cout<<"4. ["<<departure_spot<<" -> "<<arrival_spot<<"]"<<"19:10 ~ 21:10 [KTX]"<<endl;
        cout<<"Please choose you want number";
        cin>> time_choice;
        switch (time_choice)
        {
        case 1:
            departure_hour = 9;
            departure_minute = 10;
            train_name = "KTX";
            break;
        case 2:
            departure_hour = 13;
            departure_minute = 30;
            train_name = "KTX";
            break;
        case 3:
            departure_hour = 16;
            departure_minute = 0;
            train_name = "KTX";
            break;
        case 4:
            departure_hour = 19;
            departure_minute = 10;
            train_name = "KTX";
            break;
        default:
            break;
        }
    }
    else if(departure_spot == "Suwon"){
        cout<<"1. ["<<departure_spot<<" -> "<<arrival_spot<<"]"<<"17:00 ~ 19:00 [KTX]"<<endl;
        cout<<"2. ["<<departure_spot<<" -> "<<arrival_spot<<"]"<<"20:00 ~ 00:00 [KTX]"<<endl;
        cout<<"Please choose you want time: ";
        cin>> time_choice;
        switch (time_choice)
            {
            case 1:
                departure_hour = 9;
                departure_minute = 0;
                train_name = "KTX";  
                break;
            case 2:
                departure_hour = 13;
                departure_minute = 0;
                train_name = "KTX";
                break;
            default:
                break;
            }
    }

    departure_hour = departure_hour;
    departure_minute = departure_minute;
    if(departure_hour >= 22){
        arrival_hour = departure_hour + 2 - 24;
    }
    else{
        arrival_hour = departure_hour +2;
    }
    arrival_minute = departure_minute;

    price = adult_num * 300000 + child_num * 100000;

}

void Train::show_ticket() const{
    if(train_name == "NULL"){
        cout<<"Please buy your ticket"<<endl;
        return;
    }

    cout<<"================================"<<endl;
    cout<<"your ticket infomation"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"departure spot: " <<departure_spot<<endl;
    cout<<"arrival spot: "<<arrival_spot<<endl;
    cout<<"adult num: "<<adult_num<<" child num: "<<child_num<<endl;
    cout<<"your train: "<<train_name<<endl;
    cout<<"departure time "<<departure_hour<<":"<<departure_minute<<endl;
    cout<<"arrival time "<<arrival_hour<<":"<<arrival_minute<<endl;
    cout<<"price: "<<price<<endl;
    cout<<"================================"<<endl;
}

void Train::train_info() const{
    cout<<"1. [Seoul -> Busan] 09:10 ~ 11:10 [KTX]"<<endl;
    cout<<"2. [Seoul -> Busan] 13:30 ~ 15:30 [KTX]"<<endl;
    cout<<"3. [Seoul -> Busan] 16:00 ~ 18:00 [KTX]"<<endl;
    cout<<"4. [Seoul -> Busan] 19:10 ~ 21:10 [KTX]"<<endl;    
    cout<<"5. [Suwon -> Busan] 17:00 ~ 19:00 [KTX]"<<endl;
    cout<<"6. [Suwon -> Busan] 20:00 ~ 00:00 [KTX]"<<endl;
}

void Train::refund(){

}

int main(){
    Train user1(3,4);
    user1.ticketing();
    user1.show_ticket();
    user1.train_info();

    return 0;
}
```






최종 수정일 : 2020-11-19

