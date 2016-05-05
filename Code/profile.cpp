/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

profile.cpp - source file for the profile verification software

*/

#include "profile.h"
using namespace std;

profile::profile()
{

}

bool profile::initialize()
{
	cout << "Initializing Profile Verification Software" << endl; 
	readDataFromFile(); // reads depth data into array from file, debugging purposes only
	edgeDetection(); // performs the edge detection on the color image provided
	return profile_verified;
}
void profile::thresh_callback(int, void*)

{
	instance.src = imread("panel3.jpg");
	/// Convert image to gray and blur it
	cvtColor(instance.src, instance.src_gray, CV_BGR2GRAY);
	blur(instance.src_gray, instance.src_gray, Size(3, 3));
	instance.rng(instance.num);
	//profile instance;

	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using canny
	threshold(instance.src_gray, instance.threshold_output, instance.thresh, 255, THRESH_BINARY);
	Canny(instance.threshold_output, canny_output, instance.thresh, instance.thresh * 2, 3);

	/// Find contours
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	/// Draw contours
	instance.drawing = Mat::zeros(canny_output.size(), CV_8UC3); // ** originally CV_8UC3

	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(instance.rng.uniform(0, 255), instance.rng.uniform(0, 255), instance.rng.uniform(0, 255));
		drawContours(instance.drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	/// Show in a window
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", instance.drawing);
}

// edgeDetection() performs Canny edge detection of an image containing the Answer component using the HSV color space
void profile::edgeDetection()
{
	/// Load source image and convert it to gray
	src = imread("panel3.jpg");
	/// Convert image to gray and blur it
	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));
	/// Create Window
	char* source_window = "Source";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);
	createTrackbar(" Canny thresh:", "Source", &thresh, max_thresh, instance.thresh_callback);

	thresh_callback(0, 0);

	/// Create Window
	char* source_window3 = "Source";
	namedWindow(source_window3, CV_WINDOW_AUTOSIZE);
	imshow(source_window3, src);

	createTrackbar(" Threshold ", "Source", &thresh, max_thresh, instance.thresh_callback2);

	thresh_callback2(0, 0);

	namedWindow(source_window2, CV_WINDOW_AUTOSIZE);
	imshow(source_window2, src);

	createTrackbar("Threshold: ", source_window2, &thresh, max_thresh, instance.cornerHarris_demo);

	cornerHarris_demo(0, 0);

	waitKey(0);
}

void profile::cornerHarris_demo(int, void*)
{
	Mat dst, dst_norm, dst_norm_scaled;
	cvtColor(instance.drawing2, instance.src_gray2, CV_BGR2GRAY);

	dst = Mat::zeros(instance.drawing.size(), CV_32FC1);

	/// Detector parameters
	int blockSize = 3;
	int apertureSize = 3;
	double k = 0.07;

	/// Detecting corners
	cornerHarris(instance.src_gray2, dst, blockSize, apertureSize, k, BORDER_DEFAULT);

	/// Normalizing
	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());

	convertScaleAbs(dst_norm, dst_norm_scaled);

	/// Drawing a circle around corners
	for (int j = 0; j < dst_norm.rows; j++)
	{
		for (int i = 0; i < dst_norm.cols; i++)
		{
			if ((int)dst_norm.at<float>(j, i) > instance.thresh)
			{
				circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
			}
		}
	}

	/// Showing the result
	namedWindow("Corners", CV_WINDOW_AUTOSIZE);
	imshow("Corners", dst_norm_scaled);
}

