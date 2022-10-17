#include <iostream>
#include <string>
class Widget
{
public:
    explicit Widget(int size) : val(size) {}
    int GetVal() const
    {
        return doVal();
    }

protected:
    int val;

private:
    virtual int doVal() const
    {
        return val;
    }
};
class PWidget : public Widget
{
public:
    PWidget(int size) : Widget(size) {}

private:
    virtual int doVal() const
    {
        return val * 2;
    }
};
void doSomeWork(const Widget &w);

int main()
{
    PWidget foo(5);
    std::cout << foo.GetVal() << "\n";
    return 0;
}
