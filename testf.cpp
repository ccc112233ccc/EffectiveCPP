#include <fstream>
using namespace std;

int main()
{
    fstream fs;
    fs.open("myfile.txt", ios::out);

    fs << "more strings " << endl;
    fs.close();
    return 0;
}