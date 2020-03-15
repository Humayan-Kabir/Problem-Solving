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
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    ara[num]++;
  }
  int ans = 1, low = 1, high = n;
  while(low <= high) {
    int mid = (low + high) / 2;
    ll cnt = 0;
    for(int i = 1; i < MAXN; i++) {
      cnt += 1LL*(ara[i] / mid);
    }
    if(cnt >= (1LL * k)) {
      low = mid + 1;
      ans = max(ans, mid);
    }
    else high = mid - 1;
  }
  //error(ans);
  int flag = 0;
  for(int i = 1; i < MAXN; i++) {
    int cnt = ara[i] / ans;
    while(cnt > 0 && k > 0) {
      if(flag) printf(" ");
      printf("%d", i);
      cnt--; k--;
      flag = 1;
    }
  }
  printf("\n");
  return 0;
}
