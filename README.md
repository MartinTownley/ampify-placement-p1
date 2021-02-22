# M Townley: Ampify Engineering Placement Test

## Part 1: C++ Calculator

### Instructions

The repository contains a compiled version of the root directory of the repository. However, if you wish to build, you can do so using CMake:

1) cd into the root folder of the repository.
2) Execute the command "cmake -S . -B ." to generate the makefiles for the executatble in the current directory.
2) Execute the command "make" to build the executable. It will be named "calcu".
3) Execute the shellscript named "run.sh" by entering "./run.sh" to launch the executable (Alternatively, run the executable by entering "./calcu")
4) There is also a shellscript for running the tests: enter "./test.sh"

The calculator should now be giving prompts on the command line, and can be given expressions to calculate.

### Process

#### Re-factoring
I re-factored the code, creating a header file for each class of the program: calculator.h, inputProcessor.h, resultChecker.h, and tokeniser.h. I also re-named the calculator-main.cpp file to main.cpp, and added a constants.h file to store the anonymous namespace relating to the pi constant (discussed below).

#### Bugs

- ResultChecker class: it verified the calculation "3 - 5.6" with the answer "2.6", where it should have been "-2.6"

#### Including cmath
The code would not compile initially, throwing an error where the check method of the ResultChecker class attempts to assert that the absolute difference between a program-calculated result and an expected value did not exceed 1e-3. The error produced was “call to abs is ambiguous”, since the std::abs function as defined by cstdlib expects an integral value. Since in the check method of ResultChecker we are passing it a double, i.e. not an integral value, the error occurs.

I have included two solutions to this, since I was unsure if one solution was permitted under the prescription “you must use only the STL and the C stdlib (C++17)”. I was unsure whether reference to “the C stdlib” meant libraries under the umbrella of C++ Standard Library headers (e.g. "cmath"), or whether it meant properties belonging to "cstdlib" (which would exclude libraries such as "cmath"). The following two solutions cover both cases:

***Solution 1 (assuming C++ Standard Library headers permitted):***
Including "cmath" header resolves the ambiguous call error, since the std::abs function is overloaded in "cmath" for float types.

***Solution 2 (assuming only the use of "cstdlib" permitted):***
A user-defined function is created that takes a double, checks if it is below zero, and returns the negative of that value if so, and the value unchanged if not.

#### Pi Constant
This also has two solutions, one is provided again by cmath. The "USE MATH DEFINE" macro adds pi as a constant, allowing you to use M_PI whenever you want to express the value of pi.  

In case cmath is not permitted, I created an anonymous namespace to store pi as an inline constexpr. The constansts header can be included multiple times throughout the program, but since the pi variable is declared as "inline constexpr" it is only instantiated once at compile time.

##### Recognising pi from std::cin
In order that the program recognises when a user has entered "pi" as either the left or right-hand operand, I created in if statement inside each of "findAndExtractLHS" and "findAndExtractRHS" member functions of the Tokeniser class. These if statements check if the relevant substring matches "pi" (or variations involving spaces), and if so returns the pi constant (defined in the anonymous namespace). If the substring does not match "pi", the functions return the converted double of the string as usual. 


#### Other changes to the source code
I added processes to the test function of the ResultChecker class, such that each operation (multiply, add, subtract and divide) is verified to return the correct Tokeniser type. I also added a division test case to the ResultChecker, so that it calculates "18 / 6" and verifies that an answer of 3 is returned.


