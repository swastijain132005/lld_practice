#include<iostream>
#include<vector>
using namespace std;

//write public

class Product{
    public:
    string name;
    int price;

     Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    public:

    vector<Product *>prod;
    void addProduct(Product *p){
        prod.push_back(p);
    }

    vector<Product*>getprod(){
        return prod;
    }

    int total=0;
    public:

    int calctotal(){
        for (auto p:prod){
            total+=p->price;
        }

        return total;
    }



};

// abtract class no contructur 

class Persistence{
    ShoppingCart *cart;

    virtual void save(ShoppingCart *cart)=0;
   
};


class SQLpersistence :public Persistence{
         void save (ShoppingCart *cart)  override {
            cout<<"saving to sql";
         }


};


class Filepersistence :public Persistence{
         void save (ShoppingCart *cart)  override {
            cout<<"saving to file";
         }


};

int main(){

    ShoppingCart *cart =new ShoppingCart();

      cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));


    
}
