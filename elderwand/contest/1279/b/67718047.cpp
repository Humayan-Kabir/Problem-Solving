#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
LL a[mx], sum[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
       int n, s;
       cin >> n >> s;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
           sum[i] = sum[i - 1] + a[i];
       }
       int ans = 0, pos = 0;
       if(sum[n] <= s) {
           ans = n;
           cout << 0 << endl;
       } else {
           for(int i = 1; i <= n; i++) {
               if(sum[i - 1] > s) break;
               LL need = s + a[i];
               int low = 1, high = n, to = 1;
               while(low <= high) {
                   int mid = (low + high) / 2;
                   if(sum[mid] <= need) {
                       to = max(to, mid);
                       low = mid + 1;
                   } else {
                       high = mid - 1;
                   }
               }
            //   cout << i << " " << to << endl;
            if(to - 1 > ans) {
                ans = to - 1;
                pos = i;
            }
           }
         cout << pos << endl;
       }
    }
    return 0;
}