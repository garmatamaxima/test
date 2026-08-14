
#include <iostream>

constexpr int cexprMath(int op1, int op2, int op3)
{
	return (op1 / op2) * op3;
}

int main()
{
	constexpr int xx{cexprMath(50, 2, 4)};
}