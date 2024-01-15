#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches)
  {
    unordered_map<int, int[2]> players;
    for (int i = 0; i < matches.size(); i++)
    {
      players[matches[i][0]][0]++;
      players[matches[i][1]][1]++;
    }

    vector<vector<int>> winners(2);
    for (auto player : players)
    {
      if (player.second[1] == 0)
      {
        winners[0].push_back(player.first);
      }
      if (player.second[1] == 1)
      {
        winners[1].push_back(player.first);
      }
    }
    sort(winners[0].begin(), winners[0].end());
    sort(winners[1].begin(), winners[1].end());
    return winners;
  }
};

int main()
{

  int n = 0;
  cin >> n;
  vector<vector<int>> matches(n, vector<int>(2, 0));
  for (int i = 0; i < n; i++)
  {
    cin >> matches[i][0] >> matches[i][1];
  }
  Solution solution;
  vector<vector<int>> winners = solution.findWinners(matches);
  for (int i = 0; i < winners[0].size(); i++)
  {
    cout << winners[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i < winners[1].size(); i++)
  {
    cout << winners[1][i] << " ";
  }
  return 0;
}