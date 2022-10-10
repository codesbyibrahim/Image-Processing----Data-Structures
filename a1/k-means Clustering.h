#pragma once
#include"Connected Component Labeling.h"
int minDist(int val, int c1,int c2)
{
	if (abs(val - c1) > abs(val - c2))
		return 1;
	return 0;
}
void LabelArray(unsigned char** matrix, int** clustering, int r, int c,int c1,int c2)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			clustering[i][j] = minDist(matrix[i][j], c1, c2);
}
void UpdateCentroids(unsigned char** matrix, int** clustering,int r,int c, int& c1, int& c2)
{
	long c1sum = 0, c2sum = 0;
	int c1Counter = 0, c2Counter = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (clustering[i][j])
			{
				c2sum += matrix[i][j];
				c2Counter++;
				continue;
			}
			c1sum += matrix[i][j];
			c1Counter++;
		}
	if (c1Counter == 0 || c2Counter==0){
		c1 = rand() % 128 + 128;
		c2 = rand() % 128 ;
		return;
	}
	c1 = c1sum / c1Counter;
	c2 = c2sum / c2Counter;
}
void KMeansCluterring(unsigned char ** matrix,int **clustering,int r,int c)
{
	int c1 = rand() % 128 + 128, c2 = rand() % 128;
	int c1new = c1, c2new = c2;
	do {
		c1 = c1new;
		c2 = c2new;
		LabelArray(matrix, clustering, r, c, c1, c2);
		UpdateCentroids(matrix, clustering, r, c, c1new, c2new);
	} while (c1 != c1new || c2 != c2new);
}
int** Task2(int &r,int& c,string filename)
{	
	srand(time(0)); 
	unsigned char** matrix = ReadMatrix(r, c, 2, filename);
	int** cluster = AllocateSpace<int>(r, c);
	KMeansCluterring(matrix, cluster, r, c);
	return cluster;
}