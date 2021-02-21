//#define __USE__MATH__DEFINES

#include <iostream>
#include <sstream>
#include <vector>
#include <optional>
#include <string>
#include <cstdlib>
#include <cmath>    // Assuming <cmath> is permitted (see README)

#include "tokeniser.h"
#include "resultChecker.h"
#include "inputProcessor.h"
#include "constants.h" 

const double pi = 3.141592653589793238463;

void run ()
{
    InputProcessor processor;
    while (processor.requestInput () == InputProcessor::InputRequest::continueProcessing);
}

int main (int argc, const char * argv[])
{
   if (argc > 1 && std::string (argv[1]) == "--test")
        test ();
    else
        run ();
    
    return 0;
}
