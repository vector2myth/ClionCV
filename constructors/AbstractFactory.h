//
// Created by 2Myth Vector on 2022/1/11.
//

#ifndef CLIONCV_ABSTRACTFACTORY_H
#define CLIONCV_ABSTRACTFACTORY_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// 抽象产品类AbstractProduct1
class AbstractProductAF1 {
public:
    AbstractProductAF1() {
        cout << "开始:AbstractProductAF1" << endl;
    }

    virtual ~AbstractProductAF1() {
        cout << "结束:AbstractProductAF1" << endl;
    }

    // 抽象方法
    virtual void printName() {};

    virtual void play() {};
};
// 具体产品类Product
class ProductAF1_1 : public AbstractProductAF1 {
public:
    ProductAF1_1() {
        printName();
        play();
    }

    // 具体实现方法
    void printName() {
        cout << "ProductAF1_1" << endl;
    }

    void play() {
        cout << "具体产品:ProductAF1_1" << endl;
    }
};
class ProductAF1_2 : public AbstractProductAF1 {
public:
    ProductAF1_2() {
        printName();
        play();
    }

    // 具体实现方法
    void printName() {
        cout << "ProductAF1_2" << endl;
    }

    void play() {
        cout << "具体产品:ProductAF1_2" << endl;
    }
};

// 抽象产品类AbstractProduct2
class AbstractProductAF2 {
public:
    AbstractProductAF2() {
        cout << "开始:AbstractProductAF2" << endl;
    }

    virtual ~AbstractProductAF2() {
        cout << "结束:AbstractProductAF2" << endl;
    }

    // 抽象方法
    virtual void printName() {};

    virtual void play() {};
};
// 具体产品类Product
class ProductAF2_1: public AbstractProductAF2{
public:
    ProductAF2_1(){
        printName();
        play();
    }
    // 具体实现方法
    void printName(){
        cout<<"ProductAF2_1"<<endl;
    }
    void play(){
        cout << "具体产品:ProductAF2_1" << endl;
    }
};
class ProductAF2_2: public AbstractProductAF2{
public:
    ProductAF2_2(){
        printName();
        play();
    }
    // 具体实现方法
    void printName(){
        cout<<"ProductAF2_2"<<endl;
    }
    void play(){
        cout << "具体产品:ProductAF2_2" << endl;
    }
};

// 抽象工厂类
class AbstractFactoryAF{
public:
    virtual ~AbstractFactoryAF(){}
    virtual AbstractProductAF1 *get1()=0;   // 抽象产品1
    virtual AbstractProductAF2 *get2()=0;   // 抽象产品2
};

// 两个抽象产品对应两个具体产品工厂
class ProductAF1Factory:public AbstractFactoryAF{
public:
    ProductAF1Factory(){
        cout<<"产品工厂1:ProductAF1Factory"<<endl;
    }
    AbstractProductAF1 *get1(){
        cout<<"生产具体产品1-1"<<endl;
        return new ProductAF1_1;
    }
    AbstractProductAF2 *get2(){
        cout<<"生产具体产品1-2"<<endl;
        return new ProductAF2_1;
    }
};
class ProductAF2Factory:public AbstractFactoryAF{
public:
    ProductAF2Factory(){
        cout<<"产品工厂2:ProductAF1Factory"<<endl;
    }
    AbstractProductAF1 *get1(){
        cout<<"生产具体产品2-1"<<endl;
        return new ProductAF1_2;
    }
    AbstractProductAF2 *get2(){
        cout<<"生产具体产品2-2"<<endl;
        return new ProductAF2_2;
    }
};

void runAbstractFactory(){
    cout<<"抽象工厂设计模式Abstract Factory"<<endl;
    shared_ptr<AbstractFactoryAF> af1= make_shared<ProductAF1Factory>();
    shared_ptr<AbstractProductAF1>(af1->get1());
    shared_ptr<AbstractProductAF2>(af1->get2());

    shared_ptr<AbstractFactoryAF> af2= make_shared<ProductAF2Factory>();
    shared_ptr<AbstractProductAF1>(af2->get1());
    shared_ptr<AbstractProductAF2>(af2->get2());


}

#endif //CLIONCV_ABSTRACTFACTORY_H
