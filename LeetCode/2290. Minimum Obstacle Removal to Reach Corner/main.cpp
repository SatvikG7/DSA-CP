#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;

    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    dq.push_front({ 0, 0 });
    dist[0][0] = 0;

    while (!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();

      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          int newDist = dist[x][y] + grid[nx][ny];
          if (newDist < dist[nx][ny]) {
            dist[nx][ny] = newDist;

            if (grid[nx][ny] == 0) {
              dq.push_front({ nx, ny });
            }
            else {
              dq.push_back({ nx, ny });
            }
          }
        }
      }
    }

    return dist[m - 1][n - 1];
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid = { {0, 1, 1}, {1, 1, 0}, {1, 1, 0} };
  cout << s.minimumObstacles(grid) << endl;
  return 0;
}