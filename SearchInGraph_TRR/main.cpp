#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <string> edge[100];
/* Xay dung do thi */

// Doc file
void readFile(string filePath)
{
    ifstream file(filePath);

    if (file.fail())
    {
        cout << "Can't open file !" <<endl;
        return;
    }

    string getWord;
    while (file >> getWord)
    {

    }


}
/* Dem so thanh phan liên thông */

/* Duong di ngan nhat tu u den v */

int main()
{
    string filePath = "sgb-words"
    return 0;
}
