# ClionCV
+ 用来学习OpenCV的C++语言实现
+ 学习使用GitHub来管理项目

`有时候也会用来记录的编程成长记录吧`

`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`

## 第7章 类
> 类的基本思想是数据抽象（data abstraction）和封装（encapsulation）
> 
> 数据抽象：是一种依赖于接口（interface）和实现（implementation）分离的编程以及设计技术
>>接口：包括用户所能执行的操作;   
>>实现：包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数;
> 
> 封装：实现类的接口和实现的分离
> >封装后的类隐藏了它的实现细节，用户只能使用，不能访问实现部分；

+ 构造函数：用来初始化类的实例化对象，也就是初始化类对象的数据成员，只要类的对象被创建，就会执行这个类的构造函数

---
## 第二章 内存寻址
>+ 80x86微处理器怎样进行芯片级的内存寻址
>+ Linux如何利用寻址硬件-->分页单元

### 内存地址
> 1、逻辑地址
> > 包含在机器语言指令中用来指定一个操作数或一条指令的地址；
+ 在分段结构中使用，每一个逻辑地址都由一个段（segment）和偏移量（offset）组成，
    偏移量致命了从段开始的地方到实际地址之间的距离。
> 2、线性地址（虚拟地址）
> > 是一个32位无符号整数，用来表示高达4G的地址
+ 线性地址通常用16进制数字表示，0x00000000~0xffffffff。
> 3、物理地址
> > 用于内存芯片级内存单元寻址
+ 物理地址与从微处理器的地址引脚发送到内存总线上的电信号相对应。

逻辑地址中的段标识符是16位长的字段，成为段选择符（Segment Selector）
处理器提供段寄存器来存放段选择符
+ cs：代码段寄存器，指向包含程序指令的段；
+ ss：栈段寄存器，指向包含当前程序栈的段；
+ ds：数据段寄存器，指向包含静态数据或者全局数据段；
+ es，fs，gs：一般用途，可以只想任意的数据段。