#include <iostream>
#include <stdexcept>
using namespace std;

class parent {
    public:

    int balance;

    parent (int bal){
        balance=bal;
        if(balance<0){
            throw invalid_argument("neg not allowed ");
        }}
public:
       virtual void withdraw (int amt){

            if(balance-amt<0){
                throw runtime_error("balance cant be neg");
            }
            else {
                balance-=amt;
            }
        }


    



};

class cheataccount :public parent{
 cheataccount(int bal):parent(bal){

 }

 
    void withdraw(int amount) override {
        balance -= amount; // LSP break! Negative balance allowed
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }



};
