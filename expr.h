//
// Created by Johannes Joujo on 2024-02-01.
//

#ifndef MATCH_EXPR_H
#define MATCH_EXPR_H

#include "lexer.h"
#include <string>

struct op{
    std::vector<op*>children;
    virtual std::string eval()=0;
    void add(op*child){
        children.push_back(child);
    }
};
struct Addition:op{
    std::string value;

    Addition(std::string child){
        value=child;
    }
    std::string eval()override{
        return value;
    }
};

struct term:op{
    term(Addition* addi){
        add(addi);
    }
    std::string eval() override{
        auto result=children[0]->eval();
        if(children.size()>1){
            result+=children[1]->eval();
        }
        return result;
    }

};

struct expr:op{
    expr(term*child){
        add(child);
    }
    std::string eval()override{
        auto result =children[0]->eval();
        if(children.size()>1){
            result+=children[1]->eval();
        }
        return result;
    }
};


#endif //MATCH_EXPR_H
