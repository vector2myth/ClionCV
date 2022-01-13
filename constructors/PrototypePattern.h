//
// Created by 2Myth Vector on 2022/1/12.
//

#ifndef CLIONCV_PRPTOTYPEPATTERN_H
#define CLIONCV_PRPTOTYPEPATTERN_H

#include <iostream>
#include <memory>

using namespace std;

class WorkModel{
public:
    char *modelName;
    void setWorkModelName(char *iName){
        this->modelName=iName;
    }
};

// 抽象原型类Prototype
class PrototypeWork{
public:
    PrototypeWork(){}
    virtual ~PrototypeWork(){}
    virtual PrototypeWork *clone()=0;
};

// 具体原型类Concrete
class ConcreteWork:public PrototypeWork{
private:
    char* name;
    int idNum;
    WorkModel *workModel;
public:
    ConcreteWork(){}
    ConcreteWork(char* iName,int iIdNum,char* modelName){
        this->name=iName;
        this->idNum=iIdNum;
        this->workModel=new WorkModel;
        this->workModel->setWorkModelName(modelName);
    }

    void setName(char* iName){
        this->name=iName;
    }
    void setIdNum(int iIdNum){
        this->idNum=iIdNum;
    }
    void setModel(WorkModel* iWorkModel){
        this->workModel=iWorkModel;
    }

    // 打印信息
    void printInfo(){
        cout<<this->name<<endl;
        cout<<this->idNum<<endl;
        cout<<this->workModel->modelName<<endl;
    }

    ConcreteWork *clone(){
        ConcreteWork *work=new ConcreteWork();
        work->setName(this->name);
        work->setIdNum(this->idNum);
        work->workModel=this->workModel;
        return work;
    }
    ~ConcreteWork(){
        delete workModel;
        workModel= nullptr;
        cout<<"结束"<<endl;
    }
};

void runPrototypePattern(){
    ConcreteWork *singleWork = new ConcreteWork("Single", 1001, "Single_Model");
    printf("\nSingle的作业：\n");

    ConcreteWork *jungleWork = singleWork->clone();
    printf("\njungle直接抄作业……\n");

    // 抄完改名字和学号，否则会被老师查出来
    printf("\njungle抄完改名字和学号，否则会被老师查出来……\n");
    jungleWork->setName("jungle");
    jungleWork->setIdNum(1002);
    WorkModel *jungleModel = new WorkModel();
    jungleModel->setWorkModelName("Jungle_Model");
    jungleWork->setModel(jungleModel);

    // 检查下是否改对了
    printf("\nSingle的作业：\n");
    singleWork->printInfo();
    printf("\nJungle的作业：\n");
    jungleWork->printInfo();

    system("pause");

    delete singleWork;
    delete jungleModel;
    delete jungleWork;
}

#endif //CLIONCV_PRPTOTYPEPATTERN_H
