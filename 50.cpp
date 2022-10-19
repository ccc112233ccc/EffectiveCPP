#include <iostream>
#include <string>

class Base
{
private:
    static int value;
};
class Derived : public Base
{
private:
};
int main()
{
    std::cout << sizeof(std::size_t) << "\n";
    return 0;
}
