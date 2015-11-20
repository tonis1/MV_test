#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	
	Mat image, gray, edge, draw;
	int CannyThreshL = 70;
	int CannyThreshH = 255;

	image = imread("D:/Google Drive/MachineVision/1918.jpg", IMREAD_GRAYSCALE); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image " << std::endl;
		return -1;
	}

	Canny(image, edge, CannyThreshL, CannyThreshH, 3);

	edge.convertTo(draw, CV_8U);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	imshow("Display window2", draw); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}