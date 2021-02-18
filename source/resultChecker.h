//
//  resultChecker.h
//  Calculator
//
//  Created by sierra on 18/02/2021.
//

#pragma once

#ifndef resultChecker_h
#define resultChecker_h

#include "calculator.h"

class ResultChecker
{
public:
    
    static void check (double value, double expected, double range = 1e-3)
    {
        return assert (std::abs (value - expected) <= range);
    }
};

void test ()
{
    auto result = Tokeniser ().tokenise ("6*9");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 6);
    ResultChecker::check (result->rhs, 9);
    assert (result->type == Tokeniser::Type::multiply);
    
    result = Tokeniser ().tokenise ("6 * 9");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 6);
    ResultChecker::check (result->rhs, 9);
    assert (result->type == Tokeniser::Type::multiply);
    
    result = Tokeniser ().tokenise ("25 * 4");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 25);
    ResultChecker::check (result->rhs, 4);
    assert (result->type == Tokeniser::Type::multiply);
    
    ResultChecker::check (Calculator ().calculate ({ 10, 4, Tokeniser::Type::multiply }), 40);
    ResultChecker::check (Calculator ().calculate ({ 25.3, 18.6, Tokeniser::Type::add }), 43.9);
    ResultChecker::check (Calculator ().calculate ({ 3, 5.6, Tokeniser::Type::subtract }), 2.6);
}


#endif /* resultChecker_h */
