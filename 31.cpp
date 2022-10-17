#include <string> //标准程序库组件不该被前置声明
#include <memory>
#include <iosfwd>
class PersonImpl; // Person实现类的前置声明
class Date;       // Peron接口用到的class前置声明
class Address;

class Person
{
public:
    Person(const std::string &name, const Date &birthday, const Address &addr);
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:
    std::shared_ptr<PersonImpl> pImpl; //指针，指向实现
};

//在这里，Person内只有一个指针成员，指向其实现类，这种设计常被
//称为pimpl idiom(pointer to implementation)，这样实现的话这个
//类就完全与实现细节分离了，那些实现的修改都不需要Person客户端重新
//编译。
