#include <iostream>
#include <memory>
using std::cout;
using std::endl;
class mymutex
{
public:
    mymutex() = default;
};
void unlock(mymutex *m)
{
    cout << "my mutex is unlocked" << endl;
}

class Lock
{
public:
    explicit Lock(mymutex *pm) : mutexPtr(pm, unlock)
    {

        cout << "mutex is locked" << endl;
    }

private:
    std::shared_ptr<mymutex> mutexPtr;
};
int main()
{
    mymutex m;
    Lock m1(&m);
    Lock m2(m1);

    return 0;
}