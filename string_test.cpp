#include <iostream>
#include <string>
#include <filesystem>
int main()
{
    using namespace std;
    using namespace filesystem;
    path p = current_path();

    auto sptr = p.string().c_str();

    cout << "this is OK: " << p.string().c_str() << endl;
    cout << "After operator=  : " << sptr << endl;
    cout << "convert to const char* :" << (const char *)p.c_str() << endl;
}