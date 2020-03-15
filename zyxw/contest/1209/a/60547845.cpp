#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int cnt[101];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }
  int ans = 0;
  for(int i = 1; i <= 100; i++) {
    if(cnt[i] > 0) {
      ans++;
      for(int j = i; j <= 100; j += i) {
        cnt[j] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

