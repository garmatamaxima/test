 
#TODO Вирізка інформації з learning.cpp - [[ch1]] та [[ch2]]. треба переписати цю інформацію сюди в цей блокнот і вставити в <mark style="background: #BBFABBA6;">CHAPTER 1 та CHAPTER 2</mark>.

#TODO inline functions, inline variables. що це

## Assumptions:
compiler toolkit - g++, visual studio compiler, visual studio code compiler
CPU - x64 bit

# **TERMINOLOGIES**
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

CH1
##### [[#^3aeab3|Compiler warning levels]] - Compiler arguments meant to catch more errors

CH2
##### [[#One definition rule (ODR) |One definition rule (ODR)]]  - the rule that prevents naming collisions
##### [[#**Definition** and **Declaration**|Definition and Declaration]] - methods of introducing objects to program
##### [[#Compiling it|Compiling a multi file program]]
##### [[#^33cf99|Naming collisions]]
##### [[#^235c54|Scope resolution operator ::]]
##### [[#^49acb7|Translation unit]]
##### [[#^a80905|Including paired header files to source files]]
##### [[#^861673 |Include directories / where std comes from]]
##### [[#^b8be34|Header guards]] - A technique to prevent ODR violations and repeating header includes
##### [[#^52f271|How to design a program]] 

CH3
##### [[#^72040d|How to debug using VS Code]] 
##### [[#^4894b0|The call stack explanation]] 

CH4 
##### [[#^cd24be|Integral (integer) data type]],  [[#^63210c|Fundamental data types table]] 
##### [[#^ce9f81|Fundamental data types size assumptions or standarts]] 


# **MAKING BUGS AND REGRETTING IT**

##### [[#^83565d|Redefinition of a function]]
##### [Over-optimisation mistake](https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/#:~:text=New,substantive)
# **CHAPTER 1 ** ...

### COMPILER WARNING LEVELS

^3aeab3

https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/

# **CHAPTER 2** Headers & preprocessor

### FORWARD DECLARATION AND DEFINITION
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
To write a forward declaration for a function, we use a **function declaration** statement (also called a **function prototype**). ^b6dea4

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
##### Definition and Declaration

A declaration tells the compiler about the existence of an identifier and its associated type. While definition actually implements (for functions and types) or instantiates (for variables) the identifier. **In C++, all definitions are declarations**.

```cpp
void Foo(); // function forward declaration, pure declaration

void Moo() 
{

} // function definition

int X; // variable definition

int O{}; // initalisation
```

![[definitionAnddeclaration| 100%x80]]

---
##### One definition rule (ODR)

<mark style="background: #ABF7F7A6;">1.</mark>
Within a _file_, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
<mark style="background: #ABF7F7A6;">2.</mark>
Within a _program_, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file (we’ll cover this in the next lesson). Functions and variables not visible to the linker are excluded from this rule
<mark style="background: #ABF7F7A6;">3.</mark>
Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical. . ^e89dae


### PROGRAMS WITH MULTIPLE CODE FILES
##### Programs with multiple code files allow to split program's **source code** into different modules
That allows for better design practices.

**The order in which compiler compiles files is not relevant**

<mark style="background: #FFF3A3A6;">!!!</mark>  Compiler compiles each code file individually, so each file has to include preprocessor direcrtives like `#include <some header>` or `#include some_file.cpp`, that ensures each file compiles and links to those external files.

 When an identifier is used in an expression, the identifier must be connected to its definition.
 
- If the compiler has seen neither a forward declaration nor a definition for the identifier in the file being compiled, it will error at the point where the identifier is used.
- Otherwise, if a definition exists in the same file, the compiler will connect the use of the identifier to its definition.
- Otherwise, if a definition exists in a different file (and is visible to the linker), the linker will connect the use of the identifier to its definition.
- Otherwise, the linker will issue an error indicating that it couldn’t find a definition for the identifier.


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


### NAMESPACES
##### In c++ two identical identifiers are not allowed
this produces an error called **naming collision** or **naming conflict**.  ^33cf99

<mark style="background: #CACFD9A6;">main.cpp</mark>
```cpp
int myFunc() // a working code file 
{
	return 0;
}

int main() 
{ 
	myFunc();
	return 0;
}
```

