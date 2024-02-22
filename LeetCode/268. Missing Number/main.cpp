#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
      sum -= nums[i];
    }
    return sum;
  }
};

int main()
{
  vector<int> nums;
  int in;
  while (cin >> in)
  {
    nums.push_back(in);
  }
  Solution sol;
  cout << sol.missingNumber(nums) << endl;
  return 0;
}