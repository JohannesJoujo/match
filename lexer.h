//
// Created by Johannes Joujo on 2024-02-01.
//

#ifndef MATCH_LEXER_H
#define MATCH_LEXER_H

#include <iostream>

using token = int;
using it=std::string::iterator;

class lexer {
private:
    std::string input;
    std::string current_lexeme;
    size_t index=0;
    bool is_whitespace(char c);

    char add_char(it& first);

    bool is_alpha(char c);
public:
    enum {
        ADD_OP = 1,
        MULTI,
        LPAR,
        HPAR,
        PUNKT,
        LBRACE,
        HBRACE,
        LETTER,
        UNKNOWN,
        DIGIT,
        IDENT,
        INT_LIT,
        END
    };
    //token lex();
    token lex(it &first, it last);
    lexer ()=delete;
    lexer(std::string program);

    std::string lexeme();

    bool is_digit(char c);
};


#endif //MATCH_LEXER_H
