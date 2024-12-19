#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int content = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gp = 0;
    int sp = 0;

    while (gp < g.size() && sp < s.size())
    {
      if (g[gp] <= s[sp])
      {
        content++;
        gp++;
        sp++;
      }
      else
        sp++;
    }
    return content;
  }
};

int main()
{
  int in;
  vector<int> g;
  vector<int> s;

  while (cin >> in)
    g.push_back(in);

  while (cin >> in)
    s.push_back(in);

  Solution sol;
  cout
      << sol.findContentChildren(g, s) << endl;
  return 0;
}