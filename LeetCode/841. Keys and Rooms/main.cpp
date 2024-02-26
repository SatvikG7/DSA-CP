#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int totalRooms = rooms.size() - 1;
    vector<bool> visited(totalRooms, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
      int currentRoom = q.front();
      q.pop();

      for (int key : rooms[currentRoom])
      {
        if (!visited[key])
        {
          visited[key] = true;
          totalRooms--;
          q.push(key);
        }
      }
    }

    return totalRooms == 0;
  }
};

int main()
{
  vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
  Solution s;
  cout << s.canVisitAllRooms(rooms) << endl;

  return 0;
}