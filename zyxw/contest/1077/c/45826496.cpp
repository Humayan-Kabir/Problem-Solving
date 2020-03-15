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
int ara[MAXN], cnt[MAXN];
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
    cnt[ara[i]]++;
    sum += (1LL * ara[i]);
  }
  vi ans;
  for(int i = 1; i <= n; i++) {
    ll cur = sum - 1LL * ara[i];
    cnt[ara[i]]--;
    if(cur % 2 == 0 && cur < 2000001 && cnt[cur / 2]) ans.push_back(i);
    cnt[ara[i]]++;
  }
  printf("%d\n", ans.size());
  for(int v : ans) {
    printf("%d ", v);
  }
  return 0;
}
