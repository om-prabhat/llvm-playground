#include "include/data.h"
#include "include/defs.h"
#include "include/decls.h"
#include <ctype.h>
#include <stdlib.h>

tokenStruct *initToken(){
    tokenStruct *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    // token->identifierStr = ' ';
    token->type = 0;
    token->returnedInt = 0;
    token->number = 0.00;
    return token;
}

static const char *tokenTypeToStr(int type){
    switch(type){
        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_TINT: return "TOKEN_TINT";
        case TOKEN_TBOOL: return "TOKEN_TBOOL";
        case TOKEN_TVOID: return "TOKEN_TVOID";
        case TOKEN_TCHAR: return "TOKEN_TCHAR";
        case TOKEN_TFLOAT: return "TOKEN_TFLOAT";
        case TOKEN_TDOUBLE: return "TOKEN_TDOUBLE";
        case TOKEN_EXTERN: return "TOKEN_EXTERN";
        case TOKEN_BRLEFT: return "TOKEN_BRLEFT";
        case TOKEN_BRRIGHT: return "TOKEN_BRRIGHT";
        case TOKEN_BCLEFT: return "TOKEN_BCLEFT";
        case TOKEN_BCRIGHT: return "TOKEN_BCRIGHT";
        case TOKEN_SCOLON: return "TOKEN_SCOLON";
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_INT: return "TOKEN_INT";
        case TOKEN_RETURN: return "TOKEN_RETURN";
        case TOKEN_ADD: return "TOKEN_ADD";
        case TOKEN_SUB: return "TOKEN_SUB";
        case TOKEN_MUL: return "TOKEN_MUL";
        case TOKEN_DIV: return "TOKEN_DIV";
        // case : return "";
        // case : return "";
        // case : return "";
    }
    return "Token type not defined";
}

char *tokenToStr(tokenStruct *token){
    switch(token->returnedInt){
        case TOKEN_EOF: return "EOF";
        case TOKEN_TINT: return "int";
        case TOKEN_TBOOL: return "bool";
        case TOKEN_TVOID: return "void";
        case TOKEN_TCHAR: return "char";
        case TOKEN_TFLOAT: return "float";
        case TOKEN_TDOUBLE: return "double";
        case TOKEN_EXTERN: return "extern";
        case TOKEN_RETURN: return "return";
        case TOKEN_BRLEFT: return "(";
        case TOKEN_BRRIGHT: return ")";
        case TOKEN_BCLEFT: return "{";
        case TOKEN_BCRIGHT: return "}";
        case TOKEN_SCOLON: return ";";
        case TOKEN_ADD: return "+";
        case TOKEN_SUB: return "-";
        case TOKEN_MUL: return "*";
        case TOKEN_DIV: return "/";
        case TOKEN_IDENTIFIER: return token->identifierStr;
        case TOKEN_INT: return token->identifierStr;
        // case : return "";
        // case : return "";
        // case : return "";
    }
    return "Token type not defined";
}

char *tokenPrint(tokenStruct *token){
    const char *typeStr = tokenTypeToStr(token->returnedInt);
    const char *template = "<type=`%s`, intType=`%d`, value=`%s`>";
    char *str = tokenToStr(token);

    char *tp = calloc(strlen(typeStr)+strlen(template)+32, sizeof(char));
    sprintf(tp, template, typeStr, token->returnedInt, str);
    return tp;
}

static int next(){
    int c;
    c = fgetc(Infile);
    if('\n' == c)
        Line++;
    return c;
}

