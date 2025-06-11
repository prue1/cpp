// Random2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>  

using namespace std;

int main()
{
    srand(time(0));
    list<int> data;

    data.assign(3, rand() % 1001);

    data.push_back(rand() % 1001);
    data.push_back(rand() % 1001);
    data.push_back(rand() % 1001);

    data.push_back(99);

    cout << "size:" << data.size() << endl;
    int idx = 0;
    for (list<int>::iterator it = data.begin(); it != data.end(); it++) {
        cout << idx << ":" << *it << endl;
        idx++;
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
