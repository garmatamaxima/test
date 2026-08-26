
#include "main.h"
#include "constants.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <cmath>
#include <algorithm>

namespace stuff
{ 

int clamp(int value, int min, int max)
{
    if (value > max) { return max; }
    else if (value < min) { return min; }
    return value;
}
float clamp(float value, float min, float max)
{
    if (value > max) { return max; }
    else if (value < min) { return min; }
    return value;
}
double clamp(double value, double min, double max)
{
    if (value > max) { return max; }
    else if (value < min) { return min; }
    return value;
}

int clampmin(int value, int min)
{
    if (value < min) { return min; }
    return value;
}

int truncateLeftDigits(int number, int left_digits)
{
    return (number / std::pow(10, left_digits)) * std::pow(10, left_digits);
}


int accumulate(int x)
{
	static int accumulator{ 0 };
	accumulator += x;
	return accumulator;
}

std::string numberToText(int number)
{
    std::string stringBuffer{ };
    int scale{2};
    
    if (truncateLeftDigits(number, 2) <= 19)
    {
        stringBuffer.append(sizes::ones[clamp(number, 1, 19)]);
        stringBuffer.append(" ");
    }
    else 
    {
        stringBuffer = stringBuffer.append(sizes::tens[clamp(number / 10 - 1, 1, 9)]) + " ";
        stringBuffer.append( sizes::ones[clamp(number - truncateLeftDigits(number,1),0,9)] ); // wont work due to issue with truncate funtion?
        stringBuffer.append(" ");
    } 
    // implement adding number to text conversions after tens, easy because it will mostly be amount + scale_word.
    // probably deprecated and i will work on something else.
    return stringBuffer;
}

void switcher(int x)
{
    switch (x)
    {
    case 1:
        std::cout << "case1";
        break;
        
    case 2:
        std::cout << "case2";
        break;
        
    case 3:
        std::cout << "case3";
        break;
        
    default:
        std::cout << "not 1,2,3";
        break;
    }
}

void stairPrinter(int lenghtx, int lenghty)
{
    using std::cout;

    for (short i1{ 0 }; i1 < lenghty; ++i1)
    {
        for (short i2{ 0 }; i2 < lenghtx; ++i2)
        {
            cout << i2 + 1 << ' ';
        }
        lenghtx -= 1;
        cout << '\n';
    }
}

void fill_end_printer(int lenx, int leny, int fillx)
{
    short emptyfill{};
    short fullfill{};

    for (short i1{ 0 }; i1 < leny; ++i1)                         // y coordinate loop
    {
        emptyfill = clampmin(lenx - fillx, 0);
        fullfill = lenx - emptyfill;
        for (short emptyi{ 0 }; emptyi < emptyfill; ++emptyi)   // x coordinate empty fill
        {
            std::cout << "  ";
        }
        for (short fulli{ 0 }; fulli < fullfill; ++fulli)       // x coordinate full full with numbers.
        {
            std::cout << clamp(fulli + 1, 0,9) << ' ';
        }
        std::cout << '\n';
        
        if (fillx < lenx)
        {
            fillx += 1;                                        // add one to fill demand.
        }
              
    }
}

void fill_beginning_printer(int lenx, int leny, int fillx)
{
    short emptyfill{};
    short fullfill{};

    for (short i1{ 0 }; i1 < leny; ++i1)                         // y coordinate loop
    {
        emptyfill = clampmin(lenx - fillx,0);
        fullfill = lenx - emptyfill;
        for (short fulli{ 0 }; fulli < fullfill; ++fulli)       // x coordinate full full with numbers.
        {
            std::cout << clamp(fulli + 1, 0, 9) << ' ';
        }
        for (short emptyi{ 0 }; emptyi < emptyfill; ++emptyi)   // x coordinate empty fill
        {
            std::cout << "  ";
        }

        std::cout << '\n';

        if (fillx < lenx)
        {
            fillx += 1;                                        // add one to fill demand.
        }

    }
}

int sumTo(int sumvar)
{
    int buffer{};
    for (int i1{ 1 }; i1 <= sumvar; ++i1)
    {
        buffer = i1 + buffer;
    }
    return buffer;
}

void fizzbuzz(int range)
{
    for (int i1{ 1 }; i1 <= range; ++i1)
    {
        if (i1 % 3 != 0 && i1 % 5 != 0)
        {
            std::cout << i1;
        }
        else if (i1 % 3 == 0)
        {
            std::cout << i1 << " is fizz";
        }
        
        if (i1 % 5 == 0)
        {
            std::cout << "buzz";
        }

        std::cout << '\n';
    }
}

void fizzbuzzpop(int range)
{
    bool condition_satisfied{ false };
    for (int i1{1}; i1 <= range; ++i1)
    {
        condition_satisfied = false;
        if (i1 % 3 == 0)
        {
            std::cout << "fizz";
            condition_satisfied = true;
        }
        if (i1 % 5 == 0)
        {
            std::cout << "buzz";
            condition_satisfied = true;
        }
        if (i1 % 7 == 0)
        {
            std::cout << "pop!";
            condition_satisfied = true;
        }
        if (!condition_satisfied) { std::cout << i1; }
        std::cout << '\n';
    }   // checking whether fizz or buzz or pop is independent of each other, so if loops dont need to be if-else chained
        // because if else is exclusive. Meaning that if first condition is true, then second doesnt even execute!
}

void fizzbuzzpop_alt(int range)
{
    for (int i1{1}; i1 <= range; ++i1)
    { 
        if (i1 % 3 != 0 && i1 % 5 != 0 && i1 % 7 != 0) 
        { 
            std::cout << i1 << '\n'; 
            continue; // skips evaluating next stuff.
        }
        
        if (i1 % 3 == 0)
        {
            std::cout << "fizz";

        }
        if (i1 % 5 == 0)
        {
            std::cout << "buzz";

        }
        if (i1 % 7 == 0)
        {
            std::cout << "pop!";

        }
        std::cout << '\n';

    }
}


double costosin(double angle)
{
    using namespace std;
    
    return sqrt( 1 - pow(cos(angle),2) );
}

double sintocos(double angle)
{
    using namespace std;

    return sqrt(1 - pow(sin(angle), 2));
}
}

