#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(vector<vector<char>> &board, int i, int j, string &word, int k)
  {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
    {
      return false;
    }

    if (k == word.size() - 1)
    {
      return true;
    }

    char tmp = board[i][j];
    board[i][j] = '0';

    bool res = dfs(board, i + 1, j, word, k + 1) || dfs(board, i - 1, j, word, k + 1) || dfs(board, i, j + 1, word, k + 1) || dfs(board, i, j - 1, word, k + 1);

    board[i][j] = tmp;

    return res;
  }

  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
        {
          return true;
        }
      }
    }

    return false;
  }
};

int main()
{

  vector<vector<char>> board;
  board.push_back({'A', 'B', 'C', 'E'});
  board.push_back({'S', 'F', 'C', 'S'});
  board.push_back({'A', 'D', 'E', 'E'});

  string word = "ABCCED";

  Solution sol;
  cout << sol.exist(board, word) << endl;

  return 0;
}