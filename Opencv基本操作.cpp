/*********************************************

	Intordution: the basic operation function of opencv
	Date: 2017-5-11
	Author: zhangli

*********************************************/

#include "basicoperation.h"

// 
void BasicOperationWithImage::getIntendsityValue(Mat image, int channels){
	
	if(channels == 1){
		//single channel gray scale image(8UC1)
		//Scalar: 4-element vector, `double val[4]`
		//Note the ordering of x and y
		Scalar intensity_yx = image.at<uchar> (10,11);
		Scalar intensity_xy = image.at<uchar> (Point(10,11));
		cout << intensity_yx << endl;
		cout << intensity_xy << endl;
	}
	else if(channels == 3){
		Vec3b intensity = image.at<Vec3b>(10,11);
		uchar blue = intensity.val[0];
		uchar green = intensity.val[1];
		uchar red = intensity.val[2];  
		cout << intensity << endl;
		cout << "blue:" << blue << endl;
		cout << "green:" << green << endl;
		cout << "red:" << red << endl;
	}
}

void PrimitiveOperations::primitiveOperations(Mat image, int number){

	// number
	// 1: change existing image to a black image
	// 2: Selecting a region of interest
	// 3: Conversion from color to grey scale
	// 4: change image type from 8UC1 to 32FC1
	Mat smallImg, grey, image_32F;
	Rect r(10,10,50,50);
	switch (number)
	{
		case 1: 
			image = Scalar(0);
			break;
		case 2:
			smallImg = image(r);
			break;
		case 3:
			cvtColor(image, grey, CV_BGR2GRAY);
			break;
		case 4:
			image.convertTo(image_32F, CV_32F);
			break;
	}
	
	namedWindow("showImage");
	imshow("showImage", grey);		
}

void VisualImage::visualImage(Mat image){
	Mat grey;
	cvtColor(image, grey, CV_BGR2GRAY); 
	Mat sobelx;
	Sobel(grey, sobelx, CV_32F, 1, 0);
	double minVal=0.0, maxVal=0.0;
	minMaxLoc(sobelx, &minVal, &maxVal);
	Mat draw;
	sobelx.convertTo(draw, CV_8U, 255.0/(maxVal-minVal), -minVal * 255.0/(maxVal - minVal));
	cout << "minVal:" << minVal << endl;
	cout << "maxVal:" << maxVal << endl;
	namedWindow("showImage");
	imshow("showImage", draw);
	
}
