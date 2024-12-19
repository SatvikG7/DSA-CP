#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  int countStations(vector<int>& stations, double d) {
    int ans = 0;
    for (int i = 0; i < stations.size() - 1; i++) {
      ans += (stations[i + 1] - stations[i]) / d;
    }
    return ans;
  }

  double minmaxGasDist(vector<int>& stations, int K) {
    int N = stations.size();

    double left = 0, right = 1e8;
    while (right - left > 1e-6) {
      double mid = (left + right) / 2;
      int count = countStations(stations, mid);
      if (count > K) {
        left = mid;
      }
      else {
        right = mid;
      }
    }

    return left;
  }

};


int main() {
  int N;
  cin >> N;
  vector<int> stations(N);
  for (int i = 0; i < N; i++) {
    cin >> stations[i];
  }

  int K;
  cin >> K;

  cout << Solution().minmaxGasDist(stations, K) << endl;


  return 0;
}