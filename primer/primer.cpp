//
// Created by 2Myth Vector on 2022/1/2.
//

#include <iostream>
#include <vector>

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

    inline char get(pos ht,pos wd) const;
    Screen &move(pos r,pos c);

private:
    pos cursor=0;
    pos height=0,width=0;
    string contents;
};

/*引用返回左值*/
char &get_val(string &str,string::size_type ix){
    return str[ix];
}
int getval(){
    string s("a value");
    cout<<s<<endl;
    get_val(s,0)='A';
    cout<<s<<endl;

    return EXIT_SUCCESS;
}

/*列表初始化返回值*/
vector<string> process(){
    string excepted("404");
    string actual("400");

    if (excepted.empty()){
        return {};
    } else if (excepted==actual){
        return {"functionalWeb","404"};
    } else{
        return {"functionalWeb",excepted,actual};
    }

    /*
     * 输出vector的方式
     * for(auto v:process()){
        cout<<v<<endl;
    }
     * */
}

// 声明一个返回数组指针的函数
int arr[10];        // 一个数组，含有10个整数
int *p1[10];        // 一个数组，含有10个指针
int (*p2)[10]=&arr; // 一个指针，指向含有10个整数的数组

// 尾置返回类型
auto func(int i)->int(*)[10];   // func接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组

// 使用decltype
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
decltype(odd) *arrPtr(int i){
    return (i%2)?&odd:&even;    // 返回一个指向数组的指针
}
/*
 * 三种函数相关的语言特性
 * ，内联函数，constexpr函数
 * */
// 默认实参，既能接受默认值，也能接受用户传入的值，使用的时候省略该实参
/*调用的时候，实参会按照其位置解析，默认实参负责填补函数调用时缺少的尾部实参
 * 所以我们调用是传入的值默认代替调前面的参数值*/

// 内联函数，可以避免调用函数的开销，使用关键字inline
inline const string &shorterString(const string &s1,const string &s2){
    return s1.size()>s2.size()?s1:s2;
}
/*内联函数一般用于优化规模较小、流程直接、频繁调用的函数*/

// constexpr函数，可用于常量表达式

/*函数指针，指向函数而非对象*/
bool (*pf)(const string&,const string&);    // pf是指针，指向函数，函数返回值是bool类型
// 如果没有括号，bool *pf就是一个返回值为bool指针的函数

// 友元，允许其他类或者函数访问其非公有成员，用friend关键字
// return *this; // 返回调用该函数的对象

class Box{
public:
    Box()=default;
    double length,breadth,height;
    Box(double ,double ,double ){
        this->length=0;
        this->breadth=0;
        this->height=0;
    }
    double volume(double l,double b,double h){
        return l*b*h;
    }
};
// 构造函数
class Line{
public:
    void setLength(double  len);
    double getLength(void);
    Line(double len); // 构造函数声明，带参数
    ~Line();    // 析构函数声明

private:
    double length;
};
// 成员函数定义，也可以定义构造函数
// 构造函数是一定会被执行的，而且是在对象被创建的时候就被执行，不在乎定义构造函数的位置，函数体内的定义>调用时参数的权限
Line::Line(double len){
    // 可以使用初始化列表来初始化字段
    len=20;
    cout<<"对象正在被创建。。。"<<len<<endl;  // 带参数的构造函数会在被调用的时候传入参数
}
// 析构函数定义
Line::~Line(void) {
    cout<<"析构函数已执行，对象已经被删除！"<<endl;
}
// 函数重载
void Line::setLength(double len) {
    length=len;
}
double Line::getLength(void) {
    return length;
}

// 析构函数，会在每次删除创建的对象时执行，加上波浪号~作为前缀

void stl1(){
    vector<int> vec;
    int i;

    cout<<vec.size()<<endl;

    for(i=0;i<5;i++){
        vec.push_back(i);
    }
    cout<<vec.size()<<endl;

    for(auto i:vec){
        cout<<i<<endl;
    }
    cout<<"使用STL的迭代器访问"<<endl;

    vector<int>::iterator v=vec.begin();
    while (v!=vec.end()){
        cout<<*v<<endl;
        v++;    // 指针移动
    }
}