#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int pos = 0;
    int neg = 1;
    vector<int> res = {0, 0};
    for (auto &num : nums)
    {

      if (num > 0)
      {
        if (res.size()-1 < pos)
        {
          res.push_back(0);
          res.push_back(0);
          res[pos] = num;
        }
        else
        {
          res[pos] = num;
        }
        pos += 2;
      }
      else
      {
        if (res.size() < neg)
        {
          res.push_back(0);
          res.push_back(0);
          res[neg] = num;
        }
        else
        {
          res[neg] = num;
        }
        neg += 2;
      }
    }
    return res;
  }
};
int main()
{
  vector<int> nums;
  int n;
  while (cin >> n)
  {
    nums.push_back(n);
  }

  Solution s;
  vector<int> res = s.rearrangeArray(nums);
  for (auto &num : res)
  {
    cout << num << " ";
  }

  return 0;
}