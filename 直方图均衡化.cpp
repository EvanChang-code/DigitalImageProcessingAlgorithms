/*********************************************

	Intordution: ֱ��ͼ���⻯
	Date: 2017-5-25
	Author: zhangli

*********************************************/
#include <windows.h> //solve "No Target Architecture" ˳��һ������ǰ��
#include "headfile.h"
#include <WINDEF.h> // BYTE �����ڸ��ļ���

long index[256]; //�ں������ⶨ����������飬����Ԫ�ػ��ʼ��Ϊ0��
BYTE count_Rate[256];

int main()
{
	Mat image, grayImage, tempImage;
	
	image = imread(" xxx \\lake.jpg");
	cvtColor(image, grayImage, CV_RGB2GRAY);
	grayImage.copyTo(tempImage);
	cout << tempImage.depth() << endl << tempImage.rows << endl << tempImage.cols << endl; //�鿴ͼ����Ϣ
	// ������ͬ���صĸ���������������
	for(int i=0; i<tempImage.rows; i++)
	{
		for(int j=0; j<tempImage.cols; j++)
		{
			uchar x = tempImage.at<uchar>(i,j);
			index[x]++;  //��������
		}
	}
	//cout << sizeof(index)/sizeof(index[0]) << endl;  //�鿴�����С
	//����ÿ��������ռ����
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
	// �޸�ͼ��
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