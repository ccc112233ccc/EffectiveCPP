#include <iostream>
#include <string>

using std::cout;
using std::endl;
void logCall(const std::string &funcName)
{
    cout << funcName << endl;
}
class Customer
{
public:
    Customer(const Customer &rhs) : name(rhs.name)
    {
    }
    Customer &operator=(const Customer &rhs)
    {
        name = rhs.name;
        return *this;
    }

private:
    std::string name;
};

class PriorityCustomer : public Customer
{
public:
    PriorityCustomer(const PriorityCustomer &rhs)
        : Customer(rhs),
          priority(rhs.priority)
    {
    }
    PriorityCustomer &operator=(const PriorityCustomer &rhs)
    {
        Customer::operator=(rhs); //显示调用Customer的赋值运算符
        priority = rhs.priority;
        return *this;
    }

private:
    int priority;
};

int main()
{

    logCall("Customer copy constructor");

    return 0;
}