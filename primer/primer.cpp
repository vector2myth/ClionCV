//
// Created by 2Myth Vector on 2022/1/2.
//

#include <iostream>

using namespace std;

void hello(){
    cout<<"Hello Wo~~~rld!"<<endl;
}

class Screen{
public:
    typedef string::size_type pos;
    Screen()=default;

    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c){

    }
    char get()const{
        return contents[cursor];
    }

    inline char get(pos ht,pos wd)const;
    Screen &move(pos r,pos c);

private:
    pos cursor=0;
    pos height=0,width=0;
    string contents;
};