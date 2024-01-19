#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int solve(vector<vector<int>> &matrix, int row, int col)
  {

    if (row == matrix.size() - 1)
      return matrix[row][col];

    if (col == 0)
    {
      return matrix[row][col] + min(solve(matrix, row + 1, col), solve(matrix, row + 1, col + 1));
    }

    if (col == matrix.size() - 1)
    {
      return matrix[row][col] + min(solve(matrix, row + 1, col - 1), solve(matrix, row + 1, col));
    }

    return matrix[row][col] + min(solve(matrix, row + 1, col - 1), min(solve(matrix, row + 1, col), solve(matrix, row + 1, col + 1)));
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int minimum = INT_MAX;

    for (int i = 0; i < matrix.size(); i++)
    {
      minimum = min(minimum, solve(matrix, 0, i));
    }

    return minimum;
  }
};

int main()
{
  Solution sol;
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];

  cout << sol.minFallingPathSum(matrix) << endl;

  return 0;
}