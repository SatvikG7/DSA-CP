#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    int arr[n + 1][2];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < trust.size(); i++)
    {
      arr[trust[i][0]][0]++;
      arr[trust[i][1]][1]++;
    }
    for (int i = 1; i <= n; i++)
    {
      if (arr[i][0] == 0 && arr[i][1] == n - 1)
        return i;
    }
    return -1;
  }
};
int main()
{

  int n;
  cin >> n;
  int size;
  cin >> size;

  vector<vector<int>> trust;
  int a, b;
  while (size--)
  {
    cin >> a >> b;
    trust.push_back({a, b});
  }
  Solution s;
  cout << s.findJudge(n, trust);

  return 0;
}