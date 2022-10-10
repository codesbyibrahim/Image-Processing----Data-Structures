#pragma once
#include"k-means Clustering.h"
double DiceCoeffiecient(int** task1, unsigned char** matrix, int  r, int c)
{
	int truePositive = 0, falseNegative = 0, falsePositive = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (task1[i][j] && matrix[i][j])
				truePositive++;
			else if (task1[i][j] != matrix[i][j])
			{
				if (task1[i][j])
					falseNegative++;
				else
					falsePositive++;
			}
		}
	double DC = double(2 * truePositive) / double(falseNegative + 2 * truePositive + falsePositive);
	return DC;
}
void task3(string filename)
{
	int r, c;
	int** task1 = Task1(r, c, filename);
	int** task2 = Task2(r, c, filename);
	unsigned char** matrix = ReadMatrix(r, c, 3,filename);
	cout << setw(30) << left << filename << setw(20) << DiceCoeffiecient(task1, matrix, r, c) << setw(20) << DiceCoeffiecient(task2, matrix, r, c) << "\n\n";
}