void profile::thresh_callback2(int, void*)
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	//** added snippet
	cvtColor(instance.drawing, instance.src_gray2, CV_BGR2GRAY);

	blur(instance.src_gray2, instance.src_gray2, Size(3, 3));

	/// Detect edges using Threshold
	threshold(instance.src_gray, threshold_output, instance.thresh, 255, THRESH_BINARY&&THRESH_OTSU);// had to change to OTSU thresholding

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
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3.1, true);
			boundRect[i] = boundingRect(Mat(contours_poly[i]));
			minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]);
		}
	}

	/// Draw polygonal contour + bonding rects + circles
	instance.drawing2 = Mat::zeros(threshold_output.size(), CV_8UC3);

	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(instance.rng.uniform(0, 255), instance.rng.uniform(0, 255), instance.rng.uniform(0, 255));
		drawContours(instance.drawing2, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
	}

	Canny(instance.drawing2, instance.dst, 50, 200, 3);

	cvtColor(instance.dst, instance.cdst, CV_GRAY2BGR);

#if 0

	vector<Vec2f> lines;
	HoughLines(dst, lines, 100, CV_PI / 360, 500, 100, 10); //(dst, lines, 10, CV_PI / 360, 500, 100, 10)

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

		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
	}

#else

	vector<Vec4i> lines;

	HoughLinesP(instance.dst, lines, 20, CV_PI / 360, 50, 135, 10); //(dst, lines, 1, CV_PI / 360, 50, 135, 10) *** threshold changed

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		double Angle = atan2(l[3] - l[1], l[2] - l[0]) * 180.0 / CV_PI;

		if (Angle != 0)
		{
			line(instance.cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
		}
	}

#endif

	imshow("detected lines", instance.cdst);
	/// Show in a window
	namedWindow("Contours2", CV_WINDOW_AUTOSIZE);
	imshow("Contours2", instance.drawing2);
}
// readDataFromFile() reads the depth data from a .txt file into an array for processing
void profile::readDataFromFile()
{
	ifstream data_in;
	data_in.open("C:\\Users\\Lee Seemann\\Documents\\GitHub\\CPE_Senior_Design\\C# Wrapper\\wrapper\\wrapper\\bin\\Debug\\data.txt");
	int size = 307200;
	depth_data = new short[size]; // this value should be dynamically obtained if this function is used other than for debugging
	for (int i = 0; i < size; i++)
	{
		data_in >> depth_data[i];
	}
	
}

void profile::shiftDepthArray(short depthArray[DEPTH_WIDTH*DEPTH_HEIGHT])
{
	for (int i = 0; i < DEPTH_WIDTH*DEPTH_HEIGHT; i++)
	{//top 13 bits contain distance in mm. The bottom 3 bits contain tracking information not relevant in this application.
		depthArray[i] = (static_cast<unsigned short>(depthArray[i])) >> 3;
	}
}

