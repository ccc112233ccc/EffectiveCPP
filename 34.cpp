#include <iostream>
#include <string>
class Shape
{
public:
    virtual void draw() const = 0;
};
class Rectangle : public Shape
{
public:
    virtual void draw() const
    {
        std::cout << "Rectangle draw()" << std::endl;
    }
};

void Shape::draw() const
{
    //虽然是pure virtual,但是可以为其提供一个定义
    std::cout << "Shape draw()" << std::endl;
}

int main()
{
    Shape *ps = new Rectangle;
    ps->draw();        // Rectangle draw();
    ps->Shape::draw(); // 调用纯虚函数的定义时候需要加上类型
    return 0;
}
