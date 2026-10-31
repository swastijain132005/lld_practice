#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    int price;
};

class ShoppingCart{

    vector<Product *>prod;
    void addprod(Product *p){
        prod.push_back(p);
    }

    vector<Product*>getprod(){
        return prod;
    }

    int total=0;

    int calctotal(){
        for (auto p:prod){
            total+=p->price;
        }

        return total;
    }



};

class printInvoice{
    ShoppingCart *cart;

    printInvoice(ShoppingCart *cart){
        this->cart=cart;
    }

    void print(){
        
    }



};