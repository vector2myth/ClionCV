//
// Created by 2Myth Vector on 2022/1/11.
//

#ifndef CLIONCV_SIMPLEFACTORY_H
#define CLIONCV_SIMPLEFACTORY_H

#include <iostream>
#include <string.h>
using namespace std;

// 抽象产品类Abstract Product
class AbstractProduct{
public:
    AbstractProduct(){

    }
    /*
     * virtual方法的使用场景：父类告诉子类，继承接口，修改实现，从而可以面向接口编程。
     * ~析构函数，在函数调用结束的时候使用，类的析构函数不能被继承
     * */
    virtual ~AbstractProduct(){
        cout<<"结束"<<endl;
    };
    // 抽象方法
    virtual void printName()=0;
    virtual void play()=0;
};
// 具体产品类-1
class Product1:public AbstractProduct{
public:
    Product1(){
        printName();
        play();
    }
    ~Product1(){

    }
    // 具体实现方法
    void printName(){
        cout<<"Product1具体实现方法：printName"<<endl;
    }
    void play(){
        cout<<"Product1具体实现方法：play"<<endl;
    }
};
// 具体产品类-2
class Product2:public AbstractProduct{
public:
    Product2(){
        printName();
        play();
    }
    ~Product2(){

    }
    // 具体实现方法
    void printName(){
        cout<<"Product2具体实现方法：printName()"<<endl;
    }
    void play(){
        cout<<"Product2具体实现方法：play()"<<endl;
    }
};

class Factory{
public:
    shared_ptr<AbstractProduct> getProduct(string productName){
        shared_ptr<AbstractProduct> pro;
        if (productName=="Product1"){
            pro= shared_ptr<AbstractProduct>(new Product1);
        }else if (productName=="Product2"){
            pro= shared_ptr<AbstractProduct>(new Product2);
        }
        return pro;
    }
};

void runSimpleFactory(){
    shared_ptr<Factory> fac= make_shared<Factory>();    // 用make_shared来创建对象
    shared_ptr<AbstractProduct> product=fac->getProduct("Product1");
    fac= make_shared<Factory>();
    product=fac->getProduct("Product2");
}

#endif //CLIONCV_SIMPLEFACTORY_H
