/*********************************************

	Intordution: ʹ����ģ��ģ�壩��ͼ�������������
	Date: 2017-6-7
	Author: zhangli

*********************************************/

#include "headfile.h"

// ʹ����ģ��ģ�壩��ͼ�������������
// imageΪͼ�� tmΪ�����С��ÿ�л�ÿ�е���Ŀ������x,y��Ϊ���꣬ templeΪģ�� 
int templtExcuteAsh(const Mat &image, int tm, int x, int y, uchar *temple){	
	int px = 0,py = 0;
	int sum = 0;
	for(int i=0; i<tm; i++){
		for(int j=0; j<tm; j++){
			px = x - tm/2 + j;
			py = y - tm/2 + i;
			sum = sum + image.at<ushort>(px,py) * temple[i*tm+j]; 
		}
	}
	return sum;
}

int main(){
	
	Mat image, copyImage;
	uchar temple[9] = {1,1,1,1,1,1,1,1,1}; //������ģ

	image = imread(" xxx \\beach.jpg",0);
	image.convertTo(copyImage, CV_16U);
	cout << copyImage.depth() << ";" << copyImage.rows << ";" << copyImage.cols << endl; //�鿴ͼ����Ϣ

	// ȥ��ͼ�����ܵ��к���
	for(int i=1; i<copyImage.rows-1; i++){
		for(int j=1; j<copyImage.cols-1; j++){
			copyImage.at<ushort>(i,j) =  templtExcuteAsh(copyImage, 3, i, j, temple);
		}
		
	}
	
	namedWindow("image");
	imshow("image", copyImage);


	waitKey(0);
	return 0;
}