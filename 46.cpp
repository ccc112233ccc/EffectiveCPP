#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Rational; //前向声明

template <typename T>

const Rational<T> doMultiply(const Rational<T> &lhs, const Rational<T> &rhs)
{
    return Rational<T>(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
//一个表示有理数的模板类
template <typename T>
class Rational
{
public:
    Rational(const T &_numerator = 0, const T &_denominator = 1) : nume(_numerator), deno(_denominator){};
    const T numerator() const { return nume; };
    const T denominator() const { return deno; };

    //在模板内部定义非成员函数，即友元函数，这样可以使得此函数会被具现化出来
    //加不加<T>无所谓，因为具现化出来的函数已经确定了肯定是对应的类型。
    friend Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        //必须携程内联的形式，如果定义在外部则无法链接成功，因为外部无法知道T的类型，
        //自然也无法具现出相应的函数，但是为了避免代码膨胀可以使用辅助函数
        return doMultiply(lhs, rhs);
    }

private:
    T nume;
    T deno;
};

int main()
{
    Rational<int> oneHalf(1, 2);

    Rational<int> result = oneHalf * 2;

    return 0;
}
