# Ampify engineering placement test

This repository contains the technical tests for engineering placement students at Ampify.

This test contains 2 technical tasks. You are required to complete both of the tasks. 
The first task must be completed in **C++**, and the second task can be completed in either **Javascript (Node), Python or Ruby**. 

Please be sure to pay close attention to the requirements of the task as well as the expected input and outputs. Feel free to use any compiler/IDE/workflow you wish, but please detail your choice in your solution, so we can compile what you have written.

When submitting your solution, you should include the following:

+ A compiled version of the command line application
+ Changed source code
+ Any additional files that are required to make your program work.

For submission, you can email us a link to your git fork. This is our preference. Alternatively you can send in zip files of your build. 
*Remove any build artefacts first*

These tasks will help us understand your skill set and abilities, including what you have learnt so far during your studies. Whilst working on these tasks, feel free to use any resources you like, but make sure that they are credited in your code (in whatever way you wish).

Your submission should meet the following requirements:

+ The command line application should read input from stdin and require no additional options to run
+ All outputs should go to stdout
+ For the C++ task, you must use *only the STL and the C stdlib (C++17)*. You may not use any additional libraries or frameworks (i.e. no Juce).
+ For the scripting task (Node, Ruby, Python), you may include additional dependencies. If you do this, please include a `package.json` or other similar management file.
+ Include a readme that explains what you did and how to compile and run your software


## C++ Calculator

We have provided you with a simple C++ calculator that currently performs addition, subtraction and multiplication. 

`The source code for the calculator is in calculator-main.cpp in the root of this repository`

This task falls into three parts:

+ Add division to the calculator
+ Find and fix any problems
+ Add `pi` to the calculator as a constant (so instead of typing in 3.141 you can just use `pi` instead)

The calculator should request the input calculation, and then perform the computation. 
You can refactor the starting code in any way you like, except for changing the main function.

The following examples should be computed properly:

```
10 * 4
25.3 + 18.6
3-5.6
pi * 5 (to five decimal places)
```

## Web API Parsing

The Ampify API powers many of our applications. It provides information to our applications by returning JSON data, which can then be used to display information to customers. 

This task falls into 4 parts:

+ Write a simple script that downloads the content of https://api.ampifymusic.com/packs 
+ Parse the response and sort it into a set of genres
+ Print out a list of all the genres
+ Print out a list of all the packs in the genre ‘hip-hop’

You cannot cache theses results; the program must pull this information from the URL each time the script is run. No arguments should be required to run your script, and it should be easily callable using the default interpretter. 