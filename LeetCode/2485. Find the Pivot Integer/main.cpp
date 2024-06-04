#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int pivotInteger(int n)
  {
    int totalsum = n * (n + 1) / 2;
    int lsum = totalsum;
    int rsum = 0;
    for (int i = n; i >= 1; i--)
    {
      rsum = totalsum - lsum + i;

      if (lsum == rsum)
      {
        return i;
      }
      lsum -= i;
    }

    return -1;
  }
};
int main()
{
  int n;
  cin >> n;
  Solution *s = new Solution();
  cout << s->pivotInteger(n) << endl;

  return 0;
}