
#include <iostream>

int helloFunction()
{
   return 12345;
}

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}
