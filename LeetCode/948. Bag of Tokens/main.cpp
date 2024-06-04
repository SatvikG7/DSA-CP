#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int maxScore = 0;
    int i = 0;
    int j = tokens.size() - 1;

    while (i <= j)
    {

      if (power >= tokens[i])
      {
        power -= tokens[i];
        score++;
        i++;
        maxScore = max(maxScore, score);
      }
      else if (score > 0)
      {
        power += tokens[j];
        score--;
        j--;
      }
      else
      {
        break;
      }
    }
    return maxScore;
  }
};

int main()
{
  vector<int> tokens;
  int power;
  int t;
  cin >> power;

  while (cin >> t)
  {
    tokens.push_back(t);
  }
  Solution s;
  cout << s.bagOfTokensScore(tokens, power) << endl;

  return 0;
}