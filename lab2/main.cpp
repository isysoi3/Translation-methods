#include <stdio.h>

int A();

int B();

int B() {
    char c;
    c = getchar();
    if (c == 'a')
        return 1;
    else if (c == 'b') {
        if (!B())
            return 0;
        c = getchar();
        if (c != 'b')
            return 0;
    }
    return 1;
}

int R() {
    char c;
    c = getchar();
    if (c == 'a') {
        return 1;
    } else if (c == 'b') {
        if (B()) {
            c = getchar();
            if (c != 'b')
                return 1;
            if (!A())
                return 0;
        } else
            return 0;
    }
    return 1;
}

int A() {
    char c;
    c = getchar();
    if (c == 'a') {
        if (!R())
            return 0;
    } else
        return 0;
    return 1;
}


int main() {
    if (A())
        printf("success!");
    else
        printf("ERROR !");

}

//abbbabbbbab
//abbbabbbbabbbabbbbab
//ab