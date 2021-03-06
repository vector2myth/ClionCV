//
// Created by 2Myth Vector on 2022/1/2.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;



// 绘制几何图形
void myPlot(){
    Mat img=Mat::zeros(Size(512,512),CV_8UC3);  // 生成一个黑色背景

    // 绘制图形
    circle(img,Point(50,50),25,Scalar(255,255,255),-1); // 一个黑色实心圆
    circle(img,Point(50,50),20,Scalar(255,255,255),4);  // 一个黑色空心圆

    // 绘制直线
    line(img,Point(100,100),Point(200,100),Scalar(255,255,255),2,LINE_4,0);

    // 绘制椭圆
    ellipse(img,Point(300,255),Size(100,70),0,0,100,Scalar(255,255,255),-1);
    ellipse(img,RotatedRect(Point2f(150,100),Size2f(30,20),0),Scalar(0,0,255),2);   // 绘制一个空心椭圆

    vector<Point> points;
    ellipse2Poly(Point(200,400),Size(100,70),0,0,360,2,points); // 用一些点来绘制椭圆
    for (int i = 0; i < points.size() - 1; ++i) {
        if (i==points.size()-1){
            line(img,points[0],points[i],Scalar(255,255,255),2);    // 椭圆的最后一个点与第一个点连线
            break;
        }
        line(img,points[i],points[i+1],Scalar(255,255,255),2);  // 椭圆的前一个点与后一个点连线
    }

    // 绘制矩形
    rectangle(img,Point(50,400),Point(100,450),Scalar(255,255,255),-1);
    rectangle(img,Rect (400,450,60,50),Scalar(255,255,255),2);

    //绘制多边形
    Point pp[2][6];
    pp[0][0] = Point(72, 200);
    pp[0][1] = Point(142, 204);
    pp[0][2] = Point(226, 263);
    pp[0][3] = Point(172, 310);
    pp[0][4] = Point(117, 319);
    pp[0][5] = Point(15, 260);
    pp[1][0] = Point(359, 339);
    pp[1][1] = Point(447, 351);
    pp[1][2] = Point(504, 349);
    pp[1][3] = Point(484, 433);
    pp[1][4] = Point(418, 449);
    pp[1][5] = Point(354, 402);
    Point pp2[5];
    pp2[0] = Point(350, 83);
    pp2[1] = Point(463, 90);
    pp2[2] = Point(500, 171);
    pp2[3] = Point(421, 194);
    pp2[4] = Point(338, 141);

    const Point* pts[3]={pp[0],pp[1],pp2};  // pts顶点变量
    int npts[]={6,6,5}; // 顶点个数
    fillPoly(img,pts,npts,3,Scalar(125,125,125),8);// 绘制三个多边形

    // 生成文字
    putText(img,"Polygon",Point(100,400),2,1,Scalar(255,255,255));

    imshow("",img);
    waitKey(0);
    return;

}

// 未完成。。。
void myPyramid(){
    Mat img= imread("/Users/2mythvector/ClionCV/images/rocket.png");
    if (img.empty()){
        cout<<"文件不存在！"<<endl;
        return;
    }

    vector<Mat> Gauss,Lap;  // 高斯金字塔和拉普拉斯金字塔
    int level=3;    // 高斯金字塔下采样次数
    Gauss.push_back(img);   // 将原图作为高斯金字塔的第0层

    // 开始构建高斯金字塔
    for (int i = 0; i < level; i++) {
        Mat gauss;
        pyrDown(Gauss[i],gauss);    // 下采样
        Gauss.push_back(gauss);
    }

    // 构建拉普拉斯金字塔
    for (int i = Gauss.size()-1;i>0; i--) {
        Mat lap,upGauss;

        // 金字塔的最上面那层图像
        if (i==Gauss.size()-1){
            Mat down;
            pyrDown(Gauss[i],down); // 上采样
            pyrUp(down,upGauss);
            lap=Gauss[i]-upGauss;
            Lap.push_back(lap);
        }
        pyrUp(Gauss[i],upGauss);
        lap=Gauss[i]-upGauss;
        Lap.push_back(lap);
    }

    // 查看两个金字塔中的图像
    for (int i = 0; i < Gauss.size(); i++) {
        string name= to_string(i);
        imshow("Gauss"+name,Gauss[i]);
        imshow("Lap"+name,Lap[i]);
    }

    waitKey(0);
}

