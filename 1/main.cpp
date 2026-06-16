

#include <iostream>
#include <cmath>

int test( char* input_char ) {
    printf("THE format specifier %%c - %c \n", input_char); // %c is for a single character
    printf("THE format specifier %%s - %s \n", input_char); // %s is for a string

    return 0;
}

//
float accumulator(int input1, int  input2) {
    while (setpoint < 100000000000) {

        while (clock < setpoint) {
            clock += 1;
        }
        printf("%lf \n", clock);
        setpoint = std::pow(setpoint, 1.01);

    }
}
