#include <iostream>
#include <string>
#include <vector>
namespace WidgetStuff
{
    template <typename T>
    class WidgetImpl
    {
    private:
        std::vector<double> v;
    };
    template <typename T>
    class Widget
    {
    public:
        Widget &operator=(const Widget &rhs)
        {
            *pImpl = *(rhs.pImpl);
            return *this;
        }
        void swap(Widget &rhs)
        {
            std::cout << "innner swap" << std::endl;
            using std::swap;
            swap(pImpl, rhs.pImpl);
        }

    private:
        WidgetImpl<double> *pImpl;
    };
    template <typename T>
    void swap(Widget<T> &lhs, Widget<T> &rhs)
    {
        std::cout << "my swap function" << std::endl;
        lhs.swap(rhs);
    }
}

int main()
{
    using std::swap;
    using WidgetStuff::Widget;
    Widget<double> a, b;
    std::swap(a, b);
    return 0;
}
