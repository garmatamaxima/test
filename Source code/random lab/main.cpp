
#include <iostream>

int helloFunction(); // Function prototype

main()
{
   std::cout << "I am using a function that exist inside other file: " << helloFunction();
   return 0;
}
