// Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

static void doEven(int i) {
    cout << "even:" << i << endl;
}

static void doOdd(int i) {
    cout << " odd:" << i << endl;
}

static void print_number(const int n) {
    int m = n % 2;
    if (m == 0) {
        doEven(n);
    }
    else if (m == 1) {
        doOdd(n);
    }
}

static void print_number(const int* ip) {
    int m = (*ip) % 2;
    if (m == 0) {
        doEven(*ip);
    }
    else if (m == 1) {
        doOdd(*ip);
    }
}

int main() {
    srand(time(NULL));
    int i = 0;
    while (i < 10) {
        int x = rand();
        print_number(x);
        i++;
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
