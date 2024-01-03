#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findMatrix(vector<int> &nums)
  {
    // vector<vector<int>> vec2D;
    unordered_map<int, unordered_map<int, int>> numCountMap;
    int rowPtr = 0;

    for (int num : nums)
    {
      if (numCountMap[rowPtr][num] == 0)
      {
        rowPtr = 0;
      }
      while (numCountMap[rowPtr][num])
      {
        rowPtr++;
      }

      // If the rowPtr exceeds the number of rows in vec2D, add a new row
      // if (rowPtr >= vec2D.size())
      // {
      //   vec2D.push_back({});
      // }

      // Add the current element to the current row
      // vec2D[rowPtr].push_back(num);

      // Update the count of the current element in the map
      numCountMap[rowPtr][num]++;
    }

    vector<vector<int>> result(numCountMap.size());
    for (const auto &entry : numCountMap)
    {
      for (const auto &innerEntry : entry.second)
      {
        result[entry.first].insert(result[entry.first].end(), innerEntry.second, innerEntry.first);
      }
    }

    return result;
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