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
        // ����һ�����󣬵�obj�����뿪���������ʱ�������ᱻִ��
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
