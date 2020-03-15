#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
  ios_base::sync_with_stdio(false);
  LL n, a[2007], pre[5007], dp[5007];
  memset(pre, 0, sizeof pre);
  memset(dp, 0, sizeof dp);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  LL way = n * (n - 1);
  way /= 2LL;
  way = way * way * way;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      pre[a[i] - a[j]]++;
    }
  }
  for(int i = 1; i <= 5000; i++) {
    if(!pre[i]) continue;
    for(int j = i; j <= 5000; j++) {
      dp[j] = dp[j] + 1LL* pre[i] * pre[j - i]; 
    }
  }
  long double ans = 0.0;
  long long total = 0, prev = 0;
  for(int i = 1; i <= 5000; i++) {
    total += prev * pre[i];
    prev += dp[i];
  }
  ans = 1.0 * total / way;
  cout << setprecision(7) << fixed << ans << endl;
  return 0;
} 
