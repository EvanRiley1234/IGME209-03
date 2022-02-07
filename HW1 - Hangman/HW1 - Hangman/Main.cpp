#include <iostream>
#include <string>
#include "hangman.h"

int main()
{
    //strings and other variables
    char word[10] = "tropical";
    char correctGuesses[10] = "";
    char incorrectGuesses[11] = "";
    char guess[4] = "";

    bool gameEnd = false;
    bool isCorrect;

    printf("Welcome to Hangman\n");
    printf("Your word has 8 letters in it\n");
    showGallows(strlen(incorrectGuesses));
    showSolved(word, correctGuesses);

    

    while(!gameEnd)
    {
        isCorrect = false;

        printf("Guess a letter: ");
        std::cin >> guess;
        printf("Your Guess: %s\n", guess);

        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == *guess)
            {
                isCorrect = true;
            }
        }
        
        //what to do if guess is right
        if (isCorrect)
        {
            showGallows(strlen(incorrectGuesses));
            for (int i = 0; i < strlen(word); i++)
            {
                if(word[i] == *guess)
                {
                    correctGuesses[i] = *guess;
                }
            }
            showSolved(word, correctGuesses);
            printf("Your incorrect guesses: %s\n", incorrectGuesses);

            if (strlen(correctGuesses) == 8)
            {
                gameEnd = true;
            }
        }
        //what to do if guess is wrong
        else
        {
            strcat_s(incorrectGuesses, guess);
            showGallows(strlen(incorrectGuesses));
            showSolved(word, correctGuesses);
            printf("Your incorrect guesses: %s\n", incorrectGuesses);
            if (strlen(incorrectGuesses) == 6)
            {
                gameEnd = true;
            }
        }
    }

    //when the game is over
    if (strlen(incorrectGuesses) == 6)
    {
        printf("You lost");
    }
    else
    {
        printf("You won");
    }
}
