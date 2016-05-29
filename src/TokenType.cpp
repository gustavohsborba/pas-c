//
// Created by felipe on 28/05/16.
//

#include "frontend/TokenType.h"
#include <iostream>
vector<TokenType> unmask(long mask) {
    vector<TokenType> tokens;
    long t = mask;
    while(t != 0L) {
        tokens.push_back((TokenType) (t&-t));
        t = t - (t&-t);
    }

    return tokens;
}