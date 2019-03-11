#include <stdio.h>

int A();

int B();

int B() {
    char c;
    c = getchar();
    if (c == 'a')
        return 1;
    else if (B()) {
        //где то здесь
        return 1;
        c = getchar();
        if(c == '\n')
            return 2;
        if(c == 'a') {
            c = getchar();
            if (c == 'b')
                return 1;
        } else if (B())
            return 1;
    }
    return 0;
}

int R() {
    char c;
    int rez = B();
    if (rez == 2)
        return 1;
    if (rez == 1) {
        c = getchar();
        if(c != 'b')
            return 0;
        if (A())
            return 1;
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