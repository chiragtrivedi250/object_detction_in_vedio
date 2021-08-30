// AverageImageIntensity.cpp : 
//This file contains the 'main' function. Program execution begins and ends there.
//

/*
This is the one of the approach to calculate Average Intensity.
my intution is this is with O(N^2) Complexity and we can use
histogram to identify median or mean or kind of MinMax Difference
*/

#include "pch.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<string>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat originalImg;
	Mat GrayScaledImg;

	cout << "Please enter an image filename : ";
	string img_addr;
	cin >> img_addr;

	std::cout << "Searching for " + img_addr << std::endl;

	originalImg = imread(img_addr);            // open image

	if (originalImg.empty()) {
		cout << "error: image not read from file\n\n";        
		return(0);                                          
	}

	cvtColor(originalImg, GrayScaledImg, cv::COLOR_BGR2GRAY); // Grayscale conversion

	const int numOfChannels = GrayScaledImg.channels();
	cout << "Number of channels = " << numOfChannels << endl;

	//initializing average intensity
	float avgIntensity = 0.0;
	int count = 0;

	if (numOfChannels == 1)
	{
		for (int x = 0; x < GrayScaledImg.rows; x++) {
			for (int y = 0; y < GrayScaledImg.cols; y++) {
				// Accesssing values of each pixel
				++count;
				avgIntensity += GrayScaledImg.at<uchar>(x, y);
				avgIntensity /= count;
			}
		}
	}

	cout << "Average inntensity of input image is " << avgIntensity << endl;

}
/*
This is the one of the approach to calculate Average Intensity.
my intution is this is with O(N^2) Complexity and we can use 
histogram to identify median or mean or kind of MinMax Difference
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
