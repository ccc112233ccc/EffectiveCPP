#include <iostream>
#include <string>
#include <memory>
class Investment
{
public:
    Investment() = default;
    Investment(double _val) : val(_val) {}
    bool isTaxFree() const;
    operator double() const
    {
        return val;
    }

private:
    double val;
};
Investment *creatInvestment();
int main()
{
    std::shared_ptr<Investment> pi1(creatInvestment());

    bool taxable1 = pi1->isTaxFree();
    bool taxable2 = (*pi1).isTaxFree();

    bool taxable3 = pi1.get()->isTaxFree();

    Investment inv = 2;
    double a = inv;
    return 0;
}
