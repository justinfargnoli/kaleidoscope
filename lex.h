//
// Created by Justin Fargnoli on 5/10/20.
//

#ifndef KALEIDOSCOPE_LEX_H
#define KALEIDOSCOPE_LEX_H

enum Token {
    tok_eof = -1,

    // commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierStr; // Filled in it tok_identifier
static double NumVal; // Filled in it tok_number

static int gettok();

#endif //KALEIDOSCOPE_LEX_H
