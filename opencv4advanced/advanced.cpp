//
// Created by 2Myth Vector on 2022/1/2.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

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


/*
 * 用haar分类器进行人脸识别
 * */
String face_cascade_name="/Users/2mythvector/ClionCV/data/haarcascade_frontalface_alt2.xml";
CascadeClassifier face_cascade;


// 检测人脸
void detectFace(Mat frame){
    Mat frame_gray;
    vector<Rect> face;  // 图片是矩形结构

    // 进行灰度转换
    cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
    // 直方图均衡化
    equalizeHist(frame_gray,frame_gray);

    // 调用函数
    face_cascade.detectMultiScale(frame_gray,face,1.1,2,CASCADE_SCALE_IMAGE,Size(30,30));

    // 遍历所有人脸
    for(size_t i=0;i<face.size();i++){
        // 根据返回的Rect的x、y坐标，宽width和高height计算出人脸的中心位置
        Point center(face[i].x+face[i].width/2,face[i].y+face[i].height/2);
        // 调用ellipse画出人脸椭圆形边框
        ellipse(frame,center,Size(face[i].width/2,face[i].height/2),0,0,360,Scalar(255,0,255),4,8,0);
    }

    // 刷新窗口显示图像
    imshow("Face",frame);
}

void haar(){
    VideoCapture capture;
    Mat frame;

    // 调用haar分类器，首先检测这个分类器文件是否能被加载
    if (!face_cascade.load(face_cascade_name)){
        cout<<"连分类器都没有，还检测个屁的人脸！"<<endl;
        return;
    }

    // 调用摄像头，首先检测摄像头能不能用
    capture.open(0);
    if (!capture.isOpened()){
        cout<<"连摄像头都没有，还检测个屁的人脸！"<<endl;
        return;
    }

    // 创建窗口
    namedWindow("face");

    while (1){
        capture>>frame;
        detectFace(frame);  // 对图像帧进行识别

        // 按下Esc结束
        int c= waitKey(0);
        if (c==27){
            return;
        }
    }
}