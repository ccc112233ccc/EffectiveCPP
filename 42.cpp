#include <iostream>
#include <string>
template <typename IterT>
void workWithIter(IterT iter)
{
    using value_type = typename std::iterator_traits<IterT>::value_type;
    // typename std::iterator_traits<IterT>::value_type temp(*iter);
    value_type temp(*iter);
    std::cout << temp;
}

int main()
{
    std::string str{"12345"};
    workWithIter(str.begin());
    return 0;
}
