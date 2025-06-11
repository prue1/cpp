// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

static void handle(int val) {
    std::cout << val << "->sqrt:" << sqrt(val) << std::endl;
}

static void handle(int val, int idx) {
    std::cout << idx << "->" << val << std::endl;
}

class Hello {
public:
    int sub(int a, int b) {
        return a - b;
    }
};

int main()
{
    int a[]{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(a) / sizeof(a[0]) << std::endl;

    for (int i = 0; i < 25; i++) {
        handle(a[i]);
    }

    int* ip = a;
    for (int i = 0; i < 25; i++) {
        handle(*(ip + i), i);
    }

    size_t size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++) {
        handle(*(ip + i), i);
    }

    //-------------------------
    Hello h;
    std::cout << h.sub(3, 1) << std::endl;

    Hello* h2 = new Hello();
    std::cout << h2->sub(5, 2) << std::endl;
    delete h2;
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
