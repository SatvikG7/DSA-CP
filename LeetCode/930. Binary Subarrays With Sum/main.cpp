#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    int n = nums.size();
    int lsum = 0;
    int rsum = 0;
    int l = 0;
    int r = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      lsum += nums[i];
      while (l < i && lsum > goal)
      {
        lsum -= nums[l++];
      }
      rsum += nums[i];
      while (r < i && (rsum > goal || rsum == goal && nums[r] == 0))
      {
        rsum -= nums[r++];
      }
      if (lsum == goal)
      {
        ans += r - l + 1;
      }
    }
    return ans;
  }
};

int main()
{

  int goal;
  cin >> goal;
  vector<int> nums;

  int n;

  while (cin >> n)
  {
    nums.push_back(n);
  }

  Solution *s = new Solution();
  cout << s->numSubarraysWithSum(nums, goal) << endl;

  return 0;
}