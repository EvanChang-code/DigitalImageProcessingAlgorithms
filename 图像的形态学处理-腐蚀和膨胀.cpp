/*

	* 功能：图像形态学处理的膨胀与腐蚀
	* 日期：2017-9-7
	* 作者：zhangli

*/
#include "headfile.h"

int main()
{
	int getPix(const Mat image, int x, int y);
	bool contractEroded(const Mat image, int x, int y, int* temp, int tw);
	Mat erodedMe(const Mat image, int* temp, int tw);
	bool contractDilated(const Mat image, int x, int y, int* temp, int tw);
	Mat dilatedMe(const Mat image, int* temp, int tw);

	// 原图像
	Mat image = imread("binary.bmp");
	namedWindow("image");
	imshow("image", image);
	// 打印图像信息
	cout << image.depth() << "...." << image.channels();

	// 对图像进行腐蚀
	Mat eroded;
	int temp[9] = {0,1,0,1,1,1,0,1,0};
	int tw = 3;
	eroded = erodedMe(image, temp, tw);
	namedWindow("erdoed image");
	imshow("erdoed image", eroded);

	// 对图像进行膨胀
	Mat dilateded;
	dilateded = dilatedMe(image, temp, tw);
	namedWindow("dilate image");
	imshow("dilate image", dilateded);
	
	
	waitKey(0);
	return 0;
}

/*****************************************************************************
* 功能：获取图像每个图像的像素
* 参数：image - 三通道二值图像
		x,y - 像素位置
*****************************************************************************/
int getPix(const Mat image, int x, int y){
	int a = (image.at<Vec3b>(Point(x,y)).val[0]+image.at<Vec3b>(Point(x,y)).val[1]+image.at<Vec3b>(Point(x,y)).val[2])   /3;
	return a;
}
/*****************************************************************************
* 功能：判断是否对像素点进行腐蚀
* 参数：image - 三通道二值图像
		x,y - 像素位置
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
bool contractEroded(const Mat image, int x, int y, int* temp, int tw){
	x = x - tw/2;
	y = y - tw/2;
	for(int i=0; i<tw; i++){
		for(int j=0; j<tw; j++){
			if(temp[i*tw+j] == 1){
				if( !((temp[i*tw+j]) && (getPix(image,x+j,y+i)>200)) ){
					return false;
				}
			}
			else{ continue; }	
		}
	}
	return true;
}
/*****************************************************************************
* 功能：腐蚀图像
* 参数：image - 三通道二值图像
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
Mat erodedMe(const Mat image, int* temp, int tw){
	Mat imagecopy;
	image.copyTo(imagecopy);
	int h = image.cols; //图像的列
	int w = image.rows; //图像的行

	for(int x=tw/2; x<h-tw/2; x++){
		for(int y=tw/2; y<w-tw/2; y++){ 	
			if(contractEroded(image, x, y, temp, tw)){
				imagecopy.at<Vec3b>(Point(x,y)).val[0] = image.at<Vec3b>(Point(x,y)).val[0];
				imagecopy.at<Vec3b>(Point(x,y)).val[1] = image.at<Vec3b>(Point(x,y)).val[1];
				imagecopy.at<Vec3b>(Point(x,y)).val[2] = image.at<Vec3b>(Point(x,y)).val[2];
			}
			else{
				imagecopy.at<Vec3b>(Point(x,y)).val[0] = 0;
				imagecopy.at<Vec3b>(Point(x,y)).val[1] = 0;
				imagecopy.at<Vec3b>(Point(x,y)).val[2] = 0;
			}
		}
	}
	return imagecopy;
}
/*****************************************************************************
* 功能：判断是否对像素点进行膨胀
* 参数：image - 三通道二值图像
		x,y - 像素位置
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
bool contractDilated(const Mat image, int x, int y, int* temp, int tw){
	x = x - tw/2;
	y = y - tw/2;
	for(int i=0; i<tw; i++){
		for(int j=0; j<tw; j++){
			if(temp[i*tw+j] == 1){
				if( ((temp[i*tw+j]) && (getPix(image,x+j,y+i)>200)) ){
					return true;
				}
			}
			else{ continue; }
		}
	}
	return false;
}
/*****************************************************************************
* 功能：膨胀图像
* 参数：image - 三通道二值图像
		temp - 模板，下面定义一个一维数组
		tw - 模板尺寸
*****************************************************************************/
Mat dilatedMe(const Mat image, int* temp, int tw){
	Mat imagecopy;
	image.copyTo(imagecopy);
	int h = image.cols; //图像的列
	int w = image.rows; //图像的行

	for(int x=tw/2; x<h-tw/2; x++){
		for(int y=tw/2; y<w-tw/2; y++){ 	
			if(contractDilated(image, x, y, temp, tw)){
				imagecopy.at<Vec3b>(Point(x,y)).val[0] = 255;
				imagecopy.at<Vec3b>(Point(x,y)).val[1] = 255;
				imagecopy.at<Vec3b>(Point(x,y)).val[2] = 255;
			}
			else{
				imagecopy.at<Vec3b>(Point(x,y)).val[0] = 0;
				imagecopy.at<Vec3b>(Point(x,y)).val[1] = 0;
				imagecopy.at<Vec3b>(Point(x,y)).val[2] = 0;
			}
		}
	}
	return imagecopy;
}





