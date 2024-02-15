#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int dfs(int m, int n, int remMoves, int cr, int cc)
  {
    if (cr < 0 || cr >= m || cc < 0 || cc >= n)
      return 1;
    if (remMoves == 0)
      return 0;

    int ans = 0;
    return dfs(m, n, remMoves - 1, cr - 1, cc) +
           dfs(m, n, remMoves - 1, cr + 1, cc) +
           dfs(m, n, remMoves - 1, cr, cc - 1) +
           dfs(m, n, remMoves - 1, cr, cc + 1);
  }

public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
  {
    return dfs(m, n, maxMove, startRow, startColumn);
  }
};

int main()
{
  int m, n, maxMove, startRow, startColumn;

  Solution solution;

  while (cin >> m >> n >> maxMove >> startRow >> startColumn)
  {
    cout << solution.findPaths(m, n, maxMove, startRow, startColumn) << endl;
  }
  return 0;
}