struct vector3
{
    double x;
    double y;
    double z;
};

void v3print(const vector3& a) // slow printer function, can be made better, wont be made better, ugly
{
    std::cout << "| ";
    if (a.x != static_cast<int>(a.x)) { std::cout << std::setprecision(4) << a.x << ' '; }
    else { std::cout << static_cast<int> (a.x) << ".0 "; }
    
    if (a.y != static_cast<int>(a.y)) { std::cout << std::setprecision(4) << a.y << ' '; }
    else { std::cout << static_cast<int> (a.y) << ".0 "; }
    
    if (a.z != static_cast<int>(a.z)) { std::cout << std::setprecision(4) << a.z << ' '; }
    else { std::cout << static_cast<int> (a.z) << ".0 "; }
}

namespace vec
{
    constexpr double dotproduct( const vector3& a, const vector3& b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }
    
    double magnitude(const vector3& a)
    {
        return std::sqrt(std::pow(a.x, 2) + std::pow(a.y, 2) + std::pow(a.z, 2));
    }

    vector3 normalise(const vector3& a)
    {
        double magn{ magnitude(a) };
        return { a.x / magn, a.y / magn, a.z / magn };
    }

}

int main()
{
    using std::cout;
    using std::cin;
    vector3 vecA{ 2.0,0.0,0.0 }; // xyz
    vector3 vecB{ 2.0,2.0,1.0 }; // xyz

    cout << "struct: " << vecA.x << " " << vecA.y << " " << vecA.z << '\n';

    for (int i1{ 0 }; i1 < 100; ++i1)
    {
        
        v3print(vecB);
        vecB.y += 0.1;
        vecB.x += 0.1;

        if ((i1 + 1) % 2 == 0) { cout << '\n'; }
    }


    return 0;
}