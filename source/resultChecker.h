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

/* The following function constitutes one solution
   to the std::abs error (see README for details)
*/
double ABS (double input)
{
    return input < 0 ? -(input) : input;
}

class ResultChecker
{
public:
    
    static void check (double value, double expected, double range = 1e-3)
    {
        // If <cmath> is permitted (see README):
        return assert (std::abs (value - expected) <= range);
        // -------
        // If <cmath> is not permitted (see README):
        //return assert (ABS (value - expected) <= range);
    }
    
};

void test ()
{
    auto result = Tokeniser ().tokenise ("6 * 9");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 6);
    ResultChecker::check (result->rhs, 9);
    assert (result->type == Tokeniser::Type::multiply);
   
    result = Tokeniser ().tokenise ("6 + 9");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 6);
    ResultChecker::check (result->rhs, 9);
    assert (result->type == Tokeniser::Type::add);
    
    result = Tokeniser ().tokenise ("25 - 4");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 25);
    ResultChecker::check (result->rhs, 4);
    assert (result->type == Tokeniser::Type::subtract);
    
    result = Tokeniser ().tokenise ("32 / 8");
    assert (result.has_value ());
    ResultChecker::check (result->lhs, 32);
    ResultChecker::check (result->rhs, 8);
    assert (result->type == Tokeniser::Type::divide);
    
    ResultChecker::check (Calculator ().calculate ({ 10, 4, Tokeniser::Type::multiply }), 40);
    ResultChecker::check (Calculator ().calculate ({ 25.3, 18.6, Tokeniser::Type::add }), 43.9);
    ResultChecker::check (Calculator ().calculate ({ 3, 5.6, Tokeniser::Type::subtract }), -2.6);
    ResultChecker::check (Calculator ().calculate ({ 18, 6, Tokeniser::Type::divide }), 3);
    
    std::cout << "Tests passed!" << std::endl;
}

#endif /* resultChecker_h */
