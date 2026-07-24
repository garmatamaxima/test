 
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
##### [[#^33cf99|Naming collisions]]
##### [[#^235c54|Scope resolution operator ::]]
##### [[#^49acb7|Translation unit]]
##### [[#^a80905|Including paired header files to source files]]
##### [[#^861673 | Include directories / where std comes from]]

# **MAKING BUGS AND REGRETTING IT**

##### [[#^83565d|Redefinition of a function]]

# **CHAPTER 1 LEARNCPP.COM **

# **CHAPTER 2 LEARNCPP.COM**

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
<mark style="background: #ABF7F7A6;">2.</mark> variables can be defined in global scope, but this is bad practice

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

Preprocessor is a part of most compiler languages, each code file goes through the preprocessor first, then compiler.  The stage where preprocessor works is called **Preprocessing phase**, when preprocessor runs it scans through code file searching for **preprocessor directives**. <mark class="hltr-yellow">!</mark> preprocessor does not use C++ syntax  

The final output of the preprocessor contains no directives -- only the output of the processed directive is passed to the compiler. The final output of preprocessor is called **translation unit**
Preprocessor also removes comments and ends each translation unit in a newline character ^49acb7

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

<mark class="hltr-orange">An important reminder</mark> - preprocessor directly inserts contents of an included files, replacing the `#include` directive. That

##### `#define`
The `#define` directive can be used to create a macro. In C++, a **macro** is a rule that defines how input text is converted into replacement output text.
There are two basic types of macros: _object-like macros_, and _function-like macros_.

```cpp

#define MACRO "name" // will replace each MACRO by "name"

```
##### `#if`
 #TODO на learn.cpp є матеріал глава 2.10
##### `#endif`
#TODO на learn.cpp є матеріал глава 2.10


### HEADER FILES

Header files have .h extension, but in some cases they can have .hpp or no file extension at all
<mark class="hltr-yellow">!</mark> header files are used to add a bunch of related forward declarations into a code file 

what problem do they solve? - manually adding [[#^b6dea4| function prototypes]] into every source code file is tedious, so it was automated using preprocessor and header files. <mark class="hltr-purple">!</mark> They mainly allow to link libraries together.

```cpp
#include <iostream> //including std header file, no need to add .h extension

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