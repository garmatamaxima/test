
#include <iostream>

// Function prototypes
int helloFunction();
int getInteger();
//

int main()
{
   std::cout << "I am using a function that exist inside other file: " << helloFunction();

   int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << x + y << '\n';
	std::cin >> x;

	return 0;
}
