#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FrequencyPoint
{
public:
    FrequencyPoint(double _begin, double _end, unsigned int _points) : begin(_begin), end(_end), points(_points)
    {
    }
    void out(const char *filename)
    {
        unsigned int steps = (end - begin) / points;
        f.open(filename, ios_base::out);
        for (int i = 0; i < points; i++)
        {
            f << begin + steps * i << ",\n";
        }
        f << endl;
        f.close();
    }

private:
    fstream f;
    double begin;
    double end;
    double points;
};
int main()
{
    FrequencyPoint fp(1.2e9, 1.5e9, 50);
    const char *filename = "frequencyPoint.txt";
    fp.out(filename);

    return 0;
}
