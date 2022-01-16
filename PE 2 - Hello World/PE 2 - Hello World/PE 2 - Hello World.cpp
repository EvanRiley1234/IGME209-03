// PE1-Hello World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

int main()
{
    //hello world printf
    printf("Hello World!\n");
    //calculations
    int month = 1;
    int days;
    int hours;
    int minutes;
    int seconds;
    double area;
    double radius = 6.2;
    int divide1;
    int divide2;
    int divide3;
    days = month * 31;
    hours = days * 24;
    minutes = hours * 60;
    seconds = minutes * 60;
    area = 2 * radius * 3.14;
    divide1 = 3 / 2;
    divide2 = 5 / 2;
    divide3 = 5 / 3;

    //printf statements
    printf("There are %d seconds in the month of December\n", seconds);
    printf("The area of a circle with radius 6.2 is %lf\n", area);
    //division
    printf("%d\n", divide1);
    printf("%d\n", divide2);
    printf("%d\n", divide3);
    //dividing integers results in rounding
    //aditionally it rounds down


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
