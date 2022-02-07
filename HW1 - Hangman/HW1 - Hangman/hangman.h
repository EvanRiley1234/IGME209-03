#include <iostream>
#include <string>

void showGallows(int guessLimit)
{
	switch (guessLimit)
	{
		case 0:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			break;
		case 1:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|    O    \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			printf("|         \n");
			break;
		case 2:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|    O    \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|         \n");
			printf("|         \n");
			break;
		case 3:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|  \\\ O    \n");
			printf("|   \\\|    \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|         \n");
			printf("|         \n");
			break;
		case 4:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|  \\\ O /  \n");
			printf("|   \\\|/   \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|         \n");
			printf("|         \n");
			break;
		case 5:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|  \\\ O /  \n");
			printf("|   \\\|/   \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|   /     \n");
			printf("|  /      \n");
			break;
		case 6:
			printf("----------\n");
			printf("|    X    \n");
			printf("|    |    \n");
			printf("|  \\\ O /  \n");
			printf("|   \\\|/   \n");
			printf("|    |    \n");
			printf("|    |    \n");
			printf("|   / \\\    \n");
			printf("|  /   \\\   \n");
			break;
	}
}

void showSolved(char word[], char guesses[])
{
	char solved[7] = "______";
	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = 0; j < strlen(guesses); j++)
		{
			if (strchr(word, guesses[j]))
			{
				solved[i] = guesses[j];
			}
		}
	}
	printf("%s", solved);
}