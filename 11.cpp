#include <iostream>
#include <string>
using std::cout;
using std::endl;
class Widget
{
public:
    Widget(double _val) : val(_val) {}
    void swap(Widget &rhs)
    {
        double temp = 0;
        temp = rhs.val;
        rhs.val = val;
        val = temp;
    }
    Widget &operator=(const Widget &rhs)
    {
        cout << "Widget &operator=(const Widget &rhs)" << endl;
        if (this == &rhs)
            return *this;

        Widget temp(rhs);
        swap(temp);
        return *this;
    }

    Widget &operator=(Widget rhs)
    {
        cout << "Widget &operator=(Widget rhs)" << endl;

        swap(rhs);
        return *this;
    }

private:
    double val;
};

int main()
{
    Widget d1(5), d2(6);

    d1 = d2;

    return 0;
}
