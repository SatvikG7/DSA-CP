#include <iostream>
using namespace std;

int main()
{
    int a[5][5];
    int in;
    int ix, iy;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> in;
            a[i][j] = in;
            if (in == 1)
            {
                ix = j + 1;
                iy = i + 1;
            }
        }
    }

    cout << abs(3 - iy) + abs(3 - ix);
    return 0;
}