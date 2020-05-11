#include "parse.h"


int main() {
    // Install standard binary operators.
    // 1 is the lowest precedence
    BinopPrecedence['<'] = 10;
    BinopPrecedence['+'] = 20;
    BinopPrecedence['-'] = 30;
    BinopPrecedence['*'] = 40; // the highest precedence operator

    return 0;
}
