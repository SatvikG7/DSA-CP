#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSteps(string s, string t)
  {
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
      if (count[i] > 0)
        ans += count[i];
    }
    return ans;
  }
};

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    string t;
    cin >> s >> t;
    cout << Solution().minSteps(s, t) << endl;
  }
  return 0;
}