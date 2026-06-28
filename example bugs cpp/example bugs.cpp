
#include <iostream>


// ---- COMPILER BUGS: ----

// its not allowed to define function inside function.
void bug_recursive_function_definition()
{
    int function2() { return 0; }
}

// ---- RUNTIME BUGS: ----

/*
2026.06.20
learncpp chapter 1.5
Inputting different data type into cin will result in function locking its buffer to 0 and failing extraction
*/
void BUG_cin_buffer() {

    int value{};
    
    // inputting char value into the function will break it
    std::cin >> value;

}



// ---- INITALISATION ERRORS: ----


/*
Redefinition
*/
void BUG_redefinition() {

    int x{}
    int x{}
}



/*
2026.06.19
learncpp chapter 1.4
Using uninitalised value that will produce garbage data and undefined behaviours, compiler catches it usually.
OR Default initalisation leaves the variable with an indeterminate (random) value, very bad practice
*/
void BUG_garbage_initalisation() {

    // When no initaliser is provided for initalising a variable, it will hold a random value that was sitting in that memory adress
    float garbage;
    std::cout << garbage;
    
}

// GOOD PRACTICE:
void good_initalisation() {

    // List initalisation
    float not_garbage{0.00};
    std::cout << not_garbage;
    
}
//----

/*
2026.06.15
learncpp chapter 1.4
Attempting to initalise a float when integer was specified using list initalisation. Compiler throws an error
*/
int BUG_narrowing_conversion() {

    // compiler will kill that one, good bug
    int alpha{ 6.111 };
    // value will be truncated and set to 0, bad bug
    int beta = 0.01;
}
// GOOD PRACTICE:
void narrowing_conversion_prevention() {
    
    // just use list initalisation, errors will be caught at compile time usually
    int theta{ 1 };
    // when you want to truncate it deliberately, its fine
    int omega = 1.1;

}
// ----



// must have A SINGLE main function in a program, if you have no main() then program wont compile
// returning non 0 value is a bad practice when program finishes properly
int main() {


	return 1;
}
