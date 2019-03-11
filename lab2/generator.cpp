//
// Created by Ilya Sysoi on 2019-03-11.
//
#include <iostream>
using namespace std;


int main() {

    unsigned m = rand() % 20 + 0;
    unsigned n = rand() % 20 + 0;
    string s = "";
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
    cout << "a";
    cout << "b";
}