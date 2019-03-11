//
// Created by Ilya Sysoi on 2019-03-11.
//
#include <iostream>
#include <ctime>
using namespace std;


int main() {
    std::srand(time(0));
    unsigned m = rand() % 10 + 0;
    unsigned n = rand() % 10 + 0;
    string s = "";
    if (n != 0) {
        s += "a";
        for (int i = 0; i < m; ++i) {
            s += "b";
        }
        s +=  "a";
        for (int i = 0; i < m+1; ++i) {
            s += "b";
        }
        for (int i = 0; i < n; ++i) {
            cout << s;
        }
    }
    cout << "a";
    cout << "b";
}