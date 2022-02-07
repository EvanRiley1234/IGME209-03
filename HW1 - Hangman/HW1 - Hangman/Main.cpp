#include <iostream>
#include <string>
#include "hangman.h"

int main()
{
    //strings and other variables
    char word[10] = "Tropical";
    char correctGuesses[11] = "";
    char incorrectGuesses[11] = "";
    char guess[4] = "";

    bool gameEnd = false;

    printf("Welcome to Hangman\n");
    printf("Your word has 8 letters in it\n");
    showGallows(strlen(incorrectGuesses));
    showSolved(word, correctGuesses);

    

    while(!gameEnd)
    {
        printf("Guess a letter: ");
        scanf_s("%c", &guess);
        printf("Your Guess: %s\n", guess);
        
        //what to do if guess is right
        if (strchr(word, guess[1]))
        {
            strcat_s(correctGuesses, guess);
            showGallows(strlen(incorrectGuesses));
            showSolved(word, correctGuesses);
            if (strlen(correctGuesses) == 6)
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
