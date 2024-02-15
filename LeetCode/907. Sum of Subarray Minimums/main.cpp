#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      int min = arr[i];
      for (int j = i; j < arr.size(); j++)
      {
        if (arr[j] < min)
        {
          min = arr[j];
        }
        sum += min;
      }
    }
    return sum;
  }
};

int main()
{
  vector<int> arr;
  int n;

  while (cin >> n)
  {
    arr.push_back(n);
  }
  cout << Solution().sumSubarrayMins(arr) << endl;
  return 0;
}