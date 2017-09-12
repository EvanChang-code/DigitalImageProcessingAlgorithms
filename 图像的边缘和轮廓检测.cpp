/*
	* 功能：图像的边缘和轮廓检测
	* 日期：2017-9-12
	* 作者：zhangli
*/
#include "headfile.h"  // 包含常用的opencv以及C++头文件

int temp1[] = {2, -1, -1, 0}; // 梯度算子
int temp2[] = {1, 1, -1, -1}; //Roberts算子
int temp3[] = {1, 2, -1, 1, 0, -1, 0, -1, -1}; //soble算子
int temp4[] = {1, 1, 1, 1, -8, 1, 1, 1, 1}; //拉普拉斯模板
int temp5[] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};

int main(){

	int setPix(const Mat image, int x, int y, int* temp, int tw);
	Mat side(const Mat image, int *temp, int tw);

	// 显示原图像
	Mat image = imread("ti.jpg",0); 
	namedWindow("image");
	imshow("image", image);
	// 显示边缘检测图像
	Mat sideimage;
	sideimage = side(image, temp4, 3);
	namedWindow("side image");
	imshow("side image", sideimage);

	waitKey(0);
	return 0;
}

/*****************************************************************************
* 功能：对图像应用模板
* 参数：image - 灰度图像
		x,y - 像素位置
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
int setPix(const Mat image, int x, int y, int* temp, int tw){
	x = x - tw/2;
	y = y - tw/2;
	int pixsum = 0;
	for(int i=0; i<tw; i++){
		for(int j=0; j<tw; j++){
			pixsum = pixsum + (int)(temp[i*tw+j] * image.at<uchar>(x+j,y+i));
		}
	}
	return pixsum/(tw*tw);
}

/*****************************************************************************
* 功能：图像的边缘检测
* 参数：image - 灰度图像
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
Mat side(const Mat image, int *temp, int tw){
	Mat outimage;
	image.copyTo(outimage); //定义输出图像

	int h = image.cols;
	int w = image.rows;
	for(int y=tw/2; y<h-tw/2; y++){
		cout << y << endl;;
		for(int x=tw/2; x<w-tw/2; x++){
			outimage.at<uchar>(x,y) = setPix(image, x, y, temp, tw);
		}
	}

	return outimage;
}