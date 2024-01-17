#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    vector<int> arrmap(2001, 0);
    for (int x : arr)
    {
      arrmap[x + 1000]++;
    }
    sort(arrmap.begin(), arrmap.end());
    for (int i = 1; i < arrmap.size(); i++)
    {
      if (arrmap[i] != 0 && arrmap[i] == arrmap[i - 1])
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<int> arr;
  int n;
  while (cin >> n)
  {
    arr.push_back(n);
  }

  Solution s;
  cout << s.uniqueOccurrences(arr) << endl;
  return 0;
}