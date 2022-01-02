//
// Created by 2Myth Vector on 2022/1/2.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

// 图片颜色填充
void imfill(){
    Mat im_in= imread("/Users/2mythvector/ClionCV/images/nickel.jpg",IMREAD_GRAYSCALE);

    Mat im_th;
    // thresh脱粒
    threshold(im_in,im_th,200,255,THRESH_BINARY_INV);

    // floodfill填色
    Mat im_floodfill=im_th.clone();
    floodFill(im_floodfill,cv::Point(0,0),Scalar(255));

    // 颜色反转填色后的图片
    Mat im_floodfill_inv;
    bitwise_not(im_floodfill,im_floodfill_inv);

    // 结合两张图片获得前景
    Mat im_out=(im_th|im_floodfill_inv);

    // 展示图片
    imshow("Threshold Image",im_th);
    imshow("Floodfill Image",im_floodfill);
    imshow("Inverted Floodfill Image",im_floodfill_inv);
    imshow("Foreground Image",im_out);

    waitKey(0);
}

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