#include <iostream>
#include "lexer.h"
#include "expr.h"

Addition* parse_ord(lexer &lexer);
term* pars_term(lexer&Lexer);
expr* parse_expr(lexer &Lexer);

/**
 * <exp>-><word> + <expr>
 * | <word> + <word>
 * | <word>
 * |<word>-><char> [<word>]
 */
// <word>-><char> [<word>]
Addition* parse_ord(it& first, it last) {
    Addition* result= nullptr;
    int c = lexer.lex();
    if(c==lexer::LETTER){
        result=new Addition(lexer.lexeme());
    }
    return result;
}

term* pars_term(it& first, it last){
    auto fac= parse_ord(Lexer);
    term* result= nullptr;
    if(fac){
        result=new term(fac);
    }
    //auto add=Lexer.lex();
    auto add=Lexer.lex();
    if(add==lexer::ADD_OP){
        auto child= parse_ord(Lexer);
        result->add(child);
    }
    return result;
}

expr* parse_expr(it& first, it last){
    auto term=pars_term(Lexer);
    expr* result= nullptr;
    if(term){
        result=new expr(term);
    }
    auto token =Lexer.lex();
    if(token==lexer::ADD_OP){
        auto child= parse_expr(Lexer);
        result->add(child);
    }
    return result;
}


//int main(int argc, char*argv[]) {
int main() {

    /**
     * vi ska kunna förklara shift reduce
     */
    //std::cout<<argv[0]<<'\n';

    /*
    std::string program=argv[1];
    lexer lex(program);
    if(lex.lex()==lexer::DIGIT){
        std::cout<<"tjooh";
        std::cout<<"";
    }
    if(lex.lex()==lexer::ADD_OP){
        std::cout<<"tjooh";
        std::cout<<"";
    }*/

    //std::string program = argv[1];
    std::string program ="hej+jag";
    lexer lex(program);
    it first=program.begin();
    it last=program.end();

    auto expr = parse_expr(first, last);
    std::cout << expr->eval();
    std::cout << expr->eval();
}
