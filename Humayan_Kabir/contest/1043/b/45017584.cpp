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
int ara[1100], x[1100];
int check(int y, int n) {
  int pre  = 0;
  for(int i = 1; i <= n; i++) {
    pre = pre + x[(i - 1) % y];
    if(pre != ara[i]) return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  ara[0] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
  }
  vi ans;
  for(int i = 1; i <= n; i++) {
    x[i - 1] = ara[i] - ara[i - 1];
  }
  for(int i = 1; i <= n; i++) {
    if(check(i, n)) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) {
    if(i == 0) {
      cout << ans[i];
    }
    else
    {
      cout << " " << ans[i];
    }
  }
  cout << endl;
  return 0;
}
