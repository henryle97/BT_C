#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("graph.txt");
    if(!file)
    {
        cout << "Error open file!";
        return -1;
    }
    return 0;
}
