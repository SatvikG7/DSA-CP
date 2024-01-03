#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfBeams(vector<string> &bank)
  {
    int count = 0;
    int nRow = bank.size();
    if (nRow <= 1)
      return 0;
    int nCol = bank[0].size();
    int iptr = 0, jptr = 1;
    while (iptr < jptr && jptr < nRow)
    {
      int counti = 0, countj = 0;
      for (int i = 0; i < nCol; i++)
      {
        if (bank[iptr][i] == '1')
          counti++;

        if (bank[jptr][i] == '1')
          countj++;
      }

      if (counti == 0 || countj == 0)
      {
        if (counti == 0 && countj == 0)
        {
          iptr = jptr + 1;
          jptr += 2;
          continue;
        }
        else if (!counti)
        {
          iptr++;
          if (iptr == jptr)
            jptr++;
          continue;
        }
        else if (!countj)
        {
          jptr++;
          continue;
        }
      }
      else
      {
        iptr = jptr;
        jptr++;
      }

      count += counti * countj;
    }

    return count;
  }
};

int main()
{
  vector<string> bank;
  string r;
  while (cin >> r)
  {
    bank.push_back(r);
  }

  // for(auto i: bank) cout << i << endl;

  Solution solution;
  cout << solution.numberOfBeams(bank) << endl;

  return 0;
}