// 图像阈值转换
void myThreshold(){
    Mat img= imread("/Users/2mythvector/ClionCV/images/rocket.png");
    if (img.empty()){
        cout<<"请确认图片文件名称是否正确！"<<endl;
        return;
    }

    Mat gray;
    cvtColor(img,gray,COLOR_BGR2GRAY);
    Mat img_B,img_B_V,gray_B,gray_B_V,gray_T,gray_T_V,gray_TRUNC;

    /*
     * 图像二值化（ Image Binarization）就是将图像上的像素点的灰度值设置为0或255，
     * 也就是将整个图像呈现出明显的黑白效果的过程。
     * 在数字图像处理中，二值图像占有非常重要的地位，图像的二值化使图像中数据量大为减少，从而能凸显出目标的轮廓。
     * */
    // 彩色图像二值化
    threshold(img,img_B,125,255,THRESH_BINARY);
    threshold(img,img_B_V,125,255,THRESH_BINARY_INV);   // 二值化取反
    imshow("img_B",img_B);
    imshow("img_B_V",img_B_V);

    /*
     * THRESH_TOZERO表示将灰度值与阈值thresh进行比较，
     * 如果灰度值大于thresh则将保持不变，否则将灰度值改为0。
     * THRESH_TOZERO_INV方法与其相反，将灰度值与阈值thresh进行比较，
     * 如果灰度值小于等于thresh则将保持不变，否则将灰度值改为0。
     * */
    // 灰度图像TOZERO变换
    threshold(gray,gray_T,125,255,THRESH_TOZERO);
    threshold(gray,gray_T_V,125,255,THRESH_TOZERO_INV);
    imshow("gray_T",gray_T);
    imshow("gray_T_V",gray_T_V);

    /*
     * THRESH_TRUNC
     * 重新给图像的灰度值设定一个新的最大值，将大于新的最大值的灰度值全部重新设置为新的最大值，
     * 具体逻辑为将灰度值与阈值thresh进行比较，
     * 如果灰度值大于thresh则将灰度值改为thresh，否则保持灰度值不变
     * */
    // 灰度图像TRUNC变换
    threshold(gray,gray_TRUNC,125,255,THRESH_TRUNC);
    imshow("gray_TRUNC",gray_TRUNC);

    /*
     * 大津法（OTSU）是一种确定图像二值化分割阈值的算法,
     * 按图像的灰度特性，将图像分成背景和前景两部分,
     * 求图像全局阈值的最佳方法，适用于大部分需要求图像全局阈值的场合。
     * */

    /*
     * 三角法求阈值
     * 该方法是使用直方图数据，基于纯几何方法来寻找最佳阈值，
     * 它的成立条件是假设直方图最大波峰在靠近最亮的一侧，然后通过三角形求得最大直线距离，
     * 根据最大直线距离对应的直方图灰度等级即为分割阈值
     * */
    // 灰度图像大津法和三角形法二值化
    Mat img_Thr= imread("/Users/2mythvector/ClionCV/images/threshold.png",IMREAD_GRAYSCALE);
    Mat img_Thr_0,img_Thr_T;
    threshold(img_Thr,img_Thr_0,100,255,THRESH_BINARY|THRESH_OTSU);
    threshold(img_Thr,img_Thr_T,125,255,THRESH_BINARY|THRESH_TRIANGLE);
    imshow("img_Thr",img_Thr);
    imshow("img_Thr_0",img_Thr_0);
    imshow("img_Thr_T",img_Thr_T);

    // 灰度图像自适应二值化
    Mat adaptive_mean,adaptive_gauss;
    adaptiveThreshold(img_Thr,adaptive_mean,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,55,0);
    adaptiveThreshold(img_Thr,adaptive_gauss,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,55,0);
    imshow("adaptive_mean",adaptive_mean);
    imshow("adaptive_gauss",adaptive_gauss);

    waitKey(0);
}