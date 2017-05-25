/*********************************************

	Intordution: 直方图均衡化
	Date: 2017-5-25
	Author: zhangli

*********************************************/
#include <windows.h> //solve "No Target Architecture" 顺序一定放在前面
#include "headfile.h"
#include <WINDEF.h> // BYTE 定义在该文件中

long index[256]; //在函数体外定义的内置数组，数组元素会初始化为0；
BYTE count_Rate[256];

int main()
{
	Mat image, grayImage, tempImage;
	
	image = imread(" xxx \\lake.jpg");
	cvtColor(image, grayImage, CV_RGB2GRAY);
	grayImage.copyTo(tempImage);
	cout << tempImage.depth() << endl << tempImage.rows << endl << tempImage.cols << endl; //查看图像信息
	// 计算相同像素的个数，建立索引表
	for(int i=0; i<tempImage.rows; i++)
	{
		for(int j=0; j<tempImage.cols; j++)
		{
			uchar x = tempImage.at<uchar>(i,j);
			index[x]++;  //建立索引
		}
	}
	//cout << sizeof(index)/sizeof(index[0]) << endl;  //查看数组大小
	//计算每个像素所占比例
	long tempNum;
	for(int i=0; i<256; i++)
	{
		tempNum = 0;
		for(int j=0; j<i; j++)
		{
			tempNum = index[j];
		}
		count_Rate[i] = tempNum *255.0f /tempImage.rows/tempImage.cols; 
	}
	// 修改图像
	for(int i=0; i<tempImage.rows; i++)
	{
		for(int j=0; j<tempImage.cols; j++)
		{
			uchar x = tempImage.at<uchar>(i,j);
			tempImage.at<uchar>(i,j) = (uchar) count_Rate[x] * 255;
		}
	}
	namedWindow("show grayImage");
	imshow("show grayImage",grayImage);
	namedWindow("show tempImage");
	imshow("show tempImage",tempImage);

	waitKey(0);
	return 0;
}