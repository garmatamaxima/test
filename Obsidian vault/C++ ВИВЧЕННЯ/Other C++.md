
### `<iomanip>`
part of iostream?? #Note_for_future 

###### `std::setw` -  sets the width of the subsequent output


### `<climits>`

##### `CHAR_BIT` - preprocessor macro, evaluates to 8.

### Pointers and references

```cpp
#include <iostream>

void passByPointer_andDereferencing(int* input) // declaring a separate new pointer type variable that will copy passed variable's adress. (pass by value)

{
    int x{}; // creating a temporary variable for demonstration
    x = *input; // dereferencing operator, takes an value stored in that adress.
    *input = *input + 10; // dereferencing an pointer to assign its value + 10.
}

void passByReference(int& input) // creates an alias to passed variable, it holds variable's value and adress, and can change it.

{
    std::cout << "proving that alias for y is true: " << input << '\n';
    input = 1000;
}


int main()

{
    // -- POINTERS and DEREFERENCING --------------------------------------------
    
    int x{100}; // declaring a variable with type int.
    int* x_p = &x; // declaring a variable with a type integer pointer, assigning a reference to adress of x. This now holds an adress.
    // &p is an operator that returns adress of variable attached.

    std::cout << "x before being mutated (changed) by other function: " << x << "\n";

    passByPointer_andDereferencing(x_p);

    std::cout << "x after being mutated by other function: " << x << "\n";

    //-- ALIASES and REFERENCES -------------------------------------------------
    
    int y{50};
    
    passByReference(y); // passing an variable that this function will create an alias for, and then will modify this variable itself.

    std::cout << "y after being mutated by other function: " << y << '\n';

    // good practice part 1: not using aliases in function declarations, that is a possibility of a bug where programmer unknowingly passes a  
    // variable
    // to an alias and it mutates the program in a bad way.

    // good practice part 2: Safe practice is to pass by pointer, so compiler will enforce knowledge of using a pointer.

    return 0;
}
```