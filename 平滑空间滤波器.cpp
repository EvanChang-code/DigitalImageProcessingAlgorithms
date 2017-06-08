/*********************************************

	Intordution: ƽ���ռ��˲���
	Date: 2017-6-8
	Author: zhangli

*********************************************/

#include "headfile.h"

// ʹ����ģ��ģ�壩��ͼ�������������
// imageΪͼ��tmΪ�����С��ÿ�л�ÿ�е���Ŀ������x,y��Ϊ���꣬ templeΪģ�� 
int templtExcuteAsh(const Mat &image, int tm, int x, int y, uchar *temple){	
	int px = 0,py = 0;
	int sumPix = 0;
	int averPix = 0;
	for(int i=0; i<tm; i++){
		for(int j=0; j<tm; j++){
			px = x - tm/2 + j;
			py = y - tm/2 + i;
			sumPix = sumPix + image.at<uchar>(px,py) * temple[i*tm+j]; 
		}
	}
	averPix = sumPix/9; //�������ؾ�ֵ
	if( averPix>=255 ) averPix = 255;
	else if( averPix<=0 ) averPix = 0;
	return averPix;
}

int main(){
	
	Mat image, copyImage;

	uchar temple[9] = {1,1,1,1,1,1,1,1,1}; //����ģ��


	image = imread(" xxx \\baidu1.jpg",0);
	image.copyTo(copyImage);
	cout << copyImage.depth() << ";" << copyImage.rows << ";" << copyImage.cols << endl; //�鿴ͼ����Ϣ

	// ȥ��ͼ�����ܵ��к���
	for(int i=1; i<copyImage.rows-1; i++){
		for(int j=1; j<copyImage.cols-1; j++){
			copyImage.at<uchar>(i,j) =  templtExcuteAsh(copyImage, 3, i, j, temple);
		}
	}

	namedWindow("image");
	imshow("image", copyImage);

	waitKey(0);
	return 0;
}