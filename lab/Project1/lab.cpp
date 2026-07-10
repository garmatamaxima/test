
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <string>

using namespace std;

/*
	A function that approximates some kinda growth
	also calculates redundanly more of other math operations.
*/
float growthMultiLoop(float value, float multiplier, int iterations)
{
	float value_old{ 0 };
	float value_sum{ value };
	float value_average{ 0 };

	// std::fixed: tells the cout function to not format outputs using scientific notation.
	std::cout << std::fixed << "\n";

	for (int i{ 1 }; i <= iterations; i++)
	{
		// copies old value for later use.
		value_old = value;
		// accumulation
		value = value * multiplier;
		// summation
		value_sum += value;
		// average
		value_average = value_sum / (i+1);
		std::cout << "Step: " << i << ", value: " << value << ", old: " << value_old << ", Difference: " << value - value_old << '\n';
		std::cout << "sum: " << value_sum << " average: " << value_average << "\n\n";
	}
	std::cout << "Final value = " << value << "\n";

	return value;
}

void growthProgram()
{
    float x{ 0 };
	float multiplier{ 1 };
	int iterations{ 1 };

    // prompt user for initial variables they want to provide.
	std::cout << "starting value: ";
	std::cin >> x;

	std::cout << "multiplier: ";
	std::cin >> multiplier;

	std::cout << "steps: ";
	std::cin >> iterations;
	//

	growthMultiLoop(x, multiplier, iterations);
}

int main()
{
    //  main's variables
	bool workloop = true;

	while (workloop)
	{
	    cout << "Enter your action: 1 - Growth loop program, 2 - fun, exit - ends the program.  ";

		string inputvar{};
        cin >> inputvar;

        // top 1 goated programming techniques - if wall
        if (inputvar == "1")
        {
            growthProgram();
            cout << '\n';
        }
        else if (inputvar == "2")
        {

        }
        else if (inputvar == "exit")
        {
        workloop = false;
        }
	}



	return 0;
}
