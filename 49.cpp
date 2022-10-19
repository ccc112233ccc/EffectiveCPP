#include <iostream>
#include <string>
#include <new>
//声明一个没有参数和没有返回值的函数，当new内存不够时候可以指定其调用这个函数
void outOfMemory()
{
    std::cerr << "Unable to satisfy request for memory\n";
    abort();
}
// RAII类，用来保证在分配内存失败抛出异常时候将全局的new_handler恢复。
class NewHandlerHolder
{
public:
    explicit NewHandlerHolder(std::new_handler nh) : handler(nh){};

    //析构函数，在析构时将设置全局的new_handler
    ~NewHandlerHolder()
    {
        std::set_new_handler(handler);
    }

private:
    std::new_handler handler;
};

//提供new holder支持
template <typename T>
class NewHandlerSupport
{
public:
    //定义set函数，使得其和std版本的一致，都是会返回之前的new_handler
    std::new_handler set_new_handler(std::new_handler nh)
    {
        std::new_handler oldHandler = currentHandler;
        currentHandler = nh;
        return oldHandler;
    }
    static void *operator new(std::size_t size)
    {
        std::cout << "call my operator new()\n"
                  << size << "\n";
        NewHandlerHolder h(std::set_new_handler(currentHandler));
        return ::operator new(size);
    }

private:
    static std::new_handler currentHandler;
    int value;
};

// static成员必须在类外定义
template <typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = nullptr;

//继承上面的类，则Widget也可以使用
class Widget : public NewHandlerSupport<Widget>
{
private:
    double value;
};
int main()
{
    Widget *wg = new Widget;
    wg->set_new_handler(outOfMemory);
    delete wg;
    return 0;
}
