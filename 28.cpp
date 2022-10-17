#include <iostream>
#include <string>
#include <memory>
class Point
{
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y)
    {
    }
    int x;
    int y;
    ~Point()
    {
        std::cout << "Point destructor" << std::endl;
    }
};
class RectData
{
public:
    RectData()
    {
        ulhc = new Point;
        lrhc = new Point;
    }
    Point *ulhc; // upper left hand corner
    Point *lrhc; // lower right hand corner
    ~RectData()
    {
        delete ulhc;
        delete lrhc;
    }
};
class Rectangle
{
public:
    Rectangle() : pData(new RectData)
    {
    }

private:
    std::shared_ptr<RectData> pData;
};

std::shared_ptr<Point> pass()
{
    auto foo = std::make_shared<Point>();
    return foo;
}
int main()
{

    std::shared_ptr<Point> foo(pass());

    std::cout << "over"
              << "\n";
    return 0;
}
