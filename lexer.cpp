//
// Created by Johannes Joujo on 2024-02-01.
//

#include "lexer.h"

bool lexer::is_whitespace(char c) {
    return std::isspace(c);
}

char lexer::add_char(it& first) {
    //return input[index++];
    return *++first;

}

bool lexer::is_alpha(char c) {
    return std::isalpha(c);
}

bool lexer::is_digit(char c) {
    return std::isdigit(c);
}

lexer::lexer(std::string program):input(program) {}

token lexer::lex(it &first, it last) {
    char c;
    token result=UNKNOWN;
    if(first==last){
        return END;
    }

    while(is_whitespace(*first)){
        c=add_char(first);
    }
    if(is_alpha(*first)){
        while (is_alpha(*first)){
            current_lexeme+=c;
            result=LETTER;
            c=add_char(first);
        }
    }else{
        switch (c) {
            case '+':
                current_lexeme=c;
                result= ADD_OP;
                c=add_char(first);
                break;
            case '*':
                current_lexeme=c;
                result= MULTI;
                c=add_char(first);
                break;
        }
    }
    return result;

}




/*token lexer::lex() {
    current_lexeme="";
    token result=UNKNOWN;
    auto c=add_char();
    while(is_whitespace(c)){
        c=add_char();
    }
    if(index==input.size()){
        return END;
    }

    while (is_digit(c)){
        current_lexeme+=c;
        result=DIGIT;
        c=add_char();
    }
    while (is_alpha(c)){
        current_lexeme+=c;
        result=LETTER;
        c=add_char();
    }

    switch (c) {
        case '+':
            current_lexeme=c;
            result= ADD_OP;
            c=add_char();
            break;
        case '*':
            current_lexeme=c;
            result= MULTI;
            c=add_char();
            break;
    }

    return result;
}
*/
/*token lexer::lex() {
    current_lexeme = "";
    token result = UNKNOWN;  // Initialize with a default value
    auto c = add_char();

    while (is_whitespace(c)) {
        c = add_char();
    }

    if (index == input.size()) {
        return END;
    }

    if (is_digit(c)) {
        while (is_digit(c)) {
            current_lexeme += c;
            c = add_char();
        }
        result = DIGIT;
    } else if (is_alpha(c)) {
        while (is_alpha(c)) {
            current_lexeme += c;
            c = add_char();
        }
        result = LETTER;
    } else {
        switch (c) {
            case '+':
                current_lexeme = c;
                result = ADD_OP;
                break;
            case '*':
                current_lexeme = c;
                result = MULTI;
                break;
        }
        c = add_char();
    }

    return result;
}
//--------------------------//
token lexer::lex() {
    current_lexeme = "";
    token result = UNKNOWN;
    auto c = add_char();

    while (is_whitespace(c)) {
        c = add_char();
    }

    if (index == input.size()) {
        return END;
    }
    if (is_alpha(c)) {
        while (is_alpha(c)) {
            current_lexeme += c;
            c = add_char();
        }
        result = LETTER;
    } else {
        switch (c) {
            case '+':
                current_lexeme = c;
                return ADD_OP;
                //c = add_char();
                break;
            case '*':
                current_lexeme = c;
                return MULTI;
                //c = add_char();
                break;
        }
    }

    return result;
}

*/