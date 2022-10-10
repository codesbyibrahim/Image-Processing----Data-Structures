#pragma once
#include"ADDITIONALFUNCTIONS.h"
int newlabel(int* labels)
{
    for (int i = 1; i < 2000; i++)
        if (labels[i] == -1)
        {
            labels[i] = 0;
            return i;
        }
}
//to assign a label at particular index
int AssignLabels(unsigned char** matrix, int** tempMatrix, int I, int J, int r, int c, int* labels)
{
    //if current value is zero then we do nothing
    if (!matrix[I][J])
        return 0;
    // for checking the 4 neigbouring cells or pixels
    int arr[2][4] = { { 0,-1,-1,-1 }, {-1,-1,0,1} };
    //initial count =4 assuming all negihbours are '0'---> if a non zero neighbour is found we decrement the counter
    int count = 4;
    for (int i = 0; i < 4; i++)
        if (matrix[I + arr[0][i]][J + arr[1][i]])
            count--;
    // if all neighbours 0 then create a new label
    if (count == 4)
        return newlabel(labels);
    // for storing the label for the current index (min label)
    int lab = INT16_MAX;
    for (int i = 0; i < 4; i++)
        if (tempMatrix[I + arr[0][i]][J + arr[1][i]])
            lab = lab < tempMatrix[I + arr[0][i]][J + arr[1][i]] ? lab : tempMatrix[I + arr[0][i]][J + arr[1][i]];
    //if the labels are not equal to the label assigned to the current index make note of the equivalances
    for (int i = 0; i < 4; i++)
        if (tempMatrix[I + arr[0][i]][J + arr[1][i]] && tempMatrix[I + arr[0][i]][J + arr[1][i]] != lab)
            labels[tempMatrix[I + arr[0][i]][J + arr[1][i]]] = lab;
    return lab;
}
//finding the label with most occurence
int findMaxOccurence(int* matrixOccurence)
{
    int max = 0;
    for (int i = 0; i < 2000; i++)
        if (matrixOccurence[i] > matrixOccurence[max])
            max = i;
    return max;
}
//for the first of two scans 
void FirstScan(unsigned char** matrix, int** tempMatrix, int r, int c, int* labels)
{
    for (int i = 1; i < r - 1; i++)
        for (int j = 1; j < c - 1; j++)
            tempMatrix[i][j] = AssignLabels(matrix, tempMatrix, i, j, r, c, labels);
}
//Recursive call
int checkEquivalances(int* label, int index)
{
    if (label[index] == 0)
        return index;
    return checkEquivalances(label, label[index]);
}
//second scan
void SecondScan(int** tempMatrix, int r, int c, int* labels)
{
    for (int i = 1; i < r - 1; i++)
        for (int j = 1; j < c - 1; j++)
            if (labels[tempMatrix[i][j]] && tempMatrix[i][j]!=0)
                tempMatrix[i][j] = checkEquivalances(labels, tempMatrix[i][j]);
}
// max leasion
int** MaxLesion(int** Image, int r, int c, int max)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (Image[i][j] == max)
                Image[i][j] = 255;
            else
                Image[i][j] = 0;
        }
    }
    return Image;
}
void CalculateOccurences(int** tempMatrix, int* temp, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (tempMatrix[i][j])
                temp[tempMatrix[i][j]]++;
}
int** Task1(int& r, int& c, string filename)
{
    int* Occurences = initializePointer<int>(2000);
    int* EquivalanceMatrix = initializePointer<int>(2000, -1);
    unsigned char** matrix = ReadMatrix(r, c, 1, filename);
    int** OccurencesMatrix = AllocateSpace<int>(r, c);
    FirstScan(matrix, OccurencesMatrix, r, c, EquivalanceMatrix);
    SecondScan(OccurencesMatrix, r, c, EquivalanceMatrix);
    CalculateOccurences(OccurencesMatrix, Occurences, r, c);
    int maxOccured = findMaxOccurence(Occurences);
    return MaxLesion(OccurencesMatrix, r, c, maxOccured);
}