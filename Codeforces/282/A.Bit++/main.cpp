#include <iostream>
using namespace std;

int main()
{
    int n;
    string in;
    cin >> n;
    int ctr(0);

    for (int i = 0; i < n; i++)
    {
        cin >> in;
        if (in == "X++")
        {
            ctr++;
        }
        else if (in == "X--")
        {
            ctr--;
        }
        else if (in == "++X")
        {
            ++ctr;
        }
        else if (in == "--X")
        {
            --ctr;
        }
        else
        {
            return -1;
        }
    }
    cout << ctr;
    return 0;
}