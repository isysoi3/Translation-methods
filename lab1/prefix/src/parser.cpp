#include "global.h"

int lookahead;

void parse() {
    lookahead = lexan();
    while (lookahead != DONE)
        cout << expr();
    cout << endl;
}

string expr() {
    string part1, operation, part2;
    part1 = term();
    while (true) {
        switch (lookahead) {
            case '+':
            case '-':
                operation = emit(lookahead, NONE);
                match(lookahead);
                part2 = term();
                continue;
            default:
                return operation + part1 + part2;
        }
    }
}

string term() {
    string part1, operation, part2;
    part1 = factor();
    while (true) {
        switch (lookahead) {
            case '*':
            case '/':
            case DIV:
            case MOD:
                operation = emit(lookahead, NONE);
                match(lookahead);
                part2 = factor();
                continue;
            default:
                return operation + part1 + part2;
        }
    }
}

string factor() {
    string value;
    switch (lookahead) {
        case '(':
            match('(');
            value = expr();
            match(')');
            return value;
        case NUM:
            value = emit(NUM, tokenval);
            match(NUM);
            return value;
        case ID:
            value = emit(ID, tokenval);
            match(ID);
            return value;
        default:
            error("factor: syntax error");
    }
    return "";
}

void match(int t) {
    if (lookahead == t)
        lookahead = lexan();
    else
        error("match: syntax error");
}