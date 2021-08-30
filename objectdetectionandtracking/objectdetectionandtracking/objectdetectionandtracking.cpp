// objectdetectionandtracking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

// CPP program to detects face in a video 

// Include required header files from OpenCV directory 
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream> 

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
	// i have selected here MEDIANFLOW TRACKER for getting maximum FPS.
	string trackerType = "MEDIANFLOW";

	Ptr<Tracker> tracker;

	tracker = TrackerMedianFlow::create();

	VideoCapture capture;

	capture.open(0);

	if (capture.isOpened())
	{
		cout << "face detection and tracking started" << endl;
		Mat firstframe;
		bool ok = capture.read(firstframe);

		Rect2d bbox(287, 23, 86, 320);

		rectangle(firstframe, bbox, Scalar(255, 0, 0), 3, 2);

		imshow("Tracking", firstframe);

		tracker->init(firstframe, bbox);

		while (capture.read(firstframe))
		{
			// Starting timer
			double timer = (double)getTickCount();

			// Update the tracking result
			bool fine = tracker->update(firstframe, bbox);

			// Calculate FPS
			float fps = getTickFrequency() / ((double)getTickCount() - timer);

			if (fine)
			{
				// Tracking success : Drawing the tracked object
				rectangle(firstframe, bbox, Scalar(0, 255, 0), 2, 1);

			}
			else
			{
				// Tracking failure detected.
				putText(firstframe, "missing target or tracker failed", Point(100, 80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
			}
			// Display tracker type on frame
				putText(firstframe, trackerType + " Tracker", Point(100, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);

			// Display FPS on frame
				putText(firstframe, "FPS : " + (std::ostringstream() << std::dec << int(fps)).str(), Point(100, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);

			// Display frame.
				imshow("Tracking", firstframe);

			// Exit if ESC pressed.
			int k = waitKey(1);
			if (k == 27)
			{
				break;
			}
		}

	}
	else
	{
		cout << "Could not open camera" << endl;
		return 1;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
