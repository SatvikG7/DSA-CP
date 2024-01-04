#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    map<int, int> mp;
    for (int num : nums)
    {
      mp[num]++;
    }

    int ans = 0;

    for (auto it : mp)
    {
      if (it.second == 1)
      {
        return -1;
      }

      if (it.second % 3 == 0)
      {
        ans += it.second / 3;
      }
      else
      {
        ans += int(it.second / 3) + 1;
      }
    }
    return ans;
  }
};

int main()
{

  int in;
  vector<int> nums;
  while (cin >> in)
  {
    nums.push_back(in);
  }

  Solution solution;
  cout << solution.minOperations(nums) << endl;
  return 0;
}