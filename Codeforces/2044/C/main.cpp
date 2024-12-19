#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int ans = 0;

    ans += min(m, a);
    ans += min(m, b);

    int remaining = 2 * m - ans;
    ans += min(remaining, c);

    cout << ans << endl;
  }

  return 0;
}