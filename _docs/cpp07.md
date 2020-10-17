---
title: "[C++] OOP 단계별 프로젝트 1단계"
description: "[C++] OOP 단계별 프로젝트 1단계"
tags: 
 - "C++"
 - "객체지향"
 - "프로그래밍언어"
feedback: false
---
## OOP 단계적 프로젝트 1단계

#### 프로젝트 1단게의 도입

1. 프로그램 설명

   + 우리가 구현하려고 하는 것은 '은행계좌 관리 프로그램'이다. 프로젝트 01단계에서는 C스타일로 수현하는 것을 목표로 한다. 구현할 기능은 다음과 같다.
     + 기능 1. 계좌 개설
     + 기능 2. 입금
     + 기능 3. 출금
     + 기능 4. 전체고객 잔액 조회
   + 그리고 프로그램을 간결하게 하기 위해 몇 가지 가정을 하겠다 가정의 내용은 다음과 같다.
     + 통장의 계좌번호는 중복되지 아니한다. (중복검사 하지 않겠다는 뜻)
     + 입금 및 출금액은 무조건 0보다 크다.(입금 및 출금액의 오류는 검사하지 않겠다는 뜻)
     + 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액, 이렇게 세 가지만 저장 및 관리한다.
     + 둘 이상의 고객정보 저장을 위해 배열을 사용한다.
     + 계좌번호는 정수의 형태이다.

   

   >프로그램 구현

   ~~~c++
   #include <iostream>
   
   using namespace std;
   
   int viewMenu();
   void createAccount();
   void deposit();
   void withdraw();
   void viewAccount();
   
   typedef struct NewAccount{
       char* user_name;
       int user_account;
       int user_amount;
   
   }Account;
   
   int user_num = 0;
   Account user[100] ={0, };
   
   int main(){
       while(1){
           int choice = ViewMenu();
           switch (choice){
               case 1:
                   CreateAccount(); continue;
               case 2:
                   Deposit(); continue;
               case 3:
                   Withdraw(); continue;
               case 4:
                   ViewAccount(); continue;
               case 5:
                   cout<<"[END]"<<endl;
                   return 0; 
               default:
                   cout<<"it is not defined"<<endl; continue;
                   cout<<"==========================="<<endl;
           }
       }
       
       return 0;
   }
   
   
   
   int viewMenu(){
       int choice;
       cout<<" [MENU]                    "<<endl;
       cout<<" 1. CREATE ACCOUNT         "<<endl;
       cout<<" 2. DEPOSIT                "<<endl;
       cout<<" 3. WITHDRAW              "<<endl;
       cout<<" 4. VIEW AMOUNT            "<<endl;
       cout<<" 5. TERMINATE              "<<endl; 
       cout<<" choice: " ; cin>>choice;
       cout<<"==========================="<<endl;
   
       return choice;
   }

   void createAccount(){
       cout<<" [CREATE ACCOUNT]"<<endl;
       
       int id; 
       char* name;
       char nn[100];
   
       cout<<"id: "; 
       cin>>id;
       user[user_num].user_account = id;
   
       cout<<"name: "; 
       cin>>nn;
       name = nn;
   
       user[user_num].user_name = name;
       user[user_num].user_amount = 0;
   
       user_num++;
   
   }
   
   void deposit(){
       int id; int i; int money;
       cout<<" [DEPOSIT]"<<endl;
       cout<<"ID: "; cin>>id;
       for(i = 0; i<user_num; i++){
           if(user[i].user_account == id){
               cout<<"deposit money: "; 
               cin>>money;
               user[i].user_amount += money;
               cout<<"Completion"<<endl;
               cout<<"==========================="<<endl;
               break;
           }
       }
       if(i==user_num){
           cout<<"Error, Id is not defined"<<endl;
           cout<<"==========================="<<endl;
   
       }
   }
   
   void withdraw(){
       int id; int i; int money;
       cout<<" [WITHDRAW]"<<endl;
       cout<<"ID: "; cin>>id;
   
       for(i = 0; i<user_num; i++){
           if(user[i].user_account == id){
               cout<<"Withdraw money: "; cin>>money; cout << endl;
               if(money > user[i].user_amount){
                   cout<<"ERROR, reck of money"<<endl;
                   cout<<"==========================="<<endl;
   
               }
   
               else{
                   user[i].user_amount -= money;
                   cout<<"Completion"<<endl;
                   cout<<"==========================="<<endl;
                   break;
               }
               
           }
       }
       if(i==user_num){
           cout<<"Error, Id is not defined"<<endl;
           cout<<"==========================="<<endl;
   
       }
   }
   
   void viewAccount(){
       int id; int i;
       cout<<" [VIEW AMOUNT]"<<endl;
       cout<<"ID: "; 
       cin>>id;
       
       for(i = 0; i<user_num; i++){
           if(user[i].user_account == id){
               cout<<"name: "<<user[i].user_name<<endl;
               cout<<"amount: "<<user[i].user_amount<<endl;
               break;
   
           }
       }
       
       if(i==user_num){
           cout<<"Error, Id is not defined"<<endl;
           cout<<"==========================="<<endl;
   
       }    
   }
   ~~~
   
   





제작일 : 2020-10-17

<참고 : 열혈 C++ 프로그래밍 , TCP school.com>