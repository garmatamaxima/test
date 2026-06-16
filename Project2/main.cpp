
#include <iostream>
#include <math.h>
#include <windows.h>

float quadratic_value = 2.000f;
float constant_value = 0.000f;
float linear_value = 1.000f;
bool runloop = 1;

float discriminant(float quadratic, float linear, float constant) {
	return linear*linear - 4 * quadratic * constant;
}

float quadratic_equation(float quadratic, float linear, float constant, bool is_positive) {
	float discriminantv = discriminant(quadratic,linear,constant);
	
	if (is_positive) {
		return (-linear + sqrt(discriminantv))/(2*quadratic);
	} else {
		return (-linear - sqrt(discriminantv))/(2*quadratic);
	}
	
}

float exponent(float input, int exponent) {

	for (int i = 0; i < exponent; i++) {
		input = input * input;
	}
	return input;
}

void ask_values() {
	printf("INPUT QUADRATIC COEFFICIENT \n");
	scanf_s("%f", &quadratic_value );

	printf("INPUT LINEAR COEFFICIENT \n");
	scanf_s("%f", &linear_value );
	
	printf("INPUT CONSTANT  \n");
	scanf_s("%f", &constant_value );


	printf("YOUR INPUTS ARE: ( QUADRATIC COEFFICIENT: %0.3f", quadratic_value);
	printf(" + ACTUAL QUADRATIC VALUE: %0.3f", (quadratic_value * quadratic_value));

	printf(" + LINEAR: %0.3f", linear_value);
	printf(" + CONSTANT %0.3f \n", constant_value);	
 
	Sleep(700);
	
	printf("DISCRIMINANT: %f \n",discriminant(quadratic_value, linear_value, constant_value));
	printf("QUADRATIC FORMULA OUTPUTS: +x -> %0.10f", quadratic_equation(quadratic_value, linear_value, constant_value, 1));
	printf(", -x -> %0.10f \n", quadratic_equation(quadratic_value, linear_value, constant_value, 0));
	printf("------------- \n");
}





int main() {
	
	std::cout << " ";

	while (runloop) {
		ask_values();
	}
	return 0;
}

