//
//  inputProcessor.h
//  Calculator
//
//  Created by sierra on 18/02/2021.
//

#pragma once

#ifndef inputProcessor_h
#define inputProcessor_h

#include "constants.h"

class InputProcessor
{
public:
    
    enum class InputRequest
    {
        quitProcessing,
        continueProcessing,
    };
    
    
    InputRequest requestInput () const
    {
        std::cout << "Please enter a calculation (Type Q to quit)" << std::endl;
        
        std::string input;
        std::getline (std::cin, input);
        
        if (input == "Q" || input == "q")
            return InputRequest::quitProcessing;
        
        processInput (input);
        
        return InputRequest::continueProcessing;
    }
    
private:
    
    void processInput (std::string input) const
    {
        if (auto tokens = Tokeniser ().tokenise (input))
            std::cout << "Answer: " << Calculator ().calculate (*tokens) << std::endl;
        else
            std::cout << "There was an error in the input string, please try again..." << std::endl;
    }
};

#endif /* inputProcessor_h */
