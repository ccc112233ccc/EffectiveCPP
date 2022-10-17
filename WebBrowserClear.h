#pragma once

#include "WebBrowser.h"
namespace WebBrowserStuff
{

    inline void clearBrowser(WebBrowser &wb)
    {
        wb.clearCache();
        wb.clearHistory();
        wb.removeCookies();
    }
}