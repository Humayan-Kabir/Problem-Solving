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
const int MAXN = 200000 + 7;

/*author :: humayan kabir,sust*/
int ara[MAXN];
int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while(t--) {
    ll a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);
    ll right = (k + 1) / 2, left = k - right;
    printf("%lld\n", right * a - left * b);
  }
  return 0;
}
