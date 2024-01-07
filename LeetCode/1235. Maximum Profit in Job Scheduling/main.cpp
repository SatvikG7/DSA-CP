#include <bits/stdc++.h>
using namespace std;
struct Job
{
  int start;
  int end;
  int profit;
};

bool jobComparator(const Job &a, const Job &b)
{
  return a.end < b.end;
}
class Solution
{
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
  {
    int n = startTime.size();
    vector<Job> jobs;
    for (int i = 0; i < n; ++i)
    {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end(), jobComparator);
    vector<int> dp(n, 0);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; ++i)
    {
      int currentProfit = jobs[i].profit;
      int lastCompatibleJob = binarySearch(jobs, i);
      if (lastCompatibleJob != -1)
      {
        currentProfit += dp[lastCompatibleJob];
      }
      dp[i] = max(dp[i - 1], currentProfit);
    }
    return dp[n - 1];
  }

private:
  int binarySearch(const vector<Job> &jobs, int index)
  {
    int low = 0;
    int high = index - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (jobs[mid].end <= jobs[index].start)
      {
        if (jobs[mid + 1].end <= jobs[index].start)
        {
          low = mid + 1;
        }
        else
        {
          return mid;
        }
      }
      else
      {
        high = mid - 1;
      }
    }

    return -1;
  }
};

int main()
{
  int n;
  vector<int> startTime, endTime, profit;
  while (cin >> n)
  {
    startTime.push_back(n);
  };
  while (cin >> n)
  {
    endTime.push_back(n);
  };
  while (cin >> n)
  {
    profit.push_back(n);
  };

  Solution solution;
  cout << solution.jobScheduling(startTime, endTime, profit) << endl;

  return 0;
}