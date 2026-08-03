#include <iostream>

int main()
{
	unsigned short x{65535}, y{65535}; 
	x = x+1;
	y = y+15;

	std::cout << x; // will wrap around and output 15
	return 0;
}