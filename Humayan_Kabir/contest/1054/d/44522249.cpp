#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef long double ld;

/*author :: humayan kabir,sust*/

int const MAX = 1000000 + 7;
int const MAXM = 10000 + 7;
int const LOGN = 20;

int n, k, gmask;
int ara[MAX];
map<int,int> maping;

int main(int argc, char const *argv[]) {
  scanf("%d %d",&n, &k);
  ara[0] = 0;
  for(int i = 1; i<=n; i++) {
    scanf("%d",&ara[i]);
    ara[i] = ara[i] ^ ara[i - 1];
  }
  for(int i = 0; i<k; i++) {
    gmask = gmask | (1 << i);
  }
  int toogle = 0;
  ll ans = 1LL * n * (n + 1);
  ans = ans / 2LL;
  maping[0]++;
  for(int i = 1; i<=n; i++) {
    if(toogle) {
      int now = ara[i] ^ gmask;
      int cur1 = 0, cur2 = 0;
      if(maping.find(now) != maping.end()) {
        cur1 = maping[now];
      }
      if(maping.find(ara[i]) != maping.end()) {
        cur2 = maping[ara[i]];
      }

      if(cur2 < cur1) {
        toogle = toogle ^ 1;
        ans -= cur2;
      }
      else {
        ara[i] = ara[i] ^ gmask;
        ans -= cur1;
      }
    }
    else {
      int now = ara[i] ^ gmask;
      int cur1 = 0, cur2 = 0;
      if(maping.find(now) != maping.end()) {
        cur1 = maping[now];
      }
      if(maping.find(ara[i]) != maping.end()) {
        cur2 = maping[ara[i]];
      }

      if(cur1 < cur2) {
        ara[i] = ara[i] ^ gmask;
        toogle = toogle ^ 1;
        ans -= cur1;
      }
      else {
        ans -= cur2;
      }
    }
    maping[ara[i]]++;
  }
  printf("%lld\n", ans);
  return 0;
}
