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
const int MAXN = 2000000 + 7;

/*author :: humayan kabir,sust*/
map<int,int> maping;
int vis[MAXN];
multiset<ll> SET;
vl vt;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    maping[num]++;
  }
  for(auto v : maping) {
    vt.emplace_back(1LL * v.second);
    SET.insert(1LL * v.second);
  }
  ll ans = 0;
  sort(vt.begin(), vt.end());
  for(ll v : vt) {
    ans = max(ans, v);
    SET.erase(SET.find(v));
    if(SET.empty()) continue;
    for(ll i = 1; i <= v; i++) {
      if(vis[i] == 1) continue;
      vis[i] = 1;
      ll cur = i, pre = i;
      vl temp;
      while(1) {
        auto it = SET.upper_bound(pre * 2 - 1);
        if(it == SET.end()) break;
        cur += (pre * 2);
        temp.emplace_back((*it));
        SET.erase(it);
        if(SET.empty()) break;
        pre = pre * 2;
      }
      for(ll x : temp) {
        SET.insert(x);
      }
      ans = max(ans, cur);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
