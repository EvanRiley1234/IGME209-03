#pragma once
#include <iostream>
#include <stdlib.h>

void AverageScore(float* scores, int count)
{
	float total = 0;
	float average = 0;
	for (int i = 0; i < count; i++)
	{
		total += scores[i];
	}
	average = total / count;
	std::cout << "The average is: " << average << "\n";
}

void HighScore(float* scores, int count)
{
	float highScore = scores[0];
	for (int i = 0; i < count; i++)
	{
		if(highScore < scores[i])
		{
			highScore = scores[i];
		}
	}
	std::cout << "The highest score is" << highScore << "\n";
}

void LowScore(float* scores, int count)
{
	float lowScore = scores[0];
	for (int i = 0; i < count; i++)
	{
		if (lowScore > scores[i])
		{
			lowScore = scores[i];
		}
	}
	std::cout << "the lowest score is" << lowScore << "\n";
}