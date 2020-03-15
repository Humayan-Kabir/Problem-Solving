#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<int,int,int> data;
typedef long double ld;

const int MAX = 20000 + 7;
const int MAXN = 100000 + 7;

/*author :: humayan kabir,sust*/

ll solve(vl &vt, ll k) {
  map<ll,ll> maping[11];
  for(int v : vt) {
    ll len = 0, temp = v;
    while(temp) {
      len++; temp = temp / 10;
    }
    maping[len][v % k]++;
  }
  ll ans = 0;
  for(ll v : vt) {
    ll len = 0, temp = v;
    while(temp) {
      len++; temp = temp / 10;
    }
    maping[len][v % k]--;
    for(int i = 1; i <= 10; i++) {
      v = (v * 10) % k;
      ll mod = v % k;
      ll need = k - mod;
      if(maping[i].find(need) != maping[i].end()) {
        ans += maping[i][need];
      }
      if(need == k) {
        if(maping[i].find(0) != maping[i].end()) {
          ans += maping[i][0];
        }
      }
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  int n, k;
  scanf("%d %d", &n, &k);
  vl vt;
  for(int i = 0; i < n; i++) {
      ll num;
      scanf("%lld", &num);
      vt.emplace_back(num);
  }
  ll ans = solve(vt, k);
  reverse(vt.begin(), vt.end());
  ans = ans + solve(vt, k*1LL);
  printf("%lld\n", ans);
  return 0;
}
