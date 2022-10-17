#include <iostream>
#include <string>

//声明一个纯虚函数是为了让派生类只继承函数的接口，然后实现出其不同的实现。
//但是也可以给纯虚函数提供一个定义，如果想调用的话需要明确其class名称

//声明一个虚函数，但不是纯虚函数，是为了让派生类继承其函数接口，
//但是可以使用其内部的缺省实现，派生类也有可能重写他。

//声明一个非虚函数，是为了让派生类继承其实现，也就是说派生类不能去
//改变其实现
class Base
{
public:
    void mf1();
    void mf1(double x);
};
class Derived : private Base
{
public:
    void mf1()
    {
        Base::mf1();
    }
};
int main()
{
    Derived d;
    d.mf1();

    return 0;
}
