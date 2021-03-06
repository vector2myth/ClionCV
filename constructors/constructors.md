## 简单工厂模式
> 关注对象的创建过程，让用户在对象使用过程中无须关心对象的创建细节，从而降低系统耦合度，易于修改和扩展
>> 定义一个简单工厂类，可以根据参数的不同返回不同类的实例，被创建的实例通常都具有相同的父类
+ 有三种角色
> 工厂Factory：根据客户提供的具体产品类的修改，创建具体产品实例；<br>
> 抽象产品Abstract Product：具体产品类的基类，包含创建产品的公共方法；<br>
> 具体产品Concrete Product：抽象产品的派生类，包含具体产品特有的实现方法。<br>
+ 简单工厂模式的优点
  + 工厂提供创建具体产品的方法，可不不必参与产品的创建过程
  + 客户只需要对应产品的参数即可
+ 简单工厂模式的缺点
  + **违背了开闭原则**，即对扩展开放、对修改关闭，简单工厂在扩展时就会修改既有的代码
  + 所有的判断逻辑都在工厂类中实现，**一旦工厂类出现逻辑错误**，所有的产品都会受到影响
---
`shared_ptr和make_ptr的用法`：
- 前提：
>在程序设计过程中，要开启一个不知道大小的内存空间，这个空间会根据所需大小改变，这就是动态内存
+ 用法：
> shared_ptr，可以指向特定类型的对象，用于自动释放所指的对象
make_shared，在动态内存中分配一个对象并初始化，返回此对象指向的shared_ptr
头文件#include<memory>
---
虚函数virtual方法的使用场景：父类告诉子类，继承接口，修改实现，从而可以面向接口编程。
~析构函数，在对象创建结束之后使用
---
## 工厂方法模式
>定义一个用于创建其他对象的接口，但是让子类决定将哪一个类实例化。
>>对简单工厂方法的进一步抽象化，满足了"开闭原则"
+ 有四个角色
>抽象工厂Abstract Factory：提供了创建产品的接口；<br>
>具体工厂Concrete Factory：主要实现了抽象工厂中的抽象方法，完成具体产品的创建;<br>
>抽象产品Abstract Product：定义了产品的规范，描述了产品的主要特征和性能；<br>
>具体产品Concrete Product：实现了抽象产品所定义的接口，由具体工厂来创建，它与具体工厂之间一一对应。
+ 优点
  + 用户只需要具体工厂的名称就可以得到所要的产品，无须知道产品的具体创建过程；<br>
  + 灵活性强，对于新产品的创建，只要多写一个相应的工厂类，无须修改原有代码，增强了系统的可扩展性；<br>
+ 缺点
  + 类的个数容易过多，增加复杂度；<br>
  + 增加了系统的抽象性和理解难度；<br>
  + 抽象产品只能生产一种产品，_此弊端可使用抽象工厂模式解决_。<br>
+ 应用场景
  + 客户端不需要知道它所需要创建的对象的类；<br>
  + 抽象工厂类通过其子类来指定创建哪个对象（运用多态性设计和里氏代换原则）。<br>
---
## 抽象工厂模式
> 提供一个创建一系列相关或者相互依赖对象的接口，而无须指定他们具体的类
+ 有四个角色
> 抽象工厂Abstract Factory：
---
## 建造者模式Builder Pattern
> 建造者膜是将客户端包含的多个部件的复杂对象的创建过程分离，客户端不需要知道复杂对象的内部组成方式与装配对象
> 只需要知道所建造者的类型就可以了
> > 将一个复杂对象的构建与其表示分离，使得同样的构建过程可以创建不同的表示
+ 包含4个角色
  + 抽象建造者Abstract Builder：创建一个Product对象的各个部件指定的抽象接口；
  + 具体建造者Concrete Builder：实现抽象建造者的接口，实现各个部件的具体构造方法和装配方法，并返回建造结果
  + 产品Product：具体的产品对象
  + 指挥者Director：构建一个使用Builder接口的对象，安排复杂对象的构建过程
    + > 客户端一般只与指挥者交互，指定建造类型，然后通过构造函数或者setter方法 <br>
    将具体建造者对象传入指挥者。
      > > 指挥者负责隔离客户与对象的生产过程，并控制产品对象的生产过程。
> 客户端指定具体建造者，并作为参数传入指挥者，通过指挥者得到结果
+ 优点
  + 客户端不需要知道产品内部组成细节，将产品本身和产品的创建过程分离，使得同样的创建过程可以创建不同的产品对象
  + 不同建造者相互独立，方便替换
+ 缺点
  + 建造者模式所创建的产品的组成成分相似，如果产品之间的差异性很大，不适合用
  + 如果产品内部时常发生变化，就会导致要定义很多具体建造者来实现这种变化，导致系统庞大
> 应用场景
> > 需要生产的产品对象有复杂的内部结构   
> 产品对象内部属性有一定的生成顺序    
> 同一个创建流程适合多种不同的产品
---
## 原型模式Prototype Pattern
> 通过复制一个已有对象来获取更多相同或者相似的对象
> > 使用原型实例来指定待创建对象的类型，并且通过复制这个原型来创建新的对象
```text
软件系统中有些对象的创建过程比较复杂，而且有时候要频繁创建
原型模式通过给出一个原型对象来指明要创建的对象的类型
然后用复制这个原型对象的方法创建出更多同类型的对象
```
+ 包含3个角色
  + 抽象原型类Abstract Prototype：声明一个用来克隆自身的接口
  + 具体原型类Concrete Prototype：实现这个克隆接口
  + 客户端Client：客户端中声明一个抽象原型类，根据客户需求来克隆具体原型类对象实例
> 关于克隆的方法：浅拷贝和深拷贝
> > 浅拷贝：如果原型对象的成员变量是值类型，将复制给拷贝对象；如果是引用/指针，就将引用/指针指向的地址复制给拷贝对象。
> 深拷贝：无论原型对象的成员变量是值类型还是引用/指针类型，都会复制给拷贝对象

---
## 单例模式Singleton
> 在内存中只会创建一次对象的设计模式   
> 在程序中多次使用同一个对象且作用相同时，为了防止频繁创建对象而浪费内存，就用单例模式