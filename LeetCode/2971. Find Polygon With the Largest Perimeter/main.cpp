#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), greater<int>());
    long long total_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      total_sum += nums[i];
    }

    for (int i = 0; i < nums.size() - 2; i++)
    {
      if (nums[i] < (total_sum - nums[i]))
      {
        return total_sum;
      }
      else
      {
        total_sum -= nums[i];
      }
    }
    return -1;
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

  Solution s;
  cout << s.largestPerimeter(nums) << endl;
  return 0;
}