PROFILE profile::detectProfile(int xa1, int ya1, int xa2, int ya2, int xb1, int yb1, int xb2, int yb2, short depthArray[DEPTH_WIDTH*DEPTH_HEIGHT])
{
	//there are two lines, a & b. 1s are the start points, and 2's are the end points

	bool vertical = false;				//will the panel be viewed vertically or horizontally. Important for calculation. This is a hook to become user alterable.
	int lineAx, lineAy, lineBx, lineBy; //for average position of lines
	float depthA, depthB, depthAvg;
	int xAvg1, xAvg2, yAvg1, yAvg2;
	float mA, mB, mAvg, mPerp; 			//line slopes
	float intA, intB, intAvg;			//line intercepts

										//this if statement ensures on the line that the first endpoint is the lesser one. This matters for later calculations.
	if (!vertical)
	{
		int tempPoint;
		if (xa1 > xa2)
		{
			tempPoint = xa1;
			xa1 = xa2;
			xa2 = tempPoint;
			tempPoint = ya1;
			ya1 = ya2;
			ya2 = tempPoint;
		}

		if (xb1 > xb2)
		{
			tempPoint = xb1;
			xb1 = xb2;
			xb2 = tempPoint;
			tempPoint = yb1;
			yb1 = yb2;
			yb2 = tempPoint;
		}
	}
	else
	{
		int tempPoint;
		if (ya1 > ya2)
		{
			tempPoint = xa1;
			xa1 = xa2;
			xa2 = tempPoint;
			tempPoint = ya1;
			ya1 = ya2;
			ya2 = tempPoint;
		}

		if (yb1 > yb2)
		{
			tempPoint = xb1;
			xb1 = xb2;
			xb2 = tempPoint;
			tempPoint = yb1;
			yb1 = yb2;
			yb2 = tempPoint;
		}
	}

	shiftDepthArray(depthArray);

	lineAx = round((xa1 + xa2) / 2);
	lineAy = round((ya1 + ya2) / 2);
	lineBx = round((xb1 + xb2) / 2);
	lineBy = round((yb1 + yb2) / 2);

	//and some people thought middle school geometry wouldn't be useful.

	if (!vertical) 	//horizontal: y = mx + b; m = slope, b = y intercept
	{
		/*find slopes and intercepts*/
		mA = (xa1 - xa2) / float(ya1 - ya2);
		mB = (xb1 - xb2) / float(yb1 - yb2);
		mAvg = (mA + mB) / 2.0;
		mPerp = 1 / mAvg;

		intA = ya1 - mA*xa1;
		intB = yb1 - mB*xb1;
		//intAvg will be found later when endpoints on the middle line are found.

		/*
		create trapezoid
		-find inner point on both sides
		-find perpendicular line using average slope and inner point
		-find intercepting point on opposite line
		-set as new endpoint on line
		-repeat on other side
		-trapezoid is now made
		*/
		if (mAvg == 0) //weird case, 'bottom' of trapezoid is vertical
		{
			if (xa1 <= xb1) //left side
			{
				xa1 = xb1;
				ya1 = mA*xa1 + intA;
				intAvg = (intA + intB) / 2;
				xAvg1 = xb1;
				yAvg1 = mAvg*xAvg1 + intAvg;
			}
			else
			{
				xb1 = xa1;
				yb1 = mB*xb1 + intB;
				intAvg = (intA + intB) / 2;
				xAvg1 = xa1;
				yAvg1 = mAvg*xAvg1 + intAvg;
			}

			if (xa2 >= xb2) //right side
			{
				xa2 = xb2;
				ya2 = mA*xa2 + intA;
				intAvg = (intA + intB) / 2;
				xAvg2 = xb2;
				yAvg2 = mAvg*xAvg2 + intAvg;
			}
			else
			{
				xb2 = xa2;
				yb2 = mB*xb2 + intB;
				intAvg = (intA + intB) / 2;
				xAvg2 = xa2;
				yAvg2 = mAvg*xAvg2 + intAvg;
			}
		}
		else if (mAvg > 0) // panel is sitting with a positive slope in relation to camera.
		{
			int intPerp;
			intPerp = ya1 - mA*xa1;
			if (intPerp >= (yb1 - mB*xb1)) //left side
			{
				xb1 = round((intB - intPerp) / (mPerp - mB));
				yb1 = mB*xb1 + intB;
				xAvg1 = (xa1 + xb1) / 2;
				yAvg1 = (ya1 + yb1) / 2;
			}
			else
			{
				intPerp = yb1 - mB*xb1;
				xa1 = round((intA - intPerp) / (mPerp - mA));
				ya1 = mA*xa1 + intA;
				xAvg1 = (xb1 + xa1) / 2;
				yAvg1 = (yb1 + ya1) / 2;
			}

			intPerp = ya2 - mA*xa2;
			if (intPerp <= (yb2 - mB*xb2)) //right side
			{
				xb2 = round((intB - intPerp) / (mPerp - mB));
				yb2 = mB*xb2 + intB;
				xAvg2 = (xa2 + xb2) / 2;
				yAvg2 = (ya2 + yb2) / 2;
			}
			else
			{
				intPerp = yb2 - mB*xb2;
				xa2 = round((intA - intPerp) / (mPerp - mA));
				ya2 = mA*xa2 + intA;
				xAvg2 = (xb2 + xa2) / 2;
				yAvg2 = (yb2 + ya2) / 2;
			}

			intAvg = yAvg1 - mAvg*xAvg1;
		}
		else // panel is sitting with a negative slope in relation to camera.
		{
			int intPerp;
			intPerp = ya1 - mA*xa1;
			if (intPerp <= (yb1 - mB*xb1)) //left side
			{
				xb1 = round((intB - intPerp) / (mPerp - mB));
				yb1 = mB*xb1 + intB;
				xAvg1 = (xa1 + xb1) / 2;
				yAvg1 = (ya1 + yb1) / 2;
			}
			else
			{
				intPerp = yb1 - mB*xb1;
				xa1 = round((intA - intPerp) / (mPerp - mA));
				ya1 = mA*xa1 + intA;
				xAvg1 = (xb1 + xa1) / 2;
				yAvg1 = (yb1 + ya1) / 2;
			}

			intPerp = ya2 - mA*xa2;
			if (intPerp >= (yb2 - mB*xb2)) //right side
			{
				xb2 = round((intB - intPerp) / (mPerp - mB));
				yb2 = mB*xb2 + intB;
				xAvg2 = (xa2 + xb2) / 2;
				yAvg2 = (ya2 + yb2) / 2;
			}
			else
			{
				intPerp = yb2 - mB*xb2;
				xa2 = round((intA - intPerp) / (mPerp - mA));
				ya2 = mA*xa2 + intA;
				xAvg2 = (xb2 + xa2) / 2;
				yAvg2 = (yb2 + ya2) / 2;
			}

			intAvg = yAvg1 - mAvg*xAvg1;
		}
		//Trapezoid complete!	
	}
	else			//vertical:   x = my + b; m = slope, b = x intercept
	{
		/*find slopes and intercepts*/
		mA = (ya1 - ya2) / float(xa1 - xa2);
		mB = (yb1 - yb2) / float(xb1 - xb2);
		mAvg = (mA + mB) / 2.0;
		mPerp = 1 / mAvg;

		intA = xa1 - mA*ya1;
		intB = xb1 - mB*yb1;
		//intAvg will be found later when endpoints on the middle line are found.

		/*
		create trapezoid
		-find inner point on both sides
		-find perpendicular line using average slope and inner point
		-find intercepting point on opposite line
		-set as new endpoint on line
		-repeat on other side
		-trapezoid is now made
		*/
		if (mAvg == 0) //weird case, 'bottom' of trapezoid is vertical
		{
			if (ya1 <= yb1) //left side
			{
				ya1 = yb1;
				xa1 = mA*ya1 + intA;
				intAvg = (intA + intB) / 2;
				yAvg1 = yb1;
				xAvg1 = mAvg*yAvg1 + intAvg;
			}
			else
			{
				yb1 = ya1;
				xb1 = mB*yb1 + intB;
				intAvg = (intA + intB) / 2;
				yAvg1 = ya1;
				xAvg1 = mAvg*yAvg1 + intAvg;
			}

			if (ya2 >= yb2) //right side
			{
				ya2 = yb2;
				xa2 = mA*ya2 + intA;
				intAvg = (intA + intB) / 2;
				yAvg2 = yb2;
				xAvg2 = mAvg*yAvg2 + intAvg;
			}
			else
			{
				yb2 = ya2;
				xb2 = mB*yb2 + intB;
				intAvg = (intA + intB) / 2;
				yAvg2 = ya2;
				xAvg2 = mAvg*yAvg2 + intAvg;
			}
		}
		else if (mAvg > 0) // panel is sitting with a positive slope in relation to camera.
		{
			int intPerp;
			intPerp = xa1 - mA*ya1;
			if (intPerp >= (xb1 - mB*yb1)) //left side
			{
				yb1 = round((intB - intPerp) / (mPerp - mB));
				xb1 = mB*yb1 + intB;
				yAvg1 = (ya1 + yb1) / 2;
				xAvg1 = (xa1 + xb1) / 2;
			}
			else
			{
				intPerp = xb1 - mB*yb1;
				ya1 = round((intA - intPerp) / (mPerp - mA));
				xa1 = mA*ya1 + intA;
				yAvg1 = (yb1 + ya1) / 2;
				xAvg1 = (xb1 + xa1) / 2;
			}

			intPerp = xa2 - mA*ya2;
			if (intPerp <= (xb2 - mB*yb2)) //right side
			{
				yb2 = round((intB - intPerp) / (mPerp - mB));
				xb2 = mB*yb2 + intB;
				yAvg2 = (ya2 + yb2) / 2;
				xAvg2 = (xa2 + xb2) / 2;
			}
			else
			{
				intPerp = xb2 - mB*yb2;
				ya2 = round((intA - intPerp) / (mPerp - mA));
				xa2 = mA*ya2 + intA;
				yAvg2 = (yb2 + ya2) / 2;
				xAvg2 = (xb2 + xa2) / 2;
			}

			intAvg = xAvg1 - mAvg*yAvg1;
		}
		else // panel is sitting with a negative slope in relation to camera.
		{
			int intPerp;
			intPerp = xa1 - mA*ya1;
			if (intPerp <= (xb1 - mB*yb1)) //left side
			{
				yb1 = round((intB - intPerp) / (mPerp - mB));
				xb1 = mB*yb1 + intB;
				yAvg1 = (ya1 + yb1) / 2;
				xAvg1 = (xa1 + xb1) / 2;
			}
			else
			{
				intPerp = xb1 - mB*yb1;
				ya1 = round((intA - intPerp) / (mPerp - mA));
				xa1 = mA*ya1 + intA;
				yAvg1 = (yb1 + ya1) / 2;
				xAvg1 = (xb1 + xa1) / 2;
			}

			intPerp = xa2 - mA*ya2;
			if (intPerp >= (xb2 - mB*yb2)) //right side
			{
				yb2 = round((intB - intPerp) / (mPerp - mB));
				xb2 = mB*yb2 + intB;
				yAvg2 = (ya2 + yb2) / 2;
				xAvg2 = (xa2 + xb2) / 2;
			}
			else
			{
				intPerp = xb2 - mB*yb2;
				ya2 = round((intA - intPerp) / (mPerp - mA));
				xa2 = mA*ya2 + intA;
				yAvg2 = (yb2 + ya2) / 2;
				xAvg2 = (xb2 + xa2) / 2;
			}

			intAvg = xAvg1 - mAvg*yAvg1;
		}
		//Trapezoid complete!	

	}


	//With maths complete, translate points from color resolution to depth resolution.
	xa1 = round((xa1 * DEPTH_WIDTH) / COLOR_WIDTH);
	xa2 = round((xa2 * DEPTH_WIDTH) / COLOR_WIDTH);
	xb1 = round((xb1 * DEPTH_WIDTH) / COLOR_WIDTH);
	xb2 = round((xb2 * DEPTH_WIDTH) / COLOR_WIDTH);
	xAvg1 = round((xAvg1 * DEPTH_WIDTH) / COLOR_WIDTH);
	xAvg2 = round((xAvg2 * DEPTH_WIDTH) / COLOR_WIDTH);

	ya1 = round((ya1 * DEPTH_HEIGHT) / COLOR_HEIGHT);
	ya2 = round((ya2 * DEPTH_HEIGHT) / COLOR_HEIGHT);
	yb1 = round((yb1 * DEPTH_HEIGHT) / COLOR_HEIGHT);
	yb2 = round((yb2 * DEPTH_HEIGHT) / COLOR_HEIGHT);
	yAvg1 = round((yAvg1 * DEPTH_HEIGHT) / COLOR_HEIGHT);
	yAvg2 = round((yAvg2 * DEPTH_HEIGHT) / COLOR_HEIGHT);

	if (!vertical) //horizontal lines => intercepts are on Y-axis
	{
		intA = round((intA * DEPTH_HEIGHT) / COLOR_HEIGHT);
		intB = round((intB * DEPTH_HEIGHT) / COLOR_HEIGHT);
		intAvg = round((intAvg * DEPTH_HEIGHT) / COLOR_HEIGHT);
	}
	else //vertical lines => intercepts are on x-axis
	{
		intA = round((intA * DEPTH_WIDTH) / COLOR_WIDTH);
		intB = round((intB * DEPTH_WIDTH) / COLOR_WIDTH);
		intAvg = round((intAvg * DEPTH_WIDTH) / COLOR_WIDTH);
	}

	//average depth data along points on these lines
	//be sure to pull the edge lines from the slight inner of the trapezoid, this is what the average position points are for

	if (!vertical)
	{
		depthA = depthB = depthAvg = 0;

		if (lineAy > lineBy) //line a is higher, floor lineA pixels, and ceil lineB pixels
		{
			int yTemp;
			for (int i = xa1; i <= xa2; i++)
			{
				yTemp = floor(mA*i + intA);
				depthA += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthA /= float(xa2 - xa1);

			for (int i = xb1; i <= xb2; i++)
			{
				yTemp = ceil(mB*i + intB);
				depthB += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthB /= float(xb2 - xb1);

			for (int i = xAvg1; i <= xAvg2; i++)
			{
				yTemp = round(mAvg*i + intAvg);
				depthAvg += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthAvg /= float(xAvg2 - xAvg1);
		}
		else //vice versa. LineA ceil, and LineB floor
		{
			int yTemp;
			for (int i = xa1; i <= xa2; i++)
			{
				yTemp = ceil(mA*i + intA);
				depthA += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthA /= float(xa2 - xa1);

			for (int i = xb1; i <= xb2; i++)
			{
				yTemp = floor(mB*i + intB);
				depthB += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthB /= float(xb2 - xb1);

			for (int i = xAvg1; i <= xAvg2; i++)
			{
				yTemp = round(mAvg*i + intAvg);
				depthAvg += depthArray[i + yTemp*DEPTH_WIDTH];
			}
			depthAvg /= float(xAvg2 - xAvg1);
		}
	}
	else
	{
		depthA = depthB = depthAvg = 0;

		if (lineAx > lineBx) //line a is higher, floor lineA pixels, and ceil lineB pixels
		{
			int xTemp;
			for (int i = ya1; i <= ya2; i++)
			{
				xTemp = floor(mA*i + intA);
				depthA += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthA /= float(ya2 - ya1);

			for (int i = yb1; i <= yb2; i++)
			{
				xTemp = ceil(mB*i + intB);
				depthB += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthB /= float(yb2 - yb1);

			for (int i = xAvg1; i <= xAvg2; i++)
			{
				xTemp = round(mAvg*i + intAvg);
				depthAvg += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthAvg /= float(xAvg2 - xAvg1);
		}
		else //vice versa. LineA ceil, and LineB floor
		{
			int xTemp;
			for (int i = ya1; i <= ya2; i++)
			{
				xTemp = ceil(mA*i + intA);
				depthA += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthA /= float(ya2 - ya1);

			for (int i = yb1; i <= yb2; i++)
			{
				xTemp = floor(mB*i + intB);
				depthB += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthB /= float(yb2 - yb1);

			for (int i = xAvg1; i <= xAvg2; i++)
			{
				xTemp = round(mAvg*i + intAvg);
				depthAvg += depthArray[xTemp + i*DEPTH_WIDTH];
			}
			depthAvg /= float(xAvg2 - xAvg1);
		}


	}

	//compare the average depth points. Find should be midpoint depth using outside lines. compare to inside line for flat or oval.
	float depthTemp;

	//find would be midpoint depth for a flat panel according to the outside edges
	depthTemp = (depthA - depthB) / 2.0;
	if (depthTemp < 0)
		depthTemp *= -1;

	depthTemp = depthTemp - depthAvg;
	if ((depthTemp > 1) || (depthTemp < -1)) //if the depth deviates too much, we know it's oval!
	{
		PROFILE prof = oval;
		return prof;
	}



	//This is where stuff could be to differentiate square and thin... but for now we'll just say thin cuz it's flat.
	PROFILE prof = thin;
	return prof;
}

profile::~profile()
{
}
