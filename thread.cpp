#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include <chrono>
#include <mutex>
#include <vector>
std::mutex m;

struct lockostream
{
    std::lock_guard<std::mutex> l;
    lockostream() : l(m) {}
};

std::ostream &operator<<(std::ostream &os, lockostream const &l)
{
    return os;
}

void work()
{
    std::cout << lockostream() << "id: " << std::this_thread::get_id() << ", I am working" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    std::thread t(work);
    work();
    t.join();
    return 0;
}
