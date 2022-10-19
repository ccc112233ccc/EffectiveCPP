#include <iostream>

//一个继承体系
class Top
{
};
class Middle : public Top
{
};
class Bottom : public Middle
{
};

//一个智能指针模板
template <typename T>
class SmartPtr
{
public:
    explicit SmartPtr(T *realPtr){};
    //注意这个时候只有在U类型的指针可以隐式转化成T时候才能通过编译
    template <typename U>
    SmartPtr(const SmartPtr<U> &other) : heldPtr(other.get())
    {
        std::cout << "templates copying funtion" << std::endl;
    };
    T *get() const
    {
        return heldPtr;
    }

private:
    T *heldPtr;
};

int main()
{

    //对于类来说，其基类指针可以指向派生类对象：
    Top *pt1 = new Middle; //将Middle*转变为Top*
    Top *pt2 = new Bottom; //将Bottom*转变为Top*
    const Top *pct2 = pt1; //将Top*转变为cosnt Top*

    //对于由智能指针管理的对象来说，只有定义成员模板函数（具体为泛化的拷贝构造函数）时候才能通过编译
    SmartPtr<Top> spt1 = SmartPtr<Middle>(new Middle);
    SmartPtr<Top> spt2 = SmartPtr<Bottom>(new Bottom);
    SmartPtr<const Top> spct2 = SmartPtr<Top>(new Top);

    //需要注意的是，泛化的拷贝构造函数并不会阻止编译器生成它们自己的拷贝构造函数。
    SmartPtr<Top> spt3 = SmartPtr<Top>(new Top);

    return 0;
}