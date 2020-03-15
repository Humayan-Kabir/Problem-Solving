#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
       int n, x;
       cin >> n >> x;
       int ans = INT_MAX;
       map<int,int> maping;
       for(int i = 1; i <= n; i++) {
          int num;
          cin >> num; ara[i] = num;
          maping[num] = 1;
       }
       for(int i = 1; i <= n; i++) {
          int res = (x / ara[i]), rem = x % ara[i];
          if(rem == 0) {
             ans = min(ans, res);
          } else {
             if(maping.find(rem) != maping.end()) {
                res += 1;
             } else {
                res += 2;
             }
            ans = min(ans, res);
          }
       }
       for(int i = 1; i <= n; i++) {
          int rem = max(0, x - 2 * ara[i]);
          int add = (rem + ara[i] - 1) / ara[i];
          ans = min(ans, 2 + add);
       }
       cout << ans << endl;
    }
    return 0;
}