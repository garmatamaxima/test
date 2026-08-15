#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_literals;

int i32clamp( std::int64_t input)
{
	if (input > INT32_MAX)
	{
		return INT32_MAX;
	}
	else if (input < INT32_MIN)
	{
		return INT32_MIN;
	}
	return input;
}

/*
Write a program that asks the user to enter their full name and their age.
 As output, tell the user the sum of their age and the number of characters in their name (use the std::string::length()
  member function to get the length of the string). For simplicity, count any spaces in the name as a character.

Sample output:

Enter your full name: John Doe
Enter your age: 32
Your age + length of name is: 40
*/



int main()
{
	std::string fullName;
	int age;
	std::cout << "enter your full name" <<  '\n' ;
	std::getline(std::cin >> std::ws, fullName);
	std::cout << "enter your age" <<  '\n' ;
	std::cin >> age;

	std::cout << "your age + lenght of name == " << age + static_cast<int>( fullName.length() ) <<  '\n' ;
	return 0;
}

/*
int main()
{

	
	std::string mstrin{"xxx"s}



	std::string uinput{};
	std::getline(std::cin >> std::ws, uinput); // std::ws input manipulator allows to ignore leading whitespaces
	// aka: whitespace char's that are placed in front of any useful text chars.
	
	std::string dookiepoop{"ok"};
	std::cout << dookiepoop.length() <<  '\n' ;

	std::int64_t first_uint, second_uint;
	std::cout << "input value that contains between 1 and 15? input like that: first_input second_input" <<  '\n' ;
	std::cin >> first_uint >> second_uint;

	if (i32clamp(first_uint)  < 1 && i32clamp(second_uint) > 15)
	{
		std::cout << "true!" <<  '\n' ;
	}
	else 
	{
	std::cout << "false!" <<  '\n' ;
	}
	return 0;
}
*/
