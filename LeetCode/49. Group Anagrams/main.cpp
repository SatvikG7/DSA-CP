#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> map;
    for (auto &str : strs)
    {
      string key = str;
      sort(key.begin(), key.end());
      map[key].push_back(str);
    }
    vector<vector<string>> result;
    for (auto &pair : map)
    {
      result.push_back(pair.second);
    }
    return result;
  }
};

int main()
{
  vector<string> strs;
  string str;
  while (cin >> str)
  {
    strs.push_back(str);
  }
  Solution solution;
  vector<vector<string>> result = solution.groupAnagrams(strs);
  for (auto &group : result)
  {
    for (auto &str : group)
    {
      cout << str << " ";
    }
    cout << endl;
  }
  return 0;
}