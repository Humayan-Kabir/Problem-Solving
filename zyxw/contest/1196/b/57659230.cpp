#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
LL ara[mx];
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
      int n, k;
      cin >> n >> k;
      for(int i = 1; i <= n; i++) {
          cin >> ara[i];
          ara[i] = (ara[i - 1] + ara[i]) % 2;
      }
      if(k & 1) {
          if(ara[n] == 0) {
              cout << "NO" << endl;
              continue;
          }
      }
      else {
          if(ara[n] == 1) {
              cout << "NO" << endl;
              continue;
          }
      }

       int pre = 0;
        vector<int> ans;
        int t = k - 1;
        for(int i = 1; i < n && t; i++) {
            if(ara[i] != pre) {
                ans.push_back(i);
                t--;
                pre = !pre;
            }
        }
        ans.push_back(n);
        if(ans.size() == k) {
            cout << "YES" << endl;
            for(int x : ans) {
                cout << x <<" ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
  }
  return 0;
}
