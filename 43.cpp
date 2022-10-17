#include <iostream>
#include <string>
class CompanyA
{
public:
    void sendMessage(){};
};
class CompanyB
{
public:
    void sendMessage(){};
};

template <typename Company>
class SendMessage
{
public:
    void sendClear()
    {
        Company c;
        c.sendMessage();
    }
};

template <>
class SendMessage<CompanyA>
{
public:
    void sendSecret()
    {
    }
};
template <typename Company>
class LoggingSendMessage : public SendMessage<Company>
{
public:
    void sendClearMsg()
    {
        SendMessage<Company>::sendClear();
    }
};
int main()
{
    SendMessage<CompanyB> sm;
    sm.sendClear();

    return 0;
}
