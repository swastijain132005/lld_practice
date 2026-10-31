#include <iostream>
#include <stdexcept>
using namespace std;

class Parent {
public:
    virtual void getValue() {
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() override {
        throw out_of_range("Child error");
    }
};

int main() {
    Parent p;
    Child c;

    Parent* obj = &p;

    try {
        obj->getValue();
    }
    catch (const logic_error& e) {
        cout << e.what() << endl;
    }

    obj = &c;

    try {
        obj->getValue();
    }
    catch (const logic_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}