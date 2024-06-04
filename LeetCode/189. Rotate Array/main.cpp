#include <bits/stdc++.h>
using namespace std;
#define print cout
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int prev_value;
    int j = 0;
    int value_to_be_inserted = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
      cout << "i: " << i << " || ";
      for (auto n : nums)
      {
        cout << n << " ";
      }
      cout << "\n";
      prev_value = nums[(j + k) % nums.size()];
      nums[(j + k) % nums.size()] = value_to_be_inserted;
      value_to_be_inserted = prev_value;
      j = (j + k) % nums.size();
      cout << "i: " << i << " || ";
      for (auto n : nums)
      {
        cout << n << " ";
      }
      cout << "\n";

      cout << "prev_value: " << prev_value << "\n";
      cout << "value_to_be_inserted: " << value_to_be_inserted << "\n";
      cout << "\n";
    }

  }
};

int main()
{
  vector<int> tc({-1, -100, 3, 99});
  vector<int> *tcp;
  tcp = &tc;
  Solution sol;
  sol.rotate(tc, 2);

  for (auto n : tc)
  {
    cout << n << " ";
  }

  return 0;
}