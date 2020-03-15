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
typedef long double float128;

/*author :: humayan kabir,sust*/

const ll is_query = -(1LL<<62), inf = 1e18;

struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> { // // will maintain lower hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (float128)(x->b - y->b)*(z->m - y->m) >= (float128)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });//for maxi
        //   auto y = insert({ -m, -b });// for here for minimum
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    //for query, Line can't be empty
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return (l.m * x + l.b);//here for maxi
      //   return -(l.m * x + l.b);////  here for minimum
    }
};
ll sum[200007], p[200007];
void solve(int n) {
  HullDynamic H;
  H.insert_line(0, 0);
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ll num;
    scanf("%lld", &num);
    sum[i] = i * num + sum[i - 1];
    p[i] = num + p[i - 1];
    ans = max(ans, sum[i] + H.eval(p[i]));
    H.insert_line(-i*1LL, 1LL * i * p[i] - sum[i]);
  }
  printf("%lld\n", ans);
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  solve(n);
  return 0;
}
