#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "babad";
  int l = s.length();
  int dp[l][l];

  // initialize dp
  std::memset(dp, 0, sizeof(dp));

  for (int i = 0; i < l; i++) {
    dp[i][i] = 1;
  }

  for (int i = 1; i < l; i++) {
    for (int j = 0; i + j < l; j++) {
      dp[j][j + i] = (s[j] == s[j + i] && (
        (j + 1 <= j + i - 1)
        ? dp[j + 1][j + i - 1]
        : true
        )
        );
    }
  }

  // print dp

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      cout << "i: " << i << " j: " << j << " dp: " << dp[i][j] << "\n";
    }
    cout << endl;
  }



  return 0;
}