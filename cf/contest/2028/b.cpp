#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
using ll = long long;

void solve() {
  ll n, b, c; cin >> n >> b >> c;
  if (b == 0) {
    if (n > c + 2) {
      cout << -1 << '\n';
    }
    else if (c <= n - 1) {
      cout << n - 1 << '\n';
    } else {
      cout << n << '\n';
    }
  } else {
    ll cnt = 0;
    if (c <= n - 1) {
      cnt = 1 + (n - 1 - c) / b;
    }
    cout << n - cnt << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}