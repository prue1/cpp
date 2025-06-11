// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "stdio.h"

using namespace std;

string str;

int main() {
    ifstream infile("f:/temp/test.txt");
    ofstream outfile("f:/temp/test2.txt");

    while (getline(infile, str)) {
        cout << str << endl;
        outfile << str << ", aaa" << endl;
    }

    infile.close();
    outfile.close();
    //system("explorer.exe F:\\data\\bg\\spotlight");

    //
    FILE* pFile;
    char buffer[100];

    //pFile = fopen("F:\\temp\\A.java", "r");
    errno_t err = fopen_s(&pFile, "F:\\temp\\A.java", "r");
    if (pFile == NULL) perror("Error opening file");
    else
    {
        while (!feof(pFile))
        {
            if (fgets(buffer, 100, pFile) == NULL) break;
            fputs(buffer, stdout);
        }
        fclose(pFile);
    }
    return 0;
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