<mark style="background: #CACFD9A6;">a.cpp</mark>
```cpp
int myFunc() // a working code file too, the problem will arise in improper compilation or linking
{
	return 0;
}
```

compiling it like this `g++ main.cpp a.cpp -o program.cpp`  will produce a linker error error. Linker will notice a redefinition of `myFunc()` and throw an error.

<mark style="background: #FF5582A6;">linker error</mark>
will occur in cases if there were defined two identical named functions or global variables in one program.
<mark style="background: #FF5582A6;">compiler error</mark>
will occur in cases if there were defined two identical named functions or global variables in one file.

---
##### Scope regions
Two identifiers with the same name are allowed be declared in different scope regions. But within a scope region all identifiers must be unique

<mark style="background: #FFF3A3A6;">!!!</mark> The body of a function is a scope region
```cpp
void apples() 
{
	double x{}, y{}, z{};
}
void bananas() 
{
	double x{}, y{}, z{}; // no naming collision! they live in different scopes
}
```

---
##### Namespaces
provide a scope region called **namespace scope**, names declared in namespaces are isolated from other scopes. Two functions with identical declarations can be defined inside different namespaces, and no [[#^33cf99| naming collision]] will occur.

In c++ any name/identifier that is not defined inside a class, function or a namespace is a part of a **global namespace** or **global scope** 

![[scope_namespace|620x220]]

<mark style="background: #ABF7F7A6;">1.</mark> identifiers declared inside the global scope are in scope from the poin of declaration to the end of file.
<mark style="background: #ABF7F7A6;">2.</mark> variables can be defined in global scope, but this is <mark class="hltr-red">bad practice</mark>

The `::` symbol is an operator called the **scope resolution operator**, the identifier to the left of the symbol identifies namespace, the symbol to the right of `::` operator is the identifier inside this namespace. 
When an identifier includes a namespace prefix, the identifier is called a **qualified name**. ^235c54

##### Using namespace std
a way to access identifiers inside a namespace is to use a **using-directive statement**, it allows to acces the names inside a namespace without using a namespace prefix. 

This is <mark style="background: #FF5582A6;">bad practice</mark> to use identifiers from [[#std library|std library]]. If standart library will get updated in the next version of c++, new names/identifiers will conflict with old ones in the global namespace.

<mark style="background: #CACFD9A6;">main.cpp</mark>
```cpp
#include <iostream> // imports declaration of std::cout into the global scope

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}
```

--- 
##### Curly braces and intended code
are often used to delineate a scope region that is nested within another scope region,braces are also used for some non-scope-related purposes, such as list initialization

```cpp
int foo(int A, int B) // parameters are within scope of this function
{ // braces used to delineate nested scope region for function foo()
	return A + B; 
} // A and B go out of scope here

int main()
{ // braces used to delineate nested scope region for function main()
    foo(5);

    int x { 6 }; // x is defined within the scope of main()
    std::cout << x << '\n';

    return 0;
} // x goes out of scope here
// foo and main (and std::cout) go out of scope here (the end of the file)
```

### PREPROCESSOR

each code file goes through the preprocessor first, then compiler.  The stage where preprocessor works is called **Preprocessing phase**, when preprocessor runs it scans through code file searching for **preprocessor directives**. <mark class="hltr-yellow">!</mark> preprocessor does not use C++ syntax  

The final output of the preprocessor contains no directives -- only the output of the processed directive is passed to the compiler. The final output of preprocessor is called **translation unit**
Preprocessor also removes comments and ends each translation unit in a newline character ^49acb7

All preprocessor directives end on a newline, not a semicolon (the statement).

##### `#Include`
is a preprocessor directive used for including header files. Preprocessor then replaces the directive with the contents of a file included. 
<mark style="background: #FFF3A3A6;">!</mark> Preprocessor can process directives recursively, if included file has directives, it will process them too.

`#include` directive can include: Header files, source code files, std headers.

```cpp
#include <iostream> // preprocessor will replace this directive with contents of iostream header
#include "adder.h" // can also include header files
#include "friend.cpp" // and cpp files

using namespace std

int main() 
{
	cout << "im lucky bon bon"
	return 0;
}
```

<mark class="hltr-orange">An important reminder</mark> - preprocessor directly inserts contents of an included files, replacing the `#include` directive.

##### `#define`
The `#define` directive can be used to create a macro. In C++, a **macro** is a rule that defines how input text is converted into replacement output text.
There are two basic types of macros: _object-like macros_, and _function-like macros_.

Macros are useful in a technique called **header guard**, that allows to use `#ifndef` directive to include header contents only once.

```cpp

#define MACRO "name" // will replace each MACRO by "name"

```
##### `#if`
 #TODO на learn.cpp є матеріал глава 2.10
##### `#endif`
#TODO на learn.cpp є матеріал глава 2.10

##### `#ifndef`
Is a directive that means "If not defined", it is useful in a technique called **header guard**, to prevent including header files more than once ^b8be34

<mark class="hltr-grey">myHeader.h</mark>
```cpp
#ifndef MY_IDENTIFIER // if this preprocessor identifier were not defined, it will execute that preprocessor command
#define MY_IDENTIFIER // defines identifier that later will prevent preprocessor logic from uncluding this block untill #endif

int functionA(int,float); // function prototype.
#endif // ends preprocessor if logical block.
```

##### `#pragma`
other version of header guard. я лінийвий щоб писати 😭 #TODO 


### HEADER FILES

Header files have .h extension, but in some cases they can have .hpp or no file extension at all
<mark class="hltr-yellow">!</mark> header files are used to add a bunch of related forward declarations into a code file 

what problem do they solve? - manually adding [[#^b6dea4| function prototypes]] into every source code file is tedious, so it was automated using preprocessor and header files. <mark class="hltr-purple">!</mark> They mainly allow to link libraries together.

```cpp
#include <iostream> //including std header file

#include "adder.h" //including user defined header file
```

<mark class="hltr-green">Good practice: </mark> - to pair .cpp and .h files together with same name. Source files (.cpp) should `#include` their headers. This allows to pinpoint some redefinition bugs that can appear. ^a80905

---
**When  `<>` and `""` are used**
When including headers, headers that are not written inside this program are included using angled brackets (`<>`) while headers that are part of this program and its main folder are included using quotation marks (`""`). 

Angled brackets `<>` specify to preprocessor to search for header files inside **include directories**. The include directories are part of compiler settings, come from directories containing the header files that come with compiler toolchain and/or OS ^861673

![[preprocessor include rules | 500x400]]

---
##### Redefinition errors when including header files

^83565d

**Defining same function 2 times**
putting variables and function bodies/definitions into header files can lead to [[#^e89dae| One definition rule violations]]

<mark class="hltr-grey">demo.h</mark>
```cpp
int redefinitionDemo(double Xx)
{
   return Xx;
}
```

<mark class="hltr-grey">main.cpp</mark>
```cpp
#include "hello.h"
#include <iostream>

int redefinitionDemo(double Yy)
{
   return Yy;
}

int main()
{

   std::cout << redefinitionDemo(5);
	return 0;
}
```

leads to `error: redefinition of 'int redefinitionDemo(double)'` error when compiled using terminal `g++ main.cpp hello.h -o program.exe `

**Another example:**

**Declaring same function with different return types that results in redeclaration error!**
when add.cpp and add.h are paired, they can help to catch redefinition error

<mark class="hltr-grey">add.h</mark>
```cpp
int add(int x, int y);
```

<mark class="hltr-grey">add.cpp</mark>
```cpp
#include "add.h"         // copies forward declaration from add.h here

double add(int x, int y) // oops, return type is double instead of int
{
    return x + y;
}
```

<mark class="hltr-grey">main.cpp</mark>
```cpp
#include "add.h"
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

when compiled using g++ in terminal: `g++ main.cpp add.cpp add.h -o program.cpp `  // <mark class="hltr-yellow">reminder:</mark> `.cpp files should be also included with .h files, so linker can reach actual definition`

it will produce an error `error: ambiguating new declaration of 'double add(int, int)'` - compiler computes that function declaration inside .h file and definition inside .cpp file do not match, so it throws an error.

#Note_for_future  this doesn’t work if it is a parameter with a different type instead of a return type. This is because C++ supports overloaded functions (functions with the same name but different parameter types), so the compiler will assume a function with a mismatched parameter type is a different overload.  <mark class="hltr-cyan">source: </mark> [learn.cpp](https://www.learncpp.com/cpp-tutorial/header-files/#:~:text=Unfortunately,all)

##### Source files should not be included
this can lead to redefinition errors / naming collisions. 

##### Why doesnt Iostream have an .h extension?
#TODO пройтись по цьому матеріалу [learn.cpp](https://www.learncpp.com/cpp-tutorial/header-files/#:~:text=Why%20doesn%E2%80%99t%20iostream%20have%20a%20%2Eh%20extension) Та також вся 2.11 глава після цього теж

### **How to design a program**

^52f271

https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/

# **CHAPTER 3** Debug

### **SYNTAX AND SEMANTIC ERRORS**

##### Syntax errors
Syntax errors occur when statements that are not valid according to grammatic rules of  C++ language, 
<mark class="hltr-yellow">!</mark> The compiler catches syntax errors and highlights them in console.

```cpp
#include <iostream>

int main( // missing closing brace
{
    int 1x; // variable name can't start with number
    std::cout << "Hi there"; << x +++ << '\n'; // extraneous semicolon, operator+++ does not exist
    return 0 // missing semicolon at end of statement
}
```

##### Semantic errors
error in meaning, either violates the rules of the language, or a statement does a wrong action alltogether

```cpp
int main()
{
    5 = x; // x not declared, cannot assign a value to 5
    return "hello"; // "hello" cannot be converted to an int
}
```

these can appear at runtime, which is the worst case of  an semantic error. 

### DEBUG INSIDE SOURCE CODE

##### placing `std::cerr` inside a code file to debug

#TODO 
##### Debug method: narrowing down the problem using hi-lo method

#TODO 
##### using `ifdef` to insert debug code

#TODO 
##### using logging, `std::clog`

#TODO 

### DEBUG USING DEBUGGER

<mark class="hltr-green">USING VS CODE</mark>
 **step into** command executes the next statement in the normal execution path of the program, and then pauses execution of the program so we can examine the program’s state using the debugger. This debugger tool shows an pointer arrow that marks the next execution step  ^72040d

The **step over** command executes the next statement in the normal execution path of the program. However, whereas _step into_ will enter function calls and execute them line by line, _step over_ will execute an entire function without stopping and return control to you after the function has been executed.

![[Pasted image 20260729000716.png]]

<mark class="hltr-cyan">VS CODE RMB menu commands</mark>
**Set next statement** - command allows us to change the point of execution to some other statement (sometimes informally called _jumping_). This can be used to jump the point of execution forwards and skip some code that would otherwise execute, or backwards and have something that already executed run again.
##### The watch window

allows to add variables that will be continuously inspected by a debugger, adding a variable to watch window is done through RMB click menu on a variable in source code file.

![[Pasted image 20260729002838.png]]

<mark class="hltr-pink">source of reference for vscode debugging</mark>  https://code.visualstudio.com/docs/debugtest/debugging

### THE CALL STACK

^4894b0

When a program calls a function, it bookmarks the current location, makes the function call, and then returns. The program uses **call stack** to keep track of called functions in memory.

The **call stack** is a list of all the active functions that have been called to get to the current point of execution. The call stack includes an entry for each function called, as well as which line of code will be returned to when the function returns. Whenever a new function is called, that function is added to the top of the call stack. When the current function returns to the caller, it is removed from the top of the call stack, and control returns to the function just below it.

 <mark class="hltr-yellow">!</mark> ==stack is a data structure==

![[call stack | 500x500]]

### Not making errors while coding

- Follow best practices.
- Don’t program when tired or frustrated. Take a break and come back later.
- Understand where the common pitfalls are in a language (all those things we warn you not to do).
- Don’t let your functions get too long.
- Prefer using the standard library to writing your own code, when possible.
- Comment your code liberally.
- Start with simple solutions, then layer in complexity incrementally.
- Avoid clever/non-obvious solutions.
- Optimize for readability and maintainability, not performance.

#TODO занотувати це https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/

# **CHAPTER 4** Data types

### Introduction to fundamental data types
Computers use **RAM** to store data temporarily, a unit of data for a modern computer is **binary digit** (also called a **bit**) which can hold a value 1 or 0, hense the name binary. 

Memory is organized into sequential units called **memory addresses**. Each memory adress holds a **byte**, A **byte** is a group of bits that are operated on as one unit. <mark class="hltr-yellow">!</mark> ==The modern standard is that a byte is comprised of 8 sequential bits.==

![[8 bit adresses | 700x200]]
##### Fundamental data types
Because all data on a computer is just a sequence of bits, we use a **data type** (often called a **type** for short) to tell the compiler how to interpret the contents of memory in some meaningful way. You have already seen one example of a data type: the integer. When we declare a variable as an integer, we are telling the compiler “the piece of memory that this variable uses is going to be interpreted as an integer value”.

When you give an object a value, the compiler and CPU take care of encoding your value into the appropriate sequence of bits for that data type, which are then stored in memory (remember: memory can only store bits). For example, if you assign an integer object the value `65`, that value is converted to the sequence of bits `0100 0001` and stored in the memory assigned to the object.

**Fundamental data** types or **basic types** table  ^63210c

|                                                                                    |                      |                                                  |         |
| ---------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------ | ------- |
| float  <br>double  <br>long double                                                 | Floating Point       | a number with a fractional part                  | 3.14159 |
| bool                                                                               | Integral (Boolean)   | true or false                                    | true    |
| char  <br>wchar_t  <br>char8_t (C++20)  <br>char16_t (C++11)  <br>char32_t (C++11) | Integral (Character) | a single character of text                       | ‘c’     |
| short int  <br>int  <br>long int  <br>long long int (C++11)                        | Integral (Integer)   | positive and negative whole numbers, including 0 | 64      |
| std::nullptr_t (C++11)                                                             | Null Pointer         | a null pointer                                   | nullptr |
| void                                                                               | Void                 | no type                                          | n/a     |

##### Integer vs integral types
in math an integer is a number with no fractional part,  NOT `4.5`, `0.0032`. The term “integral” has several different meanings, but in the context of C++ is used to mean “like an integer”. ^cd24be

- The **standard integer types** are `short`, `int`, `long`, `long long` (including their signed and unsigned variants).
- The **integral types** are `bool`, the various char types, and the standard integer types.

 <mark class="hltr-yellow">!</mark> ==non-fundamental types (such as enum and enum class) are not integral types  ==
##### Other sets of types
*Built in types are:* fundamental types and compound data types #link_later
*external types are:* standart library types

 **strings:** in modern C++, strings are part of the standard library. they will 

##### The `_t` suffix
Many of the types defined in newer versions of C++ use `_t` suffix, it is a shorthand for type, this is not really consistent huh

### Void type
void means no type, void is an **incomplete type**. Incomplete types cannot be instantiated for use in variables (that would be pointless), void types are used in other use cases.

##### Void functions

```cpp
void functionA()
{
	// no return statement.
	// using return statement in void function will result in compiler error.
}
```

<mark class="hltr-grey">deprecated:</mark>  the original language C has syntax to indicate that a function does not take any parameters
```cpp
void func1(void) // this will compile in c++ too (for backward compatibility reasons)
{
	// 
}

void func2() // this is preffered in c++
{
	// 
}
```

<mark class="hltr-orange">!</mark> ==Other uses of void== -  The void keyword has a third (more advanced) use in C++ - void pointers. source - [19.5 -- Void pointers](https://www.learncpp.com/cpp-tutorial/void-pointers/).

### Object sizes and the sizeof operator
most objects in c++ use more than one byte of memory. **The amount of memory object uses depends on its data type**. memory acess in c++ is often done using variable names (and not directly via memory addresses) When a variable is used in source code (.cpp, .h files) the compiler automatically handles how many bytes should be used for that object based on a type of that object.

<mark class="hltr-grey">The more memory an object has, the more data it can hold</mark>
![[bits exponential growth | 900x200]]

8 bits (one byte) can hold $2^8$ = 256 different values. 
An object that uses 2 bytes can hold 2^16 (65536) different values.
So, **objects that utilize more bytes can store a larger number of unique values.**

computers have a finite amount of free memory. Every time we define an object, a small portion of that free memory is used for as long as the object is in existence. Because modern computers have a lot of memory, this impact is usually negligible. However, for programs that need a large amount of objects or data (e.g. a game that is rendering millions of polygons), the difference between using 1 byte and 8 byte objects can be significant.

##### Fundamental data type sizes and assumptions

^ce9f81

<mark class="hltr-cyan">C++ standart:</mark>
- An object must occupy at least 1 byte (so that each object has a distinct memory address).
- A byte must be at least 8 bits.
- The integral types `char`, `short`, `int`, `long`, and `long long` have a minimum size of 8, 16, 16, 32, and 64 bits respectively.
- `char` and `char8_t` are exactly 1 byte (at least 8 bits).

<mark class="hltr-cyan">Some assumptions have to be made, because computer architectures can differ, most modern computers assume...</mark>
- A byte is 8 bits.
- Memory is **byte addressable** (we can access every byte of memory independently).
- Floating point support is [IEEE-754](https://en.wikipedia.org/wiki/IEEE_754)  compliant.
- We are on a 32-bit or 64-bit architecture.

|Category|Type|Minimum Size|Typical Size|
|---|---|---|---|
|Boolean|bool|1 byte|1 byte|
|Character|char|1 byte (exactly)|1 byte|
||wchar_t|1 byte|2 or 4 bytes|
||char8_t|1 byte|1 byte|
||char16_t|2 bytes|2 bytes|
||char32_t|4 bytes|4 bytes|
|Integral|short|2 bytes|2 bytes|
||int|2 bytes|4 bytes|
||long|4 bytes|4 or 8 bytes|
||long long|8 bytes|8 bytes|
|Floating point|float|4 bytes|4 bytes|
||double|8 bytes|8 bytes|
||long double|8 bytes|8, 12, or 16 bytes|
|Pointer|std::nullptr_t|4 bytes|4 or 8 bytes|

For maximum portability,  objects shouldnt be assumed to be larger than the specified minimum size.

`static_assert` can be used for compiler to fail a build if it is compiled on an architecture where this assumption is not true. Source -  [9.6 -- Assert and static_assert](https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/#static_assert).

##### **Fundamental data type performance**
On modern machines, objects of the fundamental data types are fast, so performance while using or copying these types should generally not be a concern.

CPUs are often optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.

##### The `sizeof()` operator
In order to determine the size of data types on a particular machine, C++ provides an operator named `sizeof`. The **sizeof operator** is a unary (one variable being operated on) operator that takes either a type or a variable, and returns the size of an object of that type (in bytes).

```cpp
#include <iostream>

using namespace std // for code visual comfort

int main()
{
    cout << "using sizeof operator to get size of int - " << sizeof(int) << '\n';
    cout << "using sizeof operator to get size of char - " << sizeof(char) << '\n';
    cout << "using sizeof operator to get size of long - " << sizeof(long) << '\n';
    cout << "using sizeof operator to get size of float - " << sizeof(float) << '\n';
	 return 0;
}
```

<mark class="hltr-grey">outputs:</mark> 
```
using sizeof operator to get size of int - 4
using sizeof operator to get size of char - 1
using sizeof operator to get size of long - 4
using sizeof operator to get size of float - 4
```

**sizeof also can be used on variable names!**

```cpp
int main()
{
    char A[10]; // defining an array
    std::cout << "created array named A \n";
    std::cout << "using sizeof to get size: " << sizeof(A) <<'\n'; //using sizeof on variable.

	 // second example
    char B[10000];
    std::cout << "created array named A \n";
    std::cout << "using sizeof to get size: " << sizeof(B) <<'\n';

	 return 0;
}
```

<mark class="hltr-grey">outputs:</mark>
```
created array named A 
using sizeof to get size: 10
created array named A 
using sizeof to get size: 10000
```

### Signed integers
