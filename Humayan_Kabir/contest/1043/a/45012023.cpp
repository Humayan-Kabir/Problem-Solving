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
int ara[110];
int main(int argc, char const *argv[]) {
  int n, k = 0, sum = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
    k = max(k, ara[i]);
    sum += ara[i];
  }
  //error(sum);
  int ans = k;
  for(int i = k; ; i++) {
    int cur = 0;
    for(int j = 1; j <= n; j++) {
      cur += (i - ara[j]);
    }
    if(cur > sum) {
      ans = i;
      break;
    }
  }
  printf("%d\n",ans);
  return 0;
}
