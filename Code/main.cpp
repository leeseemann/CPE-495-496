/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.cpp - primary source file of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created
Lee				12/28/15		added instance of driver class

--------------------------------------------------------------------------------
*/


/*#include "main.h"

// main() is only necessary when the C++ code is run in isolation, when the C# driver is used main() is bypassed
int main()
{
	project_driver.startup(depth_data);
	cin.get(); // allows the output of the program to be viewed
	return 0;
}*/

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

#include <stdio.h>

#include <stdlib.h>

using namespace cv;

using namespace std;




Mat src; Mat src_gray;

Mat src_gray2;

int thresh = 100; // used to be 100

int max_thresh = 255;

int thresh2 = 200;

int max_thresh2 = 255;

Mat drawing;

RNG rng(12345);

Mat threshold_output;

Mat drawing2;

Mat cdst;

Mat dst;

char* source_window2 = "Source image";

char* corners_window2 = "Corners detected";




/// Function header

void thresh_callback(int, void*);

void thresh_callback2(int, void*);

void cornerHarris_demo(int, void*);

/** @function main */

int main()

{

	/// Load source image and convert it to gray

	src = imread("panel3.jpg");




	/// Convert image to gray and blur it

	cvtColor(src, src_gray, CV_BGR2GRAY);




	blur(src_gray, src_gray, Size(3, 3));

	///*

	/// Create Window

	char* source_window = "Source";

	namedWindow(source_window, CV_WINDOW_AUTOSIZE);

	imshow(source_window, src);




	createTrackbar(" Canny thresh:", "Source", &thresh, max_thresh, thresh_callback);

	//*/

	thresh_callback(0, 0);

	/// Load source image and convert it to gray

	//src = imread("panel3.jpg");




	/// Convert image to gray and blur it

	//cvtColor(src, src_gray, CV_BGR2GRAY);




	//blur(src_gray, src_gray, Size(3, 3));

	///*

	/// Create Window

	char* source_window3 = "Source";

	namedWindow(source_window3, CV_WINDOW_AUTOSIZE);

	imshow(source_window3, src);




	createTrackbar(" Threshold ", "Source", &thresh, max_thresh, thresh_callback2);

	thresh_callback2(0, 0);



	namedWindow(source_window2, CV_WINDOW_AUTOSIZE);

	imshow(source_window2, src);




	createTrackbar("Threshold: ", source_window2, &thresh, max_thresh, cornerHarris_demo);

	cornerHarris_demo(0, 0);



	waitKey(0);

	return(0);

}




/** @function thresh_callback */

void thresh_callback(int, void*)

{



	Mat canny_output;

	vector<vector<Point> > contours;

	vector<Vec4i> hierarchy;




	/// Detect edges using canny

	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);

	// was src_gray

	Canny(threshold_output, canny_output, thresh, thresh * 2, 3);

	/// Find contours

	// added here *****

	//threshold(canny_output, threshold_output, thresh, 255, THRESH_OTSU);

	// ***** changed from canny_output to threshold_output

	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));




	/// Draw contours

	// **edit drawing

	drawing = Mat::zeros(canny_output.size(), CV_8UC3); // ** originally CV_8UC3

	for (int i = 0; i< contours.size(); i++)

	{

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());

	}




	/// Show in a window

	namedWindow("Contours", CV_WINDOW_AUTOSIZE);

	imshow("Contours", drawing);

}




void cornerHarris_demo(int, void*)

{



	Mat dst, dst_norm, dst_norm_scaled;

	// edited **

	//cvtColor(drawing, src_gray2, CV_BGR2GRAY);

	cvtColor(drawing2, src_gray2, CV_BGR2GRAY);

	//cv::transform(src_gray2, src_gray2, cv::Matx12f(1, 1));

	//blur(src_gray2, src_gray2, Size(1, 1));




	dst = Mat::zeros(drawing.size(), CV_32FC1);

	// added piece

	// done adding

	/// Detector parameters

	int blockSize = 3;

	int apertureSize = 3;

	double k = 0.07;




	/// Detecting corners

	//**editing *** cornerHarris(src_gray, dst, blockSize, apertureSize, k, BORDER_DEFAULT);

	cornerHarris(src_gray2, dst, blockSize, apertureSize, k, BORDER_DEFAULT);

	/// Normalizing

	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());

	convertScaleAbs(dst_norm, dst_norm_scaled);




	/// Drawing a circle around corners

	for (int j = 0; j < dst_norm.rows; j++)

	{

		for (int i = 0; i < dst_norm.cols; i++)

		{

			if ((int)dst_norm.at<float>(j, i) > thresh)

			{

				circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);

			}

		}

	}

	/// Showing the result

	namedWindow("Corners", CV_WINDOW_AUTOSIZE);

	imshow("Corners", dst_norm_scaled);

}

void thresh_callback2(int, void*)

{

	Mat threshold_output;

	vector<vector<Point> > contours;

	vector<Vec4i> hierarchy;

	//** added snippet

	cvtColor(drawing, src_gray2, CV_BGR2GRAY);




	blur(src_gray2, src_gray2, Size(3, 3));

	//** 

	/// Detect edges using Threshold

	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY&&THRESH_OTSU);// had to change to OTSU thresholding

																				   /// Find contours

	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));




	/// Approximate contours to polygons + get bounding rects and circles

	vector<vector<Point> > contours_poly(contours.size());

	vector<Rect> boundRect(contours.size());

	vector<Point2f>center(contours.size());

	vector<float>radius(contours.size());

	double perimeter;

	for (int i = 0; i < contours.size(); i++)

	{

		perimeter = arcLength((Mat)(contours[i]), true);

		if (perimeter > 9000)

		{

			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);

			boundRect[i] = boundingRect(Mat(contours_poly[i]));

			minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]);

		}

	}







	/// Draw polygonal contour + bonding rects + circles

	drawing2 = Mat::zeros(threshold_output.size(), CV_8UC3);

	for (int i = 0; i< contours.size(); i++)

	{

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

		drawContours(drawing2, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());

		//rectangle(drawing2, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);

		//circle(drawing2, center[i], (int)radius[i], color, 2, 8, 0);

	}

	// start hough transform

	Canny(drawing2, dst, 50, 200, 3);

	cvtColor(dst, cdst, CV_GRAY2BGR);

#if 0

	vector<Vec2f> lines;

	HoughLines(dst, lines, 10, CV_PI / 360, 500, 100, 10);

	for (size_t i = 0; i < lines.size(); i++)

	{

		float rho = lines[i][0], theta = lines[i][1];

		Point pt1, pt2;

		double a = cos(theta), b = sin(theta);

		double x0 = a*rho, y0 = b*rho;

		pt1.x = cvRound(x0 + 1000 * (-b));

		pt1.y = cvRound(y0 + 1000 * (a));

		pt2.x = cvRound(x0 - 1000 * (-b));

		pt2.y = cvRound(y0 - 1000 * (a));

		//cout << abs(pt1 - pt2) << " ";




		//if (pt1.y > 10000000)

		//{

		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);

		//}

	}

#else

	vector<Vec4i> lines;

	HoughLinesP(dst, lines, 1, CV_PI / 360, 50, 135, 10);

	for (size_t i = 0; i < lines.size(); i++)

	{

		Vec4i l = lines[i];

		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);

	}

#endif

	imshow("detected lines", cdst);

	//

	/// Show in a window

	namedWindow("Contours2", CV_WINDOW_AUTOSIZE);

	imshow("Contours2", drawing2);

}
