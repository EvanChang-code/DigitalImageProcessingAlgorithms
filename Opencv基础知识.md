###1. 像素值操作
```
rect(x,y,w,h)        //x表示先从上向下`|`，y表示从左到右`——`
```
```
image.at<uchar>(i,j) //表示 i行、j列
image.rows           //行
image.cols           //列
image.at<Vec3b>(i,j) //B,G,R
```
```
image.ptr<uchar>(1)  //取i行首像素指针
```
```
//element_size = byte*channel
//CV_8U3C 的 elemnet_size = 1*3 = 3
//二维情况
image.data + image.step[0]*row + image.step[1]*col //step[0]表示每行单位长度，step[1]表示一个元素的大小(element_size)
//三维情况
image.data + image.step[0]*dim + step[1]*row + step[2]*col //step[0]表示维度 ...

```

###2. 图像深度
```
    Mat_<uchar> - CV_8U - element size 1
    Mat_<char> - CV_8S - element size 2
    Mat_<int> - CV_32S
    Mat_<float> - CV_32F
    Mat_<double> - CV_64F
```

###3. Common mistakes