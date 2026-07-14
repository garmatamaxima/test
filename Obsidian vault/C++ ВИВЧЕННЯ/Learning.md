
#TODO Вирізка інформації з learning.cpp - [[ch1]] та [[ch2]]. треба переписати цю інформацію сюди в цей блокнот і вставити в <mark style="background: #BBFABBA6;">CHAPTER 1 та CHAPTER 2</mark>.

#TODO inline functions, inline variables. що це


# **INFOCENTER**
### *CHAR* 
Character data types are: single digit -> 'A' taking 1 byte and string "I am a string, hi" taking more than 1 byte
Values that are placed directly into the source code are called literals
!!! Leading whitespace characters are spaces, tabs, and newlines.
### *OBJECTS*
In C++, we use objects to access memory. A named object is called a variable. Each variable has an identifier (a name), a type,
and a value
A variable’s type is used to determine how the value in memory should be interpreted.
### *INSTANTIATION*
The term instantiation means that a variable has been created (allocated)
and initialized (this includes default initialization)
declaration introduces a variable name to the computer program and assigns it to a datatype.

### *STATEMENTS*
### *DATA TYPE*
### *IDENTIFIER*
### *SIDE EFFECTS*
### *UNDEFINED BEHAVIOUR*

# **POINTS OF INTEREST**

##### [[#One definition rule (ODR) |One definition rule (ODR)]]
##### [[#**Definition** and **Declaration**|Definition and Declaration]]
##### [[#Compiling it|Compiling a multi file program]]

# **CHAPTER 1 LEARNCPP.COM **

# **CHAPTER 2 LEARNCPP.COM**

### *FORWARD DECLARATION AND DEFINITION*

##### This program wont compile.

```cpp
#include <iostream>

main()
{
	std::cout << adder(5,5); // this function were not declared nor defined before.
	return 0;
}

float adder(float A, float B)
{
	return A+B;
}
```

Function `adder()` can be reordered so it is declared before `main()`

```cpp
#include <iostream>

float adder(float A, float B)
{
	return A+B;
}

main()
{
	std::cout << adder(5,5); // now compiler were provided with a valid declaration and definition of adder()
	return 0;
}
```

But that method <mark style="background: #FF5582A6;">is limited</mark>, because in some cases functions can call each other, ordering them isnt possible. This is a **circular dependency**.

```cpp
#include <iostream>

void callerOne(int input)
{
	std::cout << input + callerTwo(input); // both functions call each other.
}

void callerTwo(int input)
{
	std::cout << input + callerOne(input);
}

main() { callerTwo(callerOne);  return 0; }
```

---
##### A **forward declaration** allows to declare an identifier before defining it.
To write a forward declaration for a function, we use a **function declaration** statement (also called a **function prototype**).

``` cpp
float Adder(float Abc, float Bca); // function declaration includes: a return type, identifier and parameters (optional).

float Substract(float,float); // parameter names are optional in function declarations.
```

<mark style="background: #BBFABBA6;">Best practice:</mark> Naming parameters in function declarations.
Forward declaring a function and then not to defining it later will produce a **linker error**

```cpp
int function(int A, int B);

main() 
{
	function(2,3) + function(1,2); // Linker could not find a definition.
}
```

There are different kinds of forward declarations, specific to variables and types.  // #REMINDER 

---
##### **Definition** and **Declaration**

A declaration tells the compiler about the existence of an identifier and its associated type. While definition actually implements (for functions and types) or instantiates (for variables) the identifier. <mark style="background: #CACFD9A6;">In C++, all definitions are declarations</mark>.

```cpp
void Foo(); // function forward declaration, pure declaration

void Moo() 
{

} // function definition

int X; // variable definition

int O{}; // initalisation
```

---
##### One definition rule (ODR)

<mark style="background: #D2B3FFA6;">1.</mark>
Within a _file_, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
<mark style="background: #ADCCFFA6;">2.</mark>
Within a _program_, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file (we’ll cover this in the next lesson). Functions and variables not visible to the linker are excluded from this rule
<mark style="background: #FF5582A6;">3.</mark>
Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical. .


### PROGRAMS WITH MULTIPLE CODE FILES

##### Programs with multiple code files allow to split program's **source code** into different modules
That allows for better design practices.

<mark style="background: #CACFD9A6;">hello.cpp</mark>
```cpp
int helloFunction()
{
   return 12345;
}
```

<mark style="background: #CACFD9A6;">main.cpp</mark>
```cpp
#include <iostream>

int helloFunction(); // Function prototype

main()
{
   std::cout << "I am using a function that exist inside other file: " << helloFunction();
   return 0;
}

```

---
##### Compiling it 
A specific command in powershell is needed:
```powershell
g++ main.cpp hello.cpp -0 program.exe
```

`g++` is the program being called in terminal.
`main.cpp hello.cpp` are files used in **compile line**
`-o` is an **optimisation flag**
`program.exe` is a name of a program

<mark style="background: #FF5582A6;">A mistake:</mark>
```powershell
g++ main.cpp -o program.exe
```

a linker error will appear -> ``undefined reference to `helloFunction()' `` , while function prototype `int helloFunction()` was given, no actual definition of `helloFunction()` body were given
Because it is located in a different code file.



#TODO Важко сформувати думку для нотатки тут. закінчив на [https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/](https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/#:~:text=Your%20compiler%20may%20compile%20either%20add%2Ecpp%20or%20main%2Ecpp%20first%2E%20Either%20way%2C%20main%2Ecpp%20will%20fail%20to%20compile%2C%20giving%20the%20same%20compiler%20error%20as%20the%20previous%20example)


