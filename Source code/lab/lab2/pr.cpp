
#include <iostream>
#include <string>

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



int main()
{
    prog2();
	coutStop();

	return 0;
}