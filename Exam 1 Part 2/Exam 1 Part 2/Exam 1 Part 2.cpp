// Exam 1 Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "Header.h"

int main()
{
    //variables for the porgram

    bool hasLetters = true;
    bool hasALetter;
    bool wrongSize = true;
    bool rightSize;
    float scores[11];
    char numOfScores[20] = "";
    char userInput[20] = "";
    

    //get the number of scores the user wants to enter
    while (hasLetters == true || wrongSize == true)
    {
        //get input
        std::cout << "\nHow Many scores would you like to input (between 1 and 10): ";
        std::cin >> numOfScores;

        //reset bools incase it loops around
        rightSize = true;
        hasALetter = false;
        hasLetters = true;
        wrongSize = true;

        //check for either wrong size or letters in input
        for (int i = 0; i < strlen(numOfScores) - 1; i++)
        {
            if (isalpha(numOfScores[i]))
            {
                hasALetter = true;
            }
        }
        for (int i = 0; i < strlen(numOfScores) - 1; i++)
        {
            if (atoi(numOfScores) < 1 || atoi(numOfScores) > 10)
            {
                rightSize = false;
            }
        }

        //set letter bool to false if okay or return a message saying its wrong
        if (!hasALetter)
        {
            hasLetters = false;
        }
        else
        {
            std::cout << "Your Input inclues a letter, please try again \n";
        }

        //set size bool to false or return a message saying its wrong
        if (rightSize)
        {
            wrongSize = false;
        }
        else
        {
            std::cout << "Your Input is either too big or too small, please try again \n";
        }
    }
    
    //loop for getting player scores
    for (int i = 0; i < atoi(numOfScores); i++)
    {
        //reset bools for use in this loop
        hasALetter = false;
        hasLetters = true;

        //get the actual scores from the user
        while (hasLetters == true)
        {
            hasALetter = false;
            hasLetters = true;

            //get input
            std::cout << "\nEnter a score (that isn't negative): ";
            std::cin >> userInput;

            //check for either wrong size or letters in input
            for (int i = 0; i < strlen(userInput) - 1; i++)
            {
                if (isalpha(userInput[i]) || atof(userInput) < 0)
                {
                    hasALetter = true;
                }
            }
            //set letter bool to false if okay or return a message saying its wrong
            if (!hasALetter)
            {
                hasLetters = false;
            }
            else
            {
                std::cout << "Your Input inclues a letter, please try again \n";
            }
        }

        scores[i] = atoi(userInput);
    }

    AverageScore(scores, atoi(numOfScores));
    HighScore(scores, atoi(numOfScores));
    LowScore(scores, atoi(numOfScores));
}