// Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>
#include <cassert>

using namespace std;

int main() {
    int i = 1;
    const int j = 2;

    cout << "i=" << i << endl;
    cout << "j=" << j << endl;

    // pointer to pointer
    int* ip = &i;
    int** ipp = &ip;
    cout << "**ipp=" << **ipp << endl;

    // 指標 1/3
    int* const ip1 = &i; // ip1 常數指標
    *ip1 = 3;
    // ip1 = &j; // error，不可移動
    cout << "i=" << i << endl;

    // 指標 2/3
    const int* ip2 = &i; // ip2 指標常數，等同於 int const* (如下示範)
    int const* ipp2 = &i; // ipp2 指標常數
    // *ip2 = 33; // error // 不可改值
    // *ipp2 = 33; // error // 不可改值

    cout << "*ip2:" << *ip2 << endl;
    cout << "*ip21:" << *ipp2 << endl;

    ip2 = &j; // 可移動
    ipp2 = &j; // 可移動
    cout << "*ip2 moved to j:" << *ip2 << endl;
    cout << "*ip21 moved to j:" << *ipp2 << endl;

    // 指標 3/3
    const int* const ip3 = &j; // ip3 常數指標，指向常數值
    // *ip3 = 3; // error，不可改值
    // ip3 = &j; // error，不可移動
    cout << "*ip3:" << *ip3 << endl;

    cout << "---------------------------------" << endl;
    int a[3]{ 3,2,1 };
    for (int idx = 0; idx < 3; idx++) {
        cout << "*a[" << idx << "]:" << a[idx] << endl;
    }

    cout << "---------------------------------" << endl;
    int* ap = a; // 陣列變數就相當於指標，可以指標操作陣列元素。
    for (int idx = 0; idx < 3; idx++) {
        cout << "*a[" << idx << "]:" << *(ap + idx) << endl;
    }

    cout << "---------------------------------" << endl;
    string str("hello world!");
    cout << str << endl;
    for (int i = 0; i < str.length(); i++) {
        cout << str[i];
    }

    cout << endl;

    for (auto s : str) {
        cout << s;
    }

    cout << endl;
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
