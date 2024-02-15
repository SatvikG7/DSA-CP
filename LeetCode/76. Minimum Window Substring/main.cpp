#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int size_s = s.size();
    int size_t = t.size();
    if (size_s < size_t)
      return "";

    int rp = 0, lp = 0;

    int min_len = INT_MAX;
    int start = 0;
    int end = 0;
    unordered_map<char, int> map;
    for (char c : t)
      map[c]++;

    int map_size = map.size();

    while (lp < size_s)
    {
      rp = lp;
      unordered_map<char, int> t_map = map;
      int required = map_size;

      while (rp < size_s)
      {
        if (t_map.find(s[rp]) != t_map.end())
        {
          t_map[s[rp]]--;
          if (t_map[s[rp]] == 0)
            required--;
          if (required == 0)
          {
            if (min(min_len, rp - lp + 1) < min_len)
            {
              min_len = min(min_len, rp - lp + 1);
              start = lp;
              end = rp;
            }
            break;
          }
        }
        rp++;
      }
      lp++;
    }
    return min_len == INT_MAX ? "" : s.substr(start, end - start + 1);
  }
};

int main()
{

  string s;
  string t;

  cin >> s >> t;

  Solution sol;
  cout << sol.minWindow(s, t) << endl;

  return 0;
}