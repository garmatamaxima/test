
#include <iostream>
#include <cmath>

/*
	A function that approximates mulpiplicative growth
	also calculates redundanly more of other math operations.
	DO_PRINT allows to output values in chat as function iterates.
*/
float growthMultiLoop(float value, float multiplier, int iterations)
{
	float value_old{ 0 };
	float value_sum{ value };
	float value_average{ 0 };

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




		// std::fixed: tells the cout function to not format outputs using scientific notation.
		std::cout << "Step: " << i << ", value: " << value << ", old: " << value_old << ", Difference: " << value - value_old << '\n';
		std::cout << "sum: " << value_sum << " average: " << value_average << "\n\n";
	}

	std::cout << "Final value = " << value << "\n";

	return value;
}

float quadratic(float a, float b, float c)
{
	float discriminant = b * b - 4 * a * c;
	float root1 = (-b + sqrt(discriminant)) / (2 * a);
	float root2 = (-b - sqrt(discriminant)) / (2 * a);
	std::cout << "Root 1: " << root1 << ", Root 2: " << root2 << "\n";
	return root1;
}

int main()
{
	bool workloop = true;
	float x{ 0 };
	float x_old{ 0 };
	float multiplier{ 1 };
	int iterations{ 1 };

	while (workloop)
	{
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

	return 0;
}
