#include "global.h"

int lookahead;
std::string result = "";

void parse()
{
    lookahead = lexan();
    while (lookahead != DONE) {
        expr();
    }
    std::cout << result << std::endl;
}

void expr()
{
    int t;
    term();
    while (true) {
        switch (lookahead) {
            case '+': case '-':
                t = lookahead;
                match(lookahead);
                result = emit(t, NONE) + result;
                term();
                continue;
            default:
                return;
        }
    }
}

void term()
{
    int t;
    factor();
    while (true) {
        switch (lookahead) {
            case '*': case '/': case DIV: case MOD:
                t = lookahead;
                match(lookahead);
                result = emit(t, NONE) + result;
                factor();
                continue;
            default:
                return;
        }
    }
}

void factor()
{
    switch (lookahead) {
        case '(':
            match('(');
            expr();
            match(')');
            break;
        case NUM:
            result += emit(NUM, tokenval);
            match(NUM);
            break;
        case ID:
            result += emit(ID, tokenval);
            match(ID);
            break;
        default:
            error("factor: syntax error");
    }
}

void match(int t)
{
    if (lookahead == t)
        lookahead = lexan();
    else
        error("match: syntax error");
}