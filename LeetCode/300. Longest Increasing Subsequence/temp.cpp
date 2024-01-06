#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(vector<int> &nums)
{
  int n = nums.size();
  vector<bool> dp(n, false);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (nums[i] > nums[j] && !dp[j])
      {
        dp[i] = true;
        break;
      }
    }
  }
  int maxLength = 0;
  for (int i = 0; i < n; i++)
  {
    if (dp[i])
    {
      maxLength++;
    }
  }
  return maxLength;
}

int main()
{
  int n;
  vector<int> nums;
  while (cin >> n)
  {
    nums.push_back(n);
  }

  cout << longestIncreasingSubsequence(nums);
  return 0;
}