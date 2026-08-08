#include <iostream>

int main()
{
  double height{};
  std::cout << "How tall are you? (cm) \n"; 
  std::cin >> height;
  if (height > 140.0) 
  {
	std::cout << "Have fun!\n";
	return 0;
  }
  std::cout << "Sorry, you're too short.\n";
  return 0; 
}