#include <iostream>
#include <string>
#include <memory>

class Widget
{
public:
    Widget()
    {
        std::cout << "Widget constructor" << std::endl;
    }
    ~Widget()
    {
        std::cout << "Widget destructor" << std::endl;
    }
};
int main()
{
    std::shared_ptr<Widget> w1(new Widget);
    std::shared_ptr<Widget> w2(w1);

    return 0;
}
