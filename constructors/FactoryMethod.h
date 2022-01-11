//
// Created by 2Myth Vector on 2022/1/11.
//

#ifndef CLIONCV_FACTORYMETHOD_H
#define CLIONCV_FACTORYMETHOD_H

#include <iostream>
#include <string.h>
using namespace std;

// 抽象产品类Abstract Product
class AbstractProductFM{
public:
    // 构造方法
    AbstractProductFM(){

    }
    // 析构方法，对象创建结束调用
    virtual ~AbstractProductFM(){
        cout<<"结束"<<endl;
    }
    // virtual虚函数，告诉子类来继承调用
    virtual void printName(){};
    virtual void play(){};
};
// 具体产品类
class Man:public AbstractProductFM{
public:
    Man(){
        printName();
        play();
    }
    // 具体实现方法
    void printName(){
        cout<<"Man:name"<<endl;
    }
    void play(){
        cout<<"Man:play"<<endl;
    }
};
class Woman:public AbstractProductFM{
public:
    Woman(){
        printName();
        play();
    }
    // 具体实现方法
    void printName(){
        cout<<"Woman:Vv"<<endl;
    }
    void play(){
        cout<<"Woman:play"<<endl;
    }
};

// 抽象工厂类Abstract Factory
class AbstractFactory{
public:
    virtual ~AbstractFactory(){};
    virtual AbstractProductFM *getProduct()=0;
};

// 具体工厂类Concrete Factory
class ManFactory:public AbstractFactory{
public:
    ManFactory(){
        cout<<"Man Factory"<<endl;
    }
    AbstractProductFM *getProduct(){
        cout<<"Man +1"<<endl;
        return new Man;
    }
};
class WomanFactory:public AbstractFactory{
public:
    WomanFactory(){
        cout<<"Woman Factory"<<endl;
    }
    AbstractProductFM *getProduct(){
        cout<<"Woman +1"<<endl;
        return new Woman;
    }
};

void runFactoryMethod(){
    cout<<"工厂方法类"<<endl;

    shared_ptr<AbstractFactory> fac= make_shared<ManFactory>();
    shared_ptr<AbstractProductFM> product= shared_ptr<AbstractProductFM>(fac->getProduct());

    fac= make_shared<WomanFactory>();
    product=shared_ptr<AbstractProductFM>(fac->getProduct());
}


#endif //CLIONCV_FACTORYMETHOD_H
