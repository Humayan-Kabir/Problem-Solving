#include <bits/stdc++.h>
#define mx 1000007
using namespace std;
typedef long long int LL;
namespace FenwickTree {
  int n, tree[mx], a[mx], prev[mx], ans[mx], prefix[mx];
  vector<pair<int,int>> queries[mx];
  map<int,int> maping;
  void update(int idx, int val) {
    while(idx <= n) {
      tree[idx] ^= val;
      idx += (idx & -idx);  
    }
  }
  int query(int idx) {
    int ans = 0;
    while(idx > 0) {
      ans ^= tree[idx];
      idx -= (idx & -idx);
    }
    return ans;
  }
  void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      prefix[i] = prefix[i - 1] ^ a[i];
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      queries[r].push_back(make_pair(l, i));
    }
    for(int i = 1; i <= n; i++) {
      if(maping.find(a[i]) != maping.end()) {
        update(maping[a[i]], a[i]);
      }
      maping[a[i]] = i;
      update(i, a[i]);
      for(auto v : queries[i]) {
        ans[v.second] = query(i) ^ query(v.first - 1) ^ prefix[i] ^ prefix[v.first - 1];
      }
    }
    for(int i = 1; i <= q; i++) {
      printf("%d\n", ans[i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  FenwickTree::solve();
}
