#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    int idx = -1;
    vector<int> count(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
      count[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
      if (count[s[i] - 'a'] == 1)
      {
        idx = i;
        break;
      }
    }

    return idx;
  }
};

int main()
{
  vector<string> testCases;
  string s;
  while (cin >> s)
  {
    cout << Solution().firstUniqChar(s) << endl;
  }
  return 0;
}