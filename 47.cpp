#include <iostream>
#include <string>
using namespace std;

//定义很多哥domyAdvance函数，其最后一个参数为了重载使用，使得主代码能够通过参数找到对应的domyAdvance
template <typename IterT, typename DistT>
void domyAdvance(IterT &iter, DistT d, std::random_access_iterator_tag)
{
    iter += d;
}
template <typename IterT, typename DistT>
void domyAdvacne(IterT &iter, DistT d, std::bidirectional_iterator_tag)
{
    if (d >= 0)
    {
        while (d--)
            ++iter;
    }
    else
    {
        while (d++)
            --iter;
    }
}
template <typename IterT, typename DistT>
void domyAdvance(IterT &iter, DistT d)
{
    if (d < 0)
    {
        throw std::out_of_range("Negative distance");
    }
    while (d--)
        ++iter;
}

// muadvance函数，使得迭代器前进或者后退d个位置
template <typename IterT, typename DistT>
void myadvance(IterT &iter, DistT d)
{
    //根据迭代器的种类判断选取那种类型的函数
    domyAdvacne(iter, d, typename std::iterator_traits<IterT>::iterator_category());
}
int main()
{

    return 0;
}
