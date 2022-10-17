#include <iostream>
#include <string>
class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1);
    int numerator() const;
    int denominator() const;

    // const Rational operator*(const Rational &rhs) const;
};

const Rational operator*(const Rational &lhs, const Rational &rhs);
int main()
{
    Rational oneEighth(1, 8);
    Rational oneHalf(1, 2);

    Rational result = oneEighth * oneHalf; //没问题
    result = result * 2;                   //没问题
    result = 2 * result;                   //报错

    return 0;
}
