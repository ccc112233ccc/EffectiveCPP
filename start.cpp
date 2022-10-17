

#include <iostream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <fstream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
int main()
{
    using std::cout;
    using std::endl;
    // SetCursorPos(1707, 1067);
    std::filesystem::path p = std::filesystem::current_path();
    // p.append("03HomeNew.wav");
    // cout << p << endl;
    //  p.string().c_str();
    //  const char *file_name = p.string().c_str();
    //  PlaySoundA("03HomeNew.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    for (const std::filesystem::path &i : std::filesystem::directory_iterator(p))
    {
        if (i.extension() == ".wav")
        {
            auto file = i.string().c_str();
            PlaySoundA(i.string().c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            std::cout << "Now is playing "
                      << file << endl;
        }
    }
    getchar();
    return 0;
}