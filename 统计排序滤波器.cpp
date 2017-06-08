/*********************************************

	Intordution: 统计排序滤波器
				 序列中位于中间位置的灰度作为中心像素的灰度
	Date: 2017-5-10
	Author: zhangli

*********************************************/

#include "headfile.h"


int main(){

	int templtExcuteAsh(const Mat &image, int tm, int x, int y);
	Mat image, copyImage;

	image = imread(" xxx \\baidu1.jpg",0);
	image.copyTo(copyImage);

	for(int i=1; i<copyImage.rows-1; i++){
		for(int j=1; j<copyImage.cols-1; j++){
			copyImage.at<uchar>(i,j) =  templtExcuteAsh(copyImage, 3, i, j);
		}
	}

	namedWindow("image");
	imshow("image", copyImage);
	waitKey(0);
	return 0;
}

// 使用掩模（模板）对图像邻域进行运算
// image为图像，tm为邻域大小（每行或每列的数目），（x,y）为坐标， temple为模板 
int templtExcuteAsh(const Mat &image, int tm, int x, int y){	
	int px = 0,py = 0;
	int pix = 0;
	int midPix = 0;

	int pixValue[9]; //创建临时数组用来存储像素值

	for(int i=0; i<tm; i++){
		for(int j=0; j<tm; j++){
			px = x - tm/2 + j;
			py = y - tm/2 + i;
			pix = image.at<uchar>(px,py);
			pixValue[i*tm+j] = pix;
		}
	}

	//对数组数据进行排序
	int number = 0;
	for(int i=1; i<tm*tm; i++){
		number = pixValue[i];
		int j = i-1;
		while( (j>=0)&&(number<pixValue[j]) ){
			pixValue[ j+1 ] = pixValue[j];
			j--;
		}
		pixValue[j+1] = number;
	}
	
	midPix = pixValue[tm*tm/2];
	return midPix;
}