#include <iostream>
#include <stdexcept>
using namespace std;
class MyTest_Base
{
public:
    virtual ~MyTest_Base()
    {
    }

    void Func()
    {
        throw std::logic_error("123");
    }

    void Other() {}
};

int main()
{
    try
    {
        // 构造一个对象，当obj对象离开这个作用域时析构将会被执行
        MyTest_Base obj;

        obj.Func();
    }
    catch (std::exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "unknow exception" << endl;
    }
}
