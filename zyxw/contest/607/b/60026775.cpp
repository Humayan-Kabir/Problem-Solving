#include <bits/stdc++.h>
#define mx 1000007
using namespace std;
typedef long long int LL;
int dp[501][501], ara[501];
int fun(int i, int j) {
  if(j < i) return 1;
  return dp[i][j];
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
  }
  for(int i = 1; i <= n; i++) {
    dp[i][i] = 1;
    if(i + 1 <= n) 
      dp[i][i + 1] = (ara[i] == ara[i + 1]) ? 1 : 2;
  }
  for(int j = 3; j <= n; j++) {
    for(int i = 1; i + j - 1 <= n; i++) {
      int ii = i, jj = i + j - 1;
      int res = INT_MAX;
      for(int k = ii; k <= jj; k++) {
        if(ara[i] == ara[k]) {
          res = min(res, fun(i + 1, k - 1) + dp[k + 1][jj]);
        }
      }
      dp[ii][jj] = res;
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}