// gets a single character at a time then convert it into tokens (our defined numbers). which will help in next steps. maybe.....
int getToken(tokenStruct *t){
    static int lastChar = ' ';

    while(isspace(lastChar))
    {
        lastChar = next();
    }
    int index = 0;
    t->identifierStr = calloc(1, sizeof(char));
    if(isalpha(lastChar)){
        t->identifierStr[index++] = lastChar;

        while(isalnum((lastChar = next()))){
            t->identifierStr = realloc(t->identifierStr, (strlen(t->identifierStr)+2)*sizeof(char));
            t->identifierStr[index++] = lastChar;
        }
        t->identifierStr[index] = '\0';
        // printf("%s\n", t->identifierStr);
        if(strcmp(t->identifierStr, "int") == 0){
            return TOKEN_TINT;
        }else if (strcmp(t->identifierStr, "bool") == 0) {
            return TOKEN_TBOOL;
        }else if (strcmp(t->identifierStr, "void") == 0) {
            return TOKEN_TVOID;
        }else if (strcmp(t->identifierStr, "char") == 0) {
            return TOKEN_TCHAR;
        }else if (strcmp(t->identifierStr, "float") == 0) {
            return TOKEN_TFLOAT;
        }else if (strcmp(t->identifierStr, "double") == 0) {
            return TOKEN_TDOUBLE;
        }else if (strcmp(t->identifierStr, "extern") == 0) {
            return TOKEN_EXTERN;
        }else if (strcmp(t->identifierStr, "return") == 0) {
            return TOKEN_RETURN;
        }else{
            return TOKEN_IDENTIFIER;
        }
    }

    //     switch(t->identifierStr){
    //         case EOF:
    //             return TOKEN_EOF;
    //         case "int":
    //             return TOKEN_TINT;
    //         case "bool":
    //             return TOKEN_TBOOL;
    //         case "void":
    //             return TOKEN_TVOID;
    //         case "char":
    //             return TOKEN_TCHAR;
    //         case "float":
    //             return TOKEN_TFLOAT;
    //         case "double":
    //             return TOKEN_TDOUBLE;
    //         case "extern":
    //             return TOKEN_EXTERN;
    //     }
    //     return TOKEN_IDENTIFIER;
    //

    if(isdigit(lastChar) || lastChar == '.'){
        char numStr[256];
        int index2 = 0;
        do{
            numStr[index2++] = lastChar;
            lastChar = next();
        }while (isdigit(lastChar) || lastChar == '.');

        t->number = strtod(numStr, 0);
        int len = snprintf(NULL, 0, "%.2f", t->number);
        t->identifierStr = calloc(len+1, sizeof(char));
        snprintf(t->identifierStr, len+1, "%.2f", t->number);
        return TOKEN_INT;
    }

    // if(lastChar == EOF){
    //     return TOKEN_EOF;
    // }
    // int thisChar = lastChar;
    // lastChar = next();

    // char *anotherthing = malloc(32*sizeof(char));
    // int index = 0;
    // if(isalpha(lastChar)){
    //     anotherthing[index++] = lastChar;
    //     while(isalnum((lastChar = next()))){
    //         anotherthing[index++] = lastChar;
    //     }

    if(lastChar == '#'){
        do{
            lastChar = next();
        }while(lastChar != EOF && lastChar != '\n' && lastChar != '\r');


        if(lastChar != EOF){
            return getToken(t);
        }
    }
    // printf("%s ", anotherthing);
    // while((lastChar = next()) != EOF){
    //     // free(t->identifierStr);
    //     // t->number = 0;
    //     // return t;
    //     return getToken(t);
    // }

    if(lastChar == EOF){
        return TOKEN_EOF;
    }
    // return t;
    int thisChar = lastChar;
    lastChar = next();
    switch(thisChar){
        case '(': return TOKEN_BRLEFT;
        case ')': return TOKEN_BRRIGHT;
        case '{': return TOKEN_BCLEFT;
        case '}': return TOKEN_BCRIGHT;
        case ';': return TOKEN_SCOLON;
        case '+': return TOKEN_ADD;
        case '-': return TOKEN_SUB;
        case '*': return TOKEN_MUL;
        case '/': return TOKEN_DIV;
        default: return thisChar;
    }

}
