#include <iostream>

void dookiepoop(int& input, int* dookie)
{
/*
	std::cout << input << '\n';
	input = input + 100;

	std::cout << dookie << '\n';
	std::cout << *dookie << '\n';
*/
}


void passByPointer_andDereferencing(int* input) // declaring a separate new pointer type variable for this function. 
{
	int x{}; // creating a temporary variable for demonstration
	x = *input; // dereferencing operator, takes an value stored in that adress.

	*input = *input + 10; // dereferencing an pointer to assign its value + 10.
}

void passByReference(int& input) // creates an alias variable to passed variable, it holds its value and adress, and can change it.
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
	int* y_p = &y;

	passByReference(y); // passing an variable that this function will create an alias for, and then will modify this variable itself.

	std::cout << "y after being mutated by other function: " << y << '\n';





/*
	int x{10};
	int* x_p = &x;

	int h{1155};
	int* h_p = &h;
	

	dookiepoop(x, h_p);
	std::cout << x;
*/
	return 0;
}