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