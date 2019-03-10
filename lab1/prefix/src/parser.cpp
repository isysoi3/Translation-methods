#include "global.h"

int lookahead;

void parse()
{
    lookahead = lexan();
    std::string result = "";
    while (lookahead != DONE) {
        result += expr();
    }
    std::cout << result << std::endl;
}

std::string expr()
{
    std::string result;
    int t;
    result = term();
    while (true) {
        switch (lookahead) {
            case '+': case '-':
                t = lookahead;
                match(lookahead);
                result = emit(t, NONE) + result;
                result += term();
                continue;
            default:
                return result;
        }
    }
}

std::string term()
{
    std::string result;
    int t;
    result = factor();
    while (true) {
        switch (lookahead) {
            case '*': case '/': case DIV: case MOD:
                t = lookahead;
                match(lookahead);
                result = emit(t, NONE) + result;
                result += factor();
                continue;
            default:
                return result;
        }
    }
}

std::string factor()
{
    std::string result;
    switch (lookahead) {
        case '(':
            match('(');
            result = expr();
            match(')');
            return result;
        case NUM:
            result = emit(NUM, tokenval);
            match(NUM);
            return result;
        case ID:
            result = emit(ID, tokenval);
            match(ID);
            return result;
        default:
            error("factor: syntax error");
    }
    return "";
}

void match(int t)
{
    if (lookahead == t)
        lookahead = lexan();
    else
        error("match: syntax error");
}