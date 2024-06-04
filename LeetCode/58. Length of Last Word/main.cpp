#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int i = s.size() - 1;
    int ans = 0;

    while (i >= 0 && s[i] == ' ')
    {
      i--;
    }

    while (i >= 0 && s[i] != ' ')
    {
      ans++;
      i--;
    }

    return ans;
  }
};

int main()
{
  string s = "Hello World";
  Solution sol;
  cout << sol.lengthOfLastWord(s) << endl;

  return 0;
}