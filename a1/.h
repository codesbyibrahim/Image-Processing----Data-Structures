#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
template <typename T>
T* initializePointer(int size, int val = 0)
{
    T* ptr = new T[size]{};
    if (val == 0)
        return ptr;
    for (int i = 0; i < size; i++)
        ptr[i] = val;
    return ptr;
}
// to convert the obtained matrix into a 2D array
unsigned char** convertToARR(Mat image)
{
    unsigned char** ptrDst = new  unsigned char* [image.rows];
    for (int i = 0; i < image.rows; ++i) {
        ptrDst[i] = new  unsigned char[image.cols];
        for (int j = 0; j < image.cols; ++j)
            ptrDst[i][j] = image.at<unsigned char>(i, j);
    }
    return ptrDst;
}
//the function to read the image into a matrix and update the rows and columns
unsigned char** ReadMatrix(int& r, int& c,int temp)
{
    string filename;
    cout << "Enter the name of the file : ";
    cin>>filename;
    if(temp==1 || temp==4)
        filename = "C:\\Users\\ibrahim\\OneDrive\\Desktop\\submission\\DS\\Segmented Outputs\\mIMD" + filename + ".bmp";
    else if(temp==3)
        filename = "C:\\Users\\ibrahim\\OneDrive\\Desktop\\submission\\DS\\Ground Truths\\IMD" + filename + "_lesion.bmp";
    else if(temp==2)
        filename = "C:\\Users\\ibrahim\\OneDrive\\Desktop\\submission\\DS\\Original Images\\IMD" + filename + ".bmp";
    Mat image = imread(filename, IMREAD_GRAYSCALE);
    r = image.rows;
    c = image.cols;
    return convertToARR(image);
}
// to allocate the required number of rows and columns for a 2D array
template<typename T>
T** AllocateSpace(int r, int c)
{
    T** ptr = new T * [r];
    for (int i = 0; i < r; i++)
        ptr[i] = new T[c]{};
    return ptr;
}
template<typename T>
T* AllocateSpace(int r)
{
    return new T[r];
}