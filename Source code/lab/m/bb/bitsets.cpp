
#include <iostream>
#include <string>
#include <string_view>
#include <bitset>
#include <cstdint>

#include "bitsets.h"

namespace glob // user defined namespace
{
	// external linkage constant global variable - visible in other translation units (TU's) due to being external, value cant be changed (global).
	// lifetime - created at the beginning of a program before main(), destroyed when program terminates
	// scope - visible in any block.
	// linkage - external, can be acessed in other TU's.
	extern const float g_somebit_bullshit{ 0.1f }; 
	
	// internal linkage constant global variable - visible inside this TU, value cant be changed (global).
	// lifetime - created at the beginning of a program before main(), destroyed when program terminates
	// scope - visible in any block.
	// linkage - internal, can be acessed in this file.
	static const int dihsize_cm{ 15 };

	// constexpr global variable -  visible inside this TU, cant be changed (constexpr variables need to guarantee being constant)
	// lifetime - created at the beginning of a program before main(), destroyed when program terminates
	// scope - visible in any block.
	// linkage - internal, can be acessed in this file.
	constexpr int mama_mia{ 0 };

	// const global variable -  visible inside this TU, cant be changed (globals enforce read only)
	// lifetime - created at the beginning of a program before main(), destroyed when program terminates
	// scope - visible in any block.
	// linkage - internal, can be acessed in this file.
	const int im_maximalistic_person{ INT32_MAX };

	namespace bob // nested namespace
	{
	
	
	
	}

}




std::bitset<8> leftrotate(std::bitset<8> bitset_)
{
	bool leftbit = bitset_.test(0);
	bitset_ >>= 1;
	bitset_.set(7, leftbit);
	return bitset_;
}

std::bitset<4> rotl(std::bitset<4> bits)
{
	// bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits << 1) | (bits >> 3);
}

int main()
{
	std::bitset<8> myvar{ 0b1100'1000 };
	std::bitset<8> originalbuffer{ myvar };

	std::cout << '\n' << "original bitset = " << myvar << '\n';

	myvar = leftrotate(myvar);
	std::cout << myvar << '\n';

	for (int i{}; originalbuffer != myvar; ++i)
	{
		myvar = leftrotate(myvar);
		std::cout << myvar << '\n';
	}
	
	std::bitset<4> bitset4{ 0001 };
	std::bitset<4> bitset4_buffer{ bitset4 };

	std::cout << "orig bitset4 - " << bitset4 << "\n";
	
	bitset4 = rotl(bitset4);
	std::cout << bitset4 << "\n";

	for (int i{}; bitset4_buffer != bitset4; ++i)
	{
		bitset4 = rotl(bitset4);
		std::cout << bitset4 << '\n';
	}




g	return 0;
}