#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int cnt[mx];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    int ini = str[i - 1] - '0', pre = ini;
    for(int i = 0; i <= 200000; i++) {
      if(i < b) {
        if(pre) {
          cnt[i]++;
        }
        continue;
      }
      if(i >= b) {
        if((i - b) % a == 0) {
          pre = pre ^ 1;
          if(pre) {
            cnt[i]++;
          }
        }
        else {
          if(pre) {
            cnt[i]++;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= 200000; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
  return 0;
}

