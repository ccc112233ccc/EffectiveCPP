#include <iostream>
#include <string>
namespace WebBrowserStuff
{
    class WebBrowser
    {
    public:
        void clearCache();
        void clearHistory();
        void removeCookies();

        void clearEverything()
        {
            clearCache();
            clearHistory();
            removeCookies();
        }
    };

    void clearBrowser(WebBrowser &wb)
    {
        wb.clearCache();
        wb.clearHistory();
        wb.removeCookies();
    }
}
int main()
{

    return 0;
}
