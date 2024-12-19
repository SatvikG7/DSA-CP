// #include <bits/stdc++.h>
// using namespace std;

// // y/x = k^n
// // l1 <= x <= r1
// // l2 <= y <= r2
// // n >= 0

// // log(y) = log(x) + n * log(k)
// // log(l2) <= log(y) <= log(r2)
// // log(l2) <= log(x) + n * log(k) <= log(r2)
// // log(l2) - log(x) <= n * log(k) <= log(r2) - log(x)
// // (log(l2) - log(x)) / log(k) <= n <= (log(r2) - log(x)) / log(k)

// // count number of n that satisfy the above condition


// int main() {
//   int t;
//   cin >> t;

//   while (t--) {
//     int k, l1, r1, l2, r2;
//     cin >> k >> l1 >> r1 >> l2 >> r2;
//     int cnt = 0;

//     double log_l2 = log2(l2);
//     double log_r2 = log2(r2);
//     double log_k = log2(k);

//     for (int x = l1; x <= r1; x++) {
//       double n1 = (log_l2 - log2(x)) / log_k;
//       double n2 = (log_r2 - log2(x)) / log_k;
//       cnt += max(0, (int)(floor(n2) - ceil(n1) + 1));
//     }

//     cout << cnt << endl;

//   }

//   return 0;
// }


// y/x = k^n
// y = x * k^n



#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    long long cnt = 0;
    long long power = 1;

    while (power <= r2) {
      long long x_min = max(l1, (l2 + power - 1) / power);
      long long x_max = min(r1, r2 / power);

      if (x_min <= x_max) {
        cnt += (x_max - x_min + 1);
      }

      if (power > r2 / k) break;
      power *= k;
    }

    cout << cnt << endl;
  }
  return 0;
}
