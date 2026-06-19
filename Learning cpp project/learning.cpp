
//To use the functionality defined within the iostream library, we need to include the iostream header at the top of any code file 
// that uses the content defined in iostream
#include <iostream>

/*
    QUICK FACTS::
    
    // ---- CHAR: ----
    Character data types are: single digit -> 'A' taking 1 byte and string "I am a string, hi" taking more than 1 byte 
    Values that are placed directly into the source code are called literals
    
    // ---- OBJECTS: ----
    In C++, we use objects to access memory. A named object is called a variable. Each variable has an identifier (a name), a type, 
     and a value
    A variableТs type is used to determine how the value in memory should be interpreted.
    
    // ---- INSTANTIATION: ----
    The term instantiation is a fancy word that means a variable has been created (allocated) 
    and initialized (this includes default initialization)
*/


void asignment_and_initalisation() {

    std::cout << "/ This is Assignment and Initalisation outputs: \n";

    // ---- DIRECT LIST INITALISATION, or just LIST INITALISATION: ----

    /* 
    this is definition and initalisation of a variable, ( is it declaration?? who knows... )
    "=" is an assignment operator
    "{}" is an initializer (The process of specifying an initial value for an object)
    */ 
    
    // (Plain english) -- define a variable named "first" of type integer then initalise it with initial value 1.
    int first {1};

    std::cout << "list init >>" << first << "\n";

    // ---- ZERO INITALISATION, VALUE INITALISATION: ----
    
    int width{}; // will implicitly initialize the variable to zero

    std::cout << "zero init >> " << width << "\n";


    // ---- COPY LIST INITALISATION: ----

    // Rarely used

    // (Plain english) -- define a variable named "alpha" of type integer then initalise it with initial value 1.
    int alpha = { 1 };

    std::cout << "copy list init >> " << alpha << "\n";

    // ---- COPY INITALISATION: ----
    
    // different syntax for initalising a variable
    // (Plain english) -- define a variable named "second" of type integer then initalise it with initial value of 1
    int second = 1;

    std::cout << "copy init >> " << second << "\n";

    // ---- DIRECT INITALISATION: ----

    // Potentially dangerous!
    // (Plain english) -- define a variable named "third" of type integer then initalise it with initial value of 1
    int third (1);

    std::cout << "direct init >> " << third << "\n";

    // ---- ASSIGNMENT: ----

    // this is assignment of a variable named "first", assignment is done to existing variable only
    // (Plain english) -- variable "first" is equal to 3
    first = 3;

    std::cout << "Assignment of variable to different value >> " << first << "\n";

    // ---- IMPORTANT TO KNOW!!!: ----
    
    /* (Narrowing conversions) --

    * Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold
    * such a conversion is a narrowing conversion, since the fractional part of the value will be lost, compiler will gladly convert
     4.5 to 4.
    * LIST INITALISATION will throw an compile error, because it does not allow it.

    */


}

void may_be_unused() {

    // ---- MAY BE UNUSED: ----

    /*
    Some values can be unused which is undesirable
    But sometimes you can have a list of variables that have to be saved for later use
    */
    // [[maybe_unused]] is an attribute, which tells compuler that variable is okay to be unused
    [[maybe_unused]] double pi{ 3.14159 };
    [[maybe_unused]] double randomsomething{ 2323.54359 };
    [[maybe_unused]] int one{ 1 }, two{ 2 }, three{ 3 };
    
    // legal but bad practice
    int i_am_useless{ 1 };



}


void iostream_tutorial() {

    float a_variable{123.233412342};

    /*
    "std::cout" is a statement (оператор), std:: means we take a function from standart library, cout is the part of iostream library
     inside standart library
    "cout" stands for "Character Output"
    "<<" INSERTION OPERATOR: allows to display information on console and concatenate (connect strings together, обЇднувати р€дки у один)
    "\n" is a format specifier, it allows for walking to a next string in console, moves console cursor to new line
    "std::endl" also moves console cursor to new line + flushes the buffer of a console 
    */
    std::cout << "Hello World!, i am std::cout function!" << std::endl;
    std::cout << "numbers... " << 1 << ", " << 1.001 << ", " << a_variable << "\n";
}


int main()
{   
    iostream_tutorial();
    asignment_and_initalisation();
    may_be_unused();


    return 0;
}

