#include "global.h"

std::string emit(int t, int tval) {
    switch (t) {
        case '+':
        case '-':
        case '*':
        case '/':
            return std::string(1, (char)t);
        case DIV:
            return "DIV";
        case MOD:
            return "MOD";
        case NUM:
            return std::to_string(tval);
        case ID:
            return symtable[tval].lexptr;
        default:
            printf("token %d, tokenval %d\n", t, tval);
    }
    return "";
}