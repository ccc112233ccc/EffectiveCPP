#include <iostream>
#include <string>
class Window
{
public:
    std::string name() const;
    virtual void display() const
    {
        std::cout << "Window display()" << std::endl;
    }
};
class WindowWithScrollBars : public Window
{
public:
    virtual void display() const
    {
        std::cout << "WindowWithScrollBars display()" << std::endl;
    }
};

void display(Window w)
{
    w.display();
}
int main()
{
    WindowWithScrollBars w;
    display(w);

    return 0;
}
