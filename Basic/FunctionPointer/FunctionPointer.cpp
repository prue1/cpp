// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

typedef long (*abc)(int, int); // 宣告＂函式型別＂，型別名稱為 abc

long (*def)(int, int); // 富告＂函式指標＂，變數名稱為 def

double (*xyz[5])(int); // 富告＂函式指標陣列＂，變數名稱為 xyz。與函式指標類似，不過，多了[]

void func1(abc a); // 宣告函數

static long add(int a, int b) {
    return a + b;
}

long (*lmn)(int, int) = &add; // 宣告同時賦值，函式指標 lmn，指向 函式 add

// 定義 func1
void func1(abc a) {
    cout << "do something." << endl;
    cout << a(1, 2) << endl;
}

static double powerValue(int v) {
    return pow(2, v);
}

static void test_pointer(const int* p) { // 無法變更 "p 所指向的值"。也就是說，*p = 33，將會產生 error
    cout << *p << endl;
}

int main()
{
    int i = 1;
    int j = 2;

    def = &add;
    func1(lmn);
    func1(def);

    int& i2 = i; // & 放在左值, 表示別名(alias)
    i2 = 33;
    int& j2 = j;
    j = 9;

    cout << "***************************" << endl;

    test_pointer(&i);
    test_pointer(&j2);

    cout << "---------------------------" << endl;

    xyz[0] = powerValue;
    xyz[1] = powerValue;
    xyz[2] = powerValue;
    xyz[3] = powerValue;
    xyz[4] = powerValue;
    for (int i = 0; i < 5; i++) {
        cout << (*xyz[i])(i) << endl;
    }

    cout << "===========================" << endl;

    xyz[0] = &powerValue;
    xyz[1] = &powerValue;
    xyz[2] = &powerValue;
    xyz[3] = &powerValue;
    xyz[4] = &powerValue;
    for (int i = 0; i < 5; i++) {
        cout << (*xyz[i])(i) << endl;
    }
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
