// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>
#include <cassert>

using namespace std;

static int* get_value() {
    int i = 5;
    return &i;
}

static int& get_value2() {
    int i = 5;
    return i;
}

int main()
{
    string str_arr[4]{ "aaa", "bbb", "ccc", "ddd"};
    cout << str_arr[0] << endl;
    cout << str_arr[1] << endl;
    cout << str_arr[2] << endl;
    cout << str_arr[3] << endl;

    char ccc[]{ 'a','b','c','d', 'E','\n','\0'}; // c string
    printf(ccc);
    printf("1:%s\n", str_arr[0]); // 亂碼
    printf("2:%s\n", str_arr[0].c_str()); // 轉成 c string，正常
    fputs(ccc, stdout);

    cout << *get_value() << endl;
    cout << get_value2() << endl;

    cout << format("aaa{}{}", "123", "456") << endl; // format() from c++ 20

    printf("%s %d\n", "hello", 223);
    //assert(1 == 2);
    assert(true);
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
