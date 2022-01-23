// PE 4 - C Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    //make an int for number of i's in the string
    int numi = 0;

    //make the first string
    char first[34] = "supercalifraglistic";

    //print out the size fo the first string
    printf("The length of the string, %s, is: %zu\n", first, strlen(first));

    //create the second string
    char second[15] = "expialidocious";

    //add the secodn string to the first
    strcat_s(first, second);
    printf("The new string is: %s\n", first);

    //loop to find how many i's are in the string
    for (int i = 0; i < strlen(first); i++)
    {
        char letter[2];
        letter[1] = first[i];
        //show we found an i while looping through and add it to the total
        if (strchr(letter, 'i'))
        {
            numi++;
            printf("found an i at position %d \n", i);
        }
    }

    //print out final results
    printf("There are %d amount of i's in the string %s\n", numi, first);
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
