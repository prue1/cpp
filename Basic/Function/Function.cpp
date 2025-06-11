// Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Action {
private:
    int value;
public:
    void setValue(int value) {
        this->value = value;
    }

    int getValue() {
        return this->value;
    }

    virtual void execute() = 0; // pure virtual function
};

class ActionImpl : public Action {
public:
    void execute() override {
        cout << getValue() << endl;
    }

};

int main()
{
    // 包含 pure virtual function 的 class 被視為 abstract class，不可初始化。

    ActionImpl a;
    ActionImpl b = ActionImpl();
    a.setValue(1);
    a.execute();
    b.setValue(2);
    b.execute();

    // 多型測試:
    // 宣告型別(Action)與初始化型別(ActionImpl)不同，要用指標。
    Action* action = new ActionImpl();
    action->setValue(3);
    action->execute();
    delete action;
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
