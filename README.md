# 数字图像处理算法
>"headfile.h" 包含了基本opencv库文件

### [Opencv基础知识](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/Opencv%E5%9F%BA%E7%A1%80%E7%9F%A5%E8%AF%86.md)

### [Opencv基本操作](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/Opencv%E5%9F%BA%E6%9C%AC%E6%93%8D%E4%BD%9C.cpp)
* 对像素的操作以及基本的图像的变换

### [直方图均衡化](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E7%9B%B4%E6%96%B9%E5%9B%BE%E5%9D%87%E8%A1%A1%E5%8C%96.cpp)
* 对灰度图像进行直方图均衡化

### [使用掩模对图像邻域进行运算](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E4%BD%BF%E7%94%A8%E6%8E%A9%E6%A8%A1%E5%AF%B9%E5%9B%BE%E5%83%8F%E9%82%BB%E5%9F%9F%E8%BF%9B%E8%A1%8C%E8%BF%90%E7%AE%97.cpp)
* 应用于灰度图像

### [平滑空间滤波器](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E5%B9%B3%E6%BB%91%E7%A9%BA%E9%97%B4%E6%BB%A4%E6%B3%A2%E5%99%A8.cpp)
* 模板（掩模）为`temple[9] = {1,1,1,1,1,1,1,1,1}`

### [统计排序滤波器](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E7%BB%9F%E8%AE%A1%E6%8E%92%E5%BA%8F%E6%BB%A4%E6%B3%A2%E5%99%A8.cpp)
* 对邻域像素值进行排序，使序列中位于中间位置的灰度作为中心像素的灰度
* 临时数组使用动态数组，在delete时出现 *heap corruption detected*，改用一般数组

### [图像的形态学处理-腐蚀和膨胀](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E5%9B%BE%E5%83%8F%E7%9A%84%E5%BD%A2%E6%80%81%E5%AD%A6%E5%A4%84%E7%90%86-%E8%85%90%E8%9A%80%E5%92%8C%E8%86%A8%E8%83%80.cpp)
* 应用三通道二值图像

### [图像的边缘和轮廓检测](https://github.com/EvanChang-code/DigitalImageProcessingAlgorithms/blob/master/%E4%BD%BF%E7%94%A8%E6%8E%A9%E6%A8%A1%E5%AF%B9%E5%9B%BE%E5%83%8F%E9%82%BB%E5%9F%9F%E8%BF%9B%E8%A1%8C%E8%BF%90%E7%AE%97.cpp)
* 使用梯度算子，Roberts算子，Soble算子，拉普拉斯算子；
* 使用时只需要应用不同的模板；
