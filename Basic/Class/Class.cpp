// Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Abc {
private:
    int value;
public:
    Abc();
    ~Abc();
    Abc(int);
    int max(int, int) const;
    int getValue() const;

    bool operator==(const Abc& other) const {
        return other.value == value; // 0: false, 1: true
    }
};

Abc::Abc() {
    cout << "Constructor() called." << endl;
    this->value = 123;
}

Abc::Abc(int value) {
    cout << "Constructor(int) called." << endl;
    this->value = value;
}

Abc::~Abc() {
    cout << "Destructor done." << endl;
}

int Abc::max(int a, int b) const {
    return a > b ? a : b;
}

// 常數函式只能用在class的成員函式。
int Abc::getValue() const { // 常數函式，不允許更改類別成員資料
    //value = 123; // 不允許賦值，因為 const
    return value;
}

int main() {
    Abc abc; // Constructor() called.
    cout << abc.getValue() << endl; // 123
    cout << abc.max(1, 2) << endl; // 2

    Abc a1(1); // Constructor(int) called.
    Abc a2(2); // Constructor(int) called.
    cout << a1.getValue() << endl; // 1
    cout << a2.getValue() << endl; // 2
    cout << "compare:" << ((a1 == a2) == false) << endl; // compare:1
    cout << (true == false) << endl; // 0
    // Destructor done.
    // Destructor done.
    // Destructor done.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
