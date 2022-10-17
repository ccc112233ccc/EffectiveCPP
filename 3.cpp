#include <string>
#include <string.h>
#include <iostream>
using namespace std;
class CTextBlock
{
public:
    CTextBlock(const CTextBlock &) = delete;

    CTextBlock(const char *str)
    {
        pText = (char *)malloc(sizeof(char) * strlen(str));
        strcpy(pText, str);
    };
    char &operator[](std::size_t position) const
    {
        return pText[position];
    }
    CTextBlock &operator=(const CTextBlock &) = delete;
    ~CTextBlock()
    {
        free(pText);
    }
    char *pText;
};

int main()
{

    const CTextBlock cctb("Hello");
    cout << cctb.pText << endl;
    cctb[0] = 'J';

    cout << cctb.pText << endl;
    return 0;
}