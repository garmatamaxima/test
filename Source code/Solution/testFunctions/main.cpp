
#include <iostream>
#include <string>

int* fooPtr(int* adress) // accepts adress as argument and stores it in pointer variable, returns that same pointer type variable
{
	*adress *= 10;
	return adress;
}

int& fooRef(int& adress) // binds reference to argument variable, then returns that same reference.
{
	adress *= 10;
	return adress;
}

const std::string& pass(const std::string& string)
{
	return string;
}


int main()
{
	int x{2};
	int y{3};

	std::cout << fooRef( x ) << '\n'; // return value is reference to x.
	std::cout << *fooPtr( &y ) << '\n'; // return value is pointer to x, which is dereferenced to read value of x.

	std::cout << '\n' << x << '\n';
	std::cout << y << '\n';


	return 0;
}