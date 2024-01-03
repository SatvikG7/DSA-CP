#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n(0), k(0);
    cin >> n;
    cin >> k;
    int arr[n];
    for (auto &el : arr)
    {
        cin >> el;
    }

    int ctr = 0;
    if (arr[0] < 0)
    {
        cout << ctr;
        return 0;
    }
    for (auto &el : arr)
    {
        if (el >= arr[k-1] && el > 0)
        {
            ctr++;
        }
        else
        {
            break;
        }
    }
    cout << ctr;
    return 0;
}
