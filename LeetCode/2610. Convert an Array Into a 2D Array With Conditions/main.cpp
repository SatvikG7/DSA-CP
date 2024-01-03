#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findMatrix(vector<int> &nums)
  {
    vector<vector<int>> vec2D;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int rowPtr = 0;

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
      {
        // If the current element is equal to the previous one, move to the next row
        rowPtr++;
      }
      else
      {
        // If the current element is not equal to the previous one, reset the rowPtr
        rowPtr = 0;
      }

      // If the rowPtr exceeds the number of rows in vec2D, add a new row
      if (rowPtr >= vec2D.size())
      {
        vec2D.emplace_back(vector<int>({}));
      }

      // Add the current element to the current row
      vec2D[rowPtr].emplace_back(nums[i]);
    }
    return vec2D;
  }
};

int main()
{
  int a;
  vector<int> v;
  while (cin >> a)
  {
    v.emplace_back(a);
  }

  Solution solution;
  vector<vector<int>> vec2D = solution.findMatrix(v);
  for (auto q : vec2D)
  {
    for (auto it : q)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}