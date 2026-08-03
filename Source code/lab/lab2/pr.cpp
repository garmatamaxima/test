
#include <iostream>
#include <string>
#include <cmath>

#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <climits> // for CHAR_BIT

void coutStop()
{
	int x{};
	std::cin >> x;
}

void prog()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";
	
    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
}




void prog2()
{
	std::cout << "using sizeof operator to get size of int - " << sizeof(int) << '\n';
	std::cout << "using sizeof operator to get size of char - " << sizeof(char) << '\n';
	std::cout << "using sizeof operator to get size of long - " << sizeof(long) << '\n';
	std::cout << "using sizeof operator to get size of float - " << sizeof(float) << '\n';

	char A[10];
	std::cout << "created array named A \n";
	std::cout << "using sizeof to get size: " << sizeof(A) <<'\n';

	char B[10000];
	std::cout << "created array named A \n";
	std::cout << "using sizeof to get size: " << sizeof(B) <<'\n';


}

void typeTest()
{
	int x{2'147'483'647};
	x += 1;

	int y{0};
	y = 899999999999;
}

// returns 1 if overflow
// Interesting: An algorithm that converts numbers into binary format using modulo operator, if input % 2 = 1, it assigns
// 1 to that array index, otherwise it assigns zero then divides the number until it reaches zero. 
short numberToBinary32(long long input)
{
	bool binary[32];

	for (int i{0}; i < sizeof(binary) ; i++ )
	{
		if (input % 2 == 1)
		{
			binary[i] = 1;
			std::cout << '1';
			input = (input - 1) / 2;
		}
		else
		{
			binary[i] = 0;
			std::cout << '0';
			input = input / 2;
		}
	}
	
	if (input != 0) {std::cout << " - overflow." << '\n'; return 1;}
	std::cout << '\n';
	return 0;
}






int main()
{
	for (int i{1}, ovr{0}; ovr != 1 ; i++)
	{
		std::cout << "iteration - " << i << '\n';
		ovr = numberToBinary32(std::pow(2,i));
	}

	return 0;
}