//
//  calculator.h
//  Calculator
//
//  Created by sierra on 18/02/2021.
//
#pragma once

#ifndef calculator_h
#define calculator_h

class Calculator
{
public:
    
    Calculator () = default;
    ~Calculator () = default;
    
    double calculate (Tokeniser::TokenList tokens) const
    {
        switch (tokens.type)
        {
            case Tokeniser::Type::add:
                return tokens.lhs + tokens.rhs;
            case Tokeniser::Type::subtract:
                return tokens.lhs - tokens.rhs;
            case Tokeniser::Type::multiply:
                return tokens.lhs * tokens.rhs;
            default:
                break;
        }
        
        return 0;
    }
};


#endif /* calculator_h */
