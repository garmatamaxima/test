
#include <iostream>

/*
    QUICK FACTS::
    
    // ---- CHAR: ----
    Character data types are: single digit -> 'A' taking 1 byte and string "I am a string, hi" taking more than 1 byte 
    Values that are placed directly into the source code are called literals
    
    // ---- OBJECTS: ----
    In C++, we use objects to access memory. A named object is called a variable. Each variable has an identifier (a name), a type, and a value
    A variable’s type is used to determine how the value in memory should be interpreted.


*/


void tutorial_asignment_and_initalisation() {

    // ---- DIRECT LIST INITALISATION, or just LIST INITALISATION: ----

    /* 
    this is definition and initalisation of a variable, ( is it declaration?? who knows... )
    "=" is an assignment operator
    "{}" is an initializer (The process of specifying an initial value for an object)
    */ 
    
    // (Plain english) -- define a variable named "first" of type integer then initalise it with initial value 1.
    int first {1};

    std::cout << first << "\n";

    // ---- COPY LIST INITALISATION: ----

    // Rarely used

    // (Plain english) -- define a variable named "alpha" of type integer then initalise it with initial value 1.
    int alpha = { 1 };

    std::cout << alpha << "\n";

    // ---- COPY INITALISATION: ----
    
    // different syntax for initalising a variable
    // (Plain english) -- define a variable named "second" of type integer then initalise it with initial value of 1
    int second = 1;

    std::cout << second << "\n";

    // ---- DIRECT INITALISATION: ----

    // different syntax for initalising a variable
    // (Plain english) -- define a variable named "third" of type integer then initalise it with initial value of 1
    int third (1);

    std::cout << third << "\n";

    // ---- ASSIGNMENT: ----

    // this is assignment of a variable named "first", assignment is done to existing variable only
    // (Plain english) -- variable "first" is equal to 3
    first = 3;

    std::cout << first << "\n";



}

void tutorialcout() {

    // "std::cout" is a statement (оператор), std:: means we take a function from standart library, cout is the part of iostream library inside standart library
    // "cout" stands for "Character Output"
    // "<<" operator allows to display information on console and concatenate (connect strings together, обєднувати рядки у один)
    // "\n" is a format specifier, it allows for walking to a next string in console 
    std::cout << "Hello World!\n";
    std::cout << "Українською " << "також!\n"; // C++ компілятор (compiler) української мови не знає
    std::cout << 'A' << "\n";


}


int main()
{   
    tutorialcout();
    
    
    tutorial_asignment_and_initalisation();

    return 0;
}

