#include <iostream>
#include <string>
int main()
{
    std::string *stringArray = new std::string[100];
    delete[] stringArray;

    std::string *string = new std::string;
    delete string;

    return 0;
}
