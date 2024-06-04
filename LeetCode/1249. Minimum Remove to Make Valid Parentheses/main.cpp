#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        st.push(i);
      }
      else if (s[i] == ')')
      {
        if (!st.empty())
        {
          st.pop();
        }
        else
        {
          s[i] = '*';
        }
      }
    }

    while (!st.empty())
    {
      s[st.top()] = '*';
      st.pop();
    }

    string result = "";
    for (int i = 0; i < n; i++)
    {
      if (s[i] != '*')
      {
        result += s[i];
      }
    }

    return result;
  }
};
int main()
{
  vector<string> inputs;
  string s;
  while (cin >> s)
  {
    inputs.push_back(s);
  }

  Solution sol;
  for (string s : inputs)
  {
    cout << sol.minRemoveToMakeValid(s) << endl;
  }

  return 0;
}