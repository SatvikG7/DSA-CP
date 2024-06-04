#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDepth(string s)
  {
    int maxDepth = 0;
    int currentDepth = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        currentDepth++;
        maxDepth = max(maxDepth, currentDepth);
      }
      else if (s[i] == ')')
      {
        currentDepth--;
      }
    }
    return maxDepth;
  }
};

int main()
{
  string s = "(1+(2*3)+((8)/4))+1";
  Solution sol;
  cout << sol.maxDepth(s) << endl;

  return 0;
}