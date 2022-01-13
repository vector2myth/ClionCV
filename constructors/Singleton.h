//
// Created by 2Myth Vector on 2022/1/12.
//

#ifndef CLIONCV_SINGLETON_H
#define CLIONCV_SINGLETON_H

#define THREAD_NUM 6

#include <iostream>
#include <string.h>
#include <mutex>
#include <memory>
#include <pthread.h>

using namespace std;

// 懒汉式
class Singleton_Lazy{
private:
    Singleton_Lazy(){}
    static Singleton_Lazy* instance;
    static mutex m_mutex;
public:
    static Singleton_Lazy* getInstance(){
        cout<<"懒汉式-单例模式"<<endl;
        if(instance==NULL){
            m_mutex.lock();
            if (instance==NULL){
                cout<<"创建新的实例"<<endl;
                instance=new Singleton_Lazy();
            }
            m_mutex.unlock();
        }
        return instance;
    }
};

Singleton_Lazy* Singleton_Lazy::instance=NULL;
mutex Singleton_Lazy::m_mutex;

class Singleton_Hungry{
private:
    Singleton_Hungry(){}
    static Singleton_Hungry* instance;
public:
    static Singleton_Hungry* getInstance(){
        cout<<"恶汉式-单例模式"<<endl;
        return instance;
    }
};

Singleton_Hungry* Singleton_Hungry::instance=new Singleton_Hungry;

void* callSingleton_Lazy(void*){
    Singleton_Lazy* s=Singleton_Lazy::getInstance();
    pthread_t nThreadNum=pthread_self();

    cout<<"懒汉-线程："<<nThreadNum<<endl;

    return 0;
}

void* callSingleton_Hungry(void*){
    Singleton_Hungry* s=Singleton_Hungry::getInstance();
    pthread_t nThreadNum=pthread_self();

    cout<<"恶汉-线程："<<nThreadNum<<endl;

    return 0;
}

void runSingleton(){
    pthread_t threads_pool[THREAD_NUM];  //创建6个线程
    int tid[THREAD_NUM],i;
    void* status;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < THREAD_NUM; ++i) {
        if (i<THREAD_NUM/2){
            tid[i]= pthread_create(&threads_pool[i],NULL,callSingleton_Lazy,(void*)&i);
        } else{
            tid[i]= pthread_create(&threads_pool[i],NULL,callSingleton_Hungry,(void*)&i);
        }
        if (tid[i]){
            cout<<"ERROR"<<endl;
            exit(-1);
        }
    }
    pthread_attr_destroy(&attr);
    for(i = 0; i < THREAD_NUM; i++)
    {
        tid[i] = pthread_join(threads_pool[i], &status);
        if(tid[i])
        {
            printf("Error: unable to join.\n");
            exit(-1);
        }
    }
    printf("main exiting.\n");
    return;
}

#endif //CLIONCV_SINGLETON_H
