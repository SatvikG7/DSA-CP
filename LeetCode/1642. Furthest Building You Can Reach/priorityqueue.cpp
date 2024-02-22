#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = heights.size();
    for (int i = 0; i < n - 1; i++)
    {
      if (heights[i] < heights[i + 1])
      {
        int diff = heights[i + 1] - heights[i];
        pq.push(diff);
        if (pq.size() > ladders)
        {
          bricks -= pq.top();
          pq.pop();
        }
        if (bricks < 0)
        {
          return i;
        }
      }
    }
    return n - 1;
    }
};

int main()
{
  int n, bricks, ladders;
  cin >> bricks >> ladders;
  vector<int> heights;
  while (cin >> n)
  {
    heights.push_back(n);
  }
  Solution sol;
  cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

  return 0;
}