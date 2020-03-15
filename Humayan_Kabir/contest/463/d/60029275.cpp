#include <bits/stdc++.h>
#define mx 1000007
using namespace std;
typedef long long int LL;
vector<int> position[1001];
int n, k, ara[6][1001] ,dp[1001][1001];
int rec(int pos, int pre) {
  if(pos > n) return 0;
  int &ret = dp[pos][pre];
  if(ret != -1) return ret;
  int now = rec(pos + 1, pre), flag = 0;
  for(int i = 0; i < k; i++) {
    if(position[pre][i] >= position[ara[1][pos]][i]) flag = 1;
  }
  if(!flag) now = max(now, 1 + rec(pos + 1, ara[1][pos]));
  return ret = now;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= k; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &ara[i][j]);
      position[ara[i][j]].push_back(j);
    }
  }
  for(int i = 0; i < k; i++) {
    position[0].push_back(0);
  }
  memset(dp, -1, sizeof dp);
  cout << rec(1, 0) << endl;
  return 0;
}

