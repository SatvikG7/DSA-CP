#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    vector<int> diff;
    int n = heights.size();
    for (int i = 0; i < n - 1; i++)
    {
      if (heights[i] < heights[i + 1])
      {
        diff.push_back(heights[i + 1] - heights[i]);
      }
      else
      {
        diff.push_back(0);
      }
    }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
      // cout << "i: " << i << endl;
      int l = ladders;
      int b = bricks;
      vector<int> temp(diff.begin(), diff.begin() + i);
      sort(temp.begin(), temp.end(), greater<int>());
      for (int j = 0; j < temp.size(); j++)
      {
        if (l > 0)
        {
          // cout << "ladder" << endl;
          l--;
        }
        else
        {
          // cout << "using " << temp[j] << " bricks" << endl;
          b -= temp[j];
          // cout << "left bricks: " << b << endl;
        }

        if (b < 0)
        {
          return i - 1;
        }
      }
      // cout << endl;
    }
    return n - 1;
  }
};

int main()
{
  int n, bricks, ladders;
  cin >> bricks >> ladders;
  vector<int> heights;
  while (cin >> n)
  {
    heights.push_back(n);
  }
  Solution sol;
  cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

  return 0;
}