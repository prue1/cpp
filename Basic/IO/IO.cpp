// IO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

const auto arr_size = 5;
bool light[arr_size];
string warning_msg;

static void print_light_status() {
    printf("Light status:\n");
    for (auto i = 0; i < arr_size; i++) {
        printf("%d [%s]\n", i + 1, (light[i] ? "_O_" : "_._"));
    }
}

static void dieplay_warning() {
    if (warning_msg.length() > 0) {
        printf(warning_msg.c_str());
    }
    warning_msg = "";
}

static void set_msg(string str) {
    warning_msg = "WARNING:Invalid input (" + str + ")\n";
}

static void print_prompt() {
    printf("input ['q' or 'Q' to quit]:");
}

int main()
{
    string str;
    bool run = true;
    while (run) {
        system("cls");
        print_light_status();
        dieplay_warning();
        print_prompt();

        cin >> str;
        if (str == "q" || str == "Q") {
            run = false;
        }
        else {
            try {
                int idx = stoi(str) - 1;
                if (idx >= 0 && idx < arr_size) {
                    light[idx] = !light[idx];
                }
                else {
                    set_msg(str);
                }
            }
            catch (const std::invalid_argument& ia) {
                set_msg(str);
            }
        }

        printf("\n");
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
