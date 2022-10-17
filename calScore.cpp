#include <iostream>
#include <string>
int main()
{
    int loot[4] = {1445, 483, 47, 57};
    int score[4] = {1, 10, 20, 50};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += loot[i] * score[i];
    }
    std::cout << "all score: " << sum << std::endl;
    std::cout << "may rolls: " << (double)sum / 3300 << std::endl;
    return 0;
}
