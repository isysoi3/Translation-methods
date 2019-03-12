#include <stdio.h>

int A();

int B();

int B() {
    char c;
    c = getchar();
    if (c == 'a')
        return 1;
    else if (c == 'b') {
        if (B()) {
            c = getchar();
            if (c == 'b')
                return 1;
        }
    }
    return 0;
}

int R() {
    char c;
    c = getchar();
    if (c == 'b') {
        char c1 = getchar();
        if (c1 == '\n')
            return 1;
        else
            ungetc(c1, stdin);
    }
    ungetc(c, stdin);
    if (B()) {
        c = getchar();
        if (c == 'b') {
            return A();
        }
    }
    return 0;
}

int A() {
    char c;
    c = getchar();
    if (c == 'a')
        if (R())
            return 1;
    return 0;
}


int main() {
    if (A())
        printf("success!");
    else
        printf("ERROR !");
}

//abbabbbab
//abbbabbbbab
//abbbabbbbabbbabbbbab

//ab
//aabab
//ababbab