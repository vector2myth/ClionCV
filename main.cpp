#include "primer/primer.cpp"
#include "opencv4basic/basic.cpp"
#include "opencv4advanced/advanced.cpp"

#include <pthread.h>

int main() {
    Box box1;
    Box box2;
    double volume=0.0;
    box1.height=5;
    box1.breadth=6;
    box1.length=10;
    volume=box1.volume(box1.height,box1.breadth,box1.length);
    cout<<volume<<endl;

    Line line1(10);
    // 设置长度
    line1.setLength(6.0);
    cout<<line1.getLength()<<endl;
    return 0;
}
