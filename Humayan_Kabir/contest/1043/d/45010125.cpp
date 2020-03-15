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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<int,int,int> data;
typedef long double ld;

const int MAX = 20000 + 7;
const int MAXN = 100000 + 7;

/*author :: humayan kabir,sust*/
int ara[11][MAXN];
vi vt[MAXN];
int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &ara[i][j]);
      vt[ara[i][j]].push_back(j);
    }
  }
  ll ans = 0, cnt = 0;
  int curpos[12];
  for(int i = 1; i <= n; i++) {
    if(i == 1) {
      cnt = 1;
      int from = 0;
      for(int v : vt[ara[1][i]]) {
        curpos[++from] = v;
      }
      continue;
    }
    int check = 1, val = ara[1][i];
    for(int j = 1; j <= m; j++) {
      curpos[j]++;
      if(curpos[j] > n || ara[j][curpos[j]] != val) {
        check = 0;
        break;
      }
    }
    if(check == 1) {
      cnt++;
    }
    else {
      ans += (cnt * (cnt + 1)) / 2LL;
      cnt = 1;
      int from = 0;
      for(int v : vt[ara[1][i]]) {
        curpos[++from] = v;
      }
      continue;
    }
  }
  if(cnt > 0) {
    ans += (cnt * (cnt + 1)) / 2LL;
  }
  printf("%lld\n", ans);
  return 0;
}
