#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int nos = m * n;
    if (m % 2 == 0 && n % 2 == 0)
    {
        cout << nos / 2;
        return 0;
    }
    else if (m % 2 != 0 && n % 2 != 0)
    {
        cout << (nos - 1) / 2;
        return 0;
    }
    else
    {
        cout << nos / 2;
        return 0;
    }

    return 0;
}