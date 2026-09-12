#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// The lexer will return tokens [0-255] for any character except these defined things

typedef struct TOKEN_STRUCT
{
    char *identifierStr;
    double number;
    // char *value;
    int returnedInt;
    enum
    {
        TOKEN_EOF = -1,

        // type of the thing defined (int,bool,void etc) or extern
        TOKEN_TINT = -2,
        TOKEN_TBOOL = -3,
        TOKEN_TVOID = -4,
        TOKEN_TCHAR = -5,
        TOKEN_TFLOAT = -6,
        TOKEN_TDOUBLE = -7,
        TOKEN_EXTERN = -8,

        // symbols
        TOKEN_BRLEFT = -9,
        TOKEN_BRRIGHT = -10,
        TOKEN_BCLEFT = -11,
        TOKEN_BCRIGHT = -12,
        TOKEN_SCOLON = -13,
        TOKEN_RETURN = -14,

        // arithmetic
        TOKEN_ADD = -15,
        TOKEN_SUB = -16,
        TOKEN_MUL = -17,
        TOKEN_DIV = -18,


        // primary
        TOKEN_IDENTIFIER = -254,
        TOKEN_INT = -255

    } type;
} tokenStruct;



// scanned tokens will be stored here
// struct token
// {
//     char *identifierStr; // [a-zA-Z][a-zA-Z0-9]* == any string that starts with a letter, followed by zero or more letters or digits
//     double number; // [0-9.]+ == any number of numbers
// };
