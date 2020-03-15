#include<bits/stdc++.h>
#define mx 300007
#define mod 998244353
using namespace std;
typedef long long int LL;
int ara[mx];
vector<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
      cin >> ara[i];
      if(i > 1) {
        s.push_back(ara[i] - ara[i - 1]);
      }
    }
    sort(s.begin(), s.end());
    int ans = ara[n] - ara[1];
    //cout << ans << endl;
    k--;
    while(k--) {
      ans -= s.back();
      s.pop_back();
    }
    cout << ans << endl;
    return 0;
}