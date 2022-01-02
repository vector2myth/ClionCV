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
