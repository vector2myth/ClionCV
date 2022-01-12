//
// Created by 2Myth Vector on 2022/1/12.
//

#ifndef CLIONCV_BUILDERPATTERN_H
#define CLIONCV_BUILDERPATTERN_H

#include <iostream>
#include <string>
#include <memory>


using namespace std;

// 产品类
class House{
private:
    string floor;
    string wall;
    string roof;
public:
    House()=default; // 构造函数
    void setFloor(string iFloor){
        this->floor=iFloor;
    }
    void setWall(string iWall){
        this->wall=iWall;
    }
    void setRoof(string iRoof){
        this->roof=iRoof;
    }
    // 打印House信息
    void printInfo(){
        cout<<this->floor.c_str()<<endl;
        cout<<this->wall.c_str()<<endl;
        cout<<this->roof.c_str()<<endl;
    }
};

// 抽象建造者
class AbstractBuilder{
public:
    House *house;
    AbstractBuilder(){
        house=new House;
    }
    AbstractBuilder(const AbstractBuilder& o)=delete;   // 不想使用该函数，用=delete
    AbstractBuilder& operator=(const AbstractBuilder& o)=delete;

    virtual ~AbstractBuilder(){
        if (house!= nullptr){
            delete house;
            house= nullptr; // 析构函数，在对象结束时使用，然后释放指针
        }
    }
    // 抽象方法
    virtual void buildFloor()=0;
    virtual void buildWall()=0;
    virtual void buildRoof()=0;

    virtual House *getHouse()=0;

};

// 具体建造者
class ConcreteBuilderA:public AbstractBuilder{
public:
    ConcreteBuilderA(){
        cout<<"A 开始建造！"<<endl;
    }
    ConcreteBuilderA(const AbstractBuilder& o)=delete;   // 不想使用该函数，用=delete
    ConcreteBuilderA& operator=(const AbstractBuilder& o)=delete;
    ~ConcreteBuilderA(){
        cout<<"A 结束建造！"<<endl;
        if (house!= nullptr){
            delete house;
            house= nullptr; // 析构函数，在对象结束时使用，然后释放指针
        }
    }
    // 具体实现方法
    void buildFloor(){
        this->house->setFloor("A 的 Floor");
    }
    void buildWall(){
        this->house->setWall("A 的 Wall");
    }
    void buildRoof(){
        this->house->setRoof("A 的 Roof");
    }

    House *getHouse(){
        return this->house;
    }
};
class ConcreteBuilderB:public AbstractBuilder{
public:
    ConcreteBuilderB(){
        cout<<"B 开始建造！"<<endl;
    }
    ConcreteBuilderB(const AbstractBuilder& o)=delete;   // 不想使用该函数，用=delete
    ConcreteBuilderB& operator=(const AbstractBuilder& o)=delete;
    ~ConcreteBuilderB(){
        cout<<"B 结束建造！"<<endl;
        if (house!= nullptr){
            delete house;
            house= nullptr; // 析构函数，在对象结束时使用，然后释放指针
        }
    }
    // 具体实现方法
    void buildFloor(){
        this->house->setFloor("B 的 Floor");
    }
    void buildWall(){
        this->house->setWall("B 的 Wall");
    }
    void buildRoof(){
        this->house->setRoof("B 的 Roof");
    }

    House *getHouse(){
        return this->house;
    }
};

// 指挥者Director
class Director{
private:
    AbstractBuilder *builder;
public:
    Director():builder(nullptr){}
    ~Director(){
        if(this->builder!= nullptr){
            delete builder;
            builder= nullptr;
        }
    }
    Director(const Director&)=delete;
    Director& operator=(const Director&)=delete;

    // 具体实现方法
    void setBuilder(AbstractBuilder *iBuilder){
        this->builder=iBuilder;
    }
    // 封装组装流程，返回建造结果
    House *construct(){
        builder->buildFloor();
        builder->buildWall();
        builder->buildRoof();

        return builder->getHouse();
    }
};

void runBuilderPattern(){
    // 抽象建造者
    AbstractBuilder *builder;
    // 指挥者
    Director *director = new Director();
    // 产品：House
    House *house;

    // 指定具体建造者A
    builder = new ConcreteBuilderA();
    director->setBuilder(builder);
    house = director->construct();
    house->printInfo();
    delete builder;

    // 指定具体建造者A
    builder = new ConcreteBuilderB();
    director->setBuilder(builder);
    house = director->construct();
    house->printInfo();


    delete director;
    delete builder;
}

#endif //CLIONCV_BUILDERPATTERN_H
