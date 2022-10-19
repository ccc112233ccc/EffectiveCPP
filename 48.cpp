#include <iostream>
#include <string>
template <unsigned n>
struct Factorial
{
    enum val
    {
        value = n * Factorial<n - 1>::value
    };
};
template <>
struct Factorial<0>
{
    enum val
    {
        value = 1
    };
};

using namespace std;
int main()
{
    cout << Factorial<3>::value << endl;

    return 0;
}
