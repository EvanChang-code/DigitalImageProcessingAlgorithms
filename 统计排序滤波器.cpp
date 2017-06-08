/*********************************************

	Intordution: ͳ�������˲���
				 ������λ���м�λ�õĻҶ���Ϊ�������صĻҶ�
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

// ʹ����ģ��ģ�壩��ͼ�������������
// imageΪͼ��tmΪ�����С��ÿ�л�ÿ�е���Ŀ������x,y��Ϊ���꣬ templeΪģ�� 
int templtExcuteAsh(const Mat &image, int tm, int x, int y){	
	int px = 0,py = 0;
	int pix = 0;
	int midPix = 0;

	int pixValue[9]; //������ʱ���������洢����ֵ

	for(int i=0; i<tm; i++){
		for(int j=0; j<tm; j++){
			px = x - tm/2 + j;
			py = y - tm/2 + i;
			pix = image.at<uchar>(px,py);
			pixValue[i*tm+j] = pix;
		}
	}

	//���������ݽ�������
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