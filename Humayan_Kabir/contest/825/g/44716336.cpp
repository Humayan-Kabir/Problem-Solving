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
typedef vector<long long> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<int,int,int,int> data;
typedef long double ld;

const int MAXN = 1000001;
const int MAXM = 1000000 + 7;

/*author :: humayan kabir,sust*/
vi graph[MAXN];
int mnfromroot[MAXN];
void dfs(int u, int p, int mn) {
  mnfromroot[u] = mn;
  for(int v : graph[u]) {
    if(v != p) {
      dfs(v, u, min(mn, v));
    }
  }
}
void solve(int n, int q) {
  int x, last = 0;
  scanf("%d",&x);
  scanf("%d",&x);
  x = 1 + (x + last) % n;
  dfs(x, -1, x);
  int ans = x;
  while(--q) {
    int t, node;
    scanf("%d %d",&t, &node);
    node = 1 + (node + last) % n;
    if(t == 1) {
      ans = min(ans, mnfromroot[node]);
    }
    else {
      last = min(ans, mnfromroot[node]);
      printf("%d\n", last);
    }
  }
}
int main(int argc, char const *argv[]) {
  int n, q;
  scanf("%d %d",&n, &q);
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d",&u,&v);
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  solve(n, q);
  //resubmit
  return 0;
}
