#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx][4][4];
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  map<char,int> maping;
  maping['R'] = 0;
  maping['G'] = 1;
  maping['B'] = 2;
  while(t--) {
      int n, k;
      cin >> n >> k;
      string str;
      cin >> str;
      for(int i = 1; i <= n; i++) {
          for(int x = 0; x < 3; x++) {
              for(int y = 0; y < 3; y++) {
                  ara[i][x][y] = 0;
              }
          }
          int m = i % 3;
          int x = maping[str[i - 1]];
           for(int x = 0; x < 3; x++) {
              for(int y = 0; y < 3; y++) {
                  ara[i][x][y] = ara[i - 1][x][y];
              }
          }
          ara[i][m][x] += 1;
      }
      int ans = INT_MAX;
      for(int i = 1; i <= n; i++) {
          if(i + k - 1 > n) break;
          int x = min(k, 3), to = i + k - 1;
          vector<int> vt[3];
          int now = 0;
          for(int j = i; x > 0 ; j++, x--) {
              int u = j % 3;
              for(int kk = 0; kk < 3; kk++) {
                  int v = ara[to][u][kk] - ara[i - 1][u][kk];
                  vt[now].push_back(v);
              }
              now++;
          }
          if(vt[1].size() == 0) {
              vt[1].push_back(0);
              vt[1].push_back(0);
              vt[1].push_back(0);
          }
          if(vt[2].size() == 0) {
              vt[2].push_back(0);
              vt[2].push_back(0);
              vt[2].push_back(0);
          }
          int total = vt[0][0] + vt[1][1] + vt[2][2];
          total = max(total, vt[0][1] + vt[1][2] + vt[2][0]);
          total = max(total, vt[0][1] + vt[1][2] + vt[2][0]);
          total = max(total, vt[0][2] + vt[1][0] + vt[2][1]);
          ans = min(ans, k - total);
      }
      cout << ans << endl;
  }
  return 0;
}
