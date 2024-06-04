#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = 0, n2 = 0;
    while (n1 < nums1.size() && n2 < nums2.size())
    {
      if(nums1[n1] == nums2[n2]){
        return nums1[n1];
      }
      if(nums1[n1] < nums2[n2]){
        n1++;
      }else{
        n2++;
      }
    }
    return -1;
  }
};
int main()
{
  int n1, n2;
  cin >> n1;
  vector<int> v1(n1);
  for (int i = 0; i < n1; i++)
  {
    cin >> v1[i];
  }
  cin >> n2;
  vector<int> v2(n2);
  for (int i = 0; i < n2; i++)
  {
    cin >> v2[i];
  }

  Solution s;
  cout << s.getCommon(v1, v2) << endl;

  return 0;
}