//
// Created by Justin Fargnoli on 5/10/20.
//

#include <cctype>
#include <string>
#include "lex.h"

/// gettok - Return the next token from standard input
static int gettok() {
    static char LastChar = ' ';

    while (isspace(LastChar)) {
        LastChar = (char) getchar();
    }

    if (isalpha(LastChar)) { // identifier: [a-zA-z][a-zA-z0-9]
        IdentifierStr = LastChar;
        while (isalnum((LastChar = (char) getchar()))) // is alphanumeric
            IdentifierStr += LastChar;

        if (IdentifierStr == "def")
            return tok_def;
        else if (IdentifierStr == "extern")
            return tok_extern;
        else
            return tok_identifier;
    }

    if (isdigit(LastChar) || LastChar == '.') { // Number: [0-9.]+
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = (char) getchar();
        } while (isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), nullptr);
        return tok_number;
    }

    if (LastChar == '#') {
        // Comment goes until the end of the line
        do {
            LastChar = (char) getchar();
        } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return gettok();
    }

    // Check for the end of the file. Don't eat the EOF.
    if (LastChar == EOF)
        return tok_eof;

    // Otherwise, just return the character as its ascii value
    char ThisChar = LastChar;
    LastChar = (char) getchar();
    return ThisChar;
}
