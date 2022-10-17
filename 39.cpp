#include <iostream>
#include <string>
class Empty
{
};
class HoldsAnInt
{
private:
    int x;
    Empty e;
};
int main()
{
    using namespace std;
    cout << sizeof(HoldsAnInt) << endl;

    return 0;
}
