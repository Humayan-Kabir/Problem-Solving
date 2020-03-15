#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t; 
    while(t--) {
        int a[3];
        for(int i = 0; i < 3; i++) cin >> a[i];
        int ans = 0;
        for(int i  = 0; i < 3; i++) {
            if(a[i] > 0) {
                ans++; a[i]--;
            }
        }
        sort(a, a + 3);
        reverse(a, a + 3);
        if(a[0] > 0 && a[1] > 0) {
            ans++; a[0]--;
            a[1]--;
        }
        if(a[0] > 0 && a[2] > 0) {
            ans++; a[0]--;
            a[2]--;
        }
        if(a[1] > 0 && a[2] > 0) {
            ans++; a[1]--;
            a[2]--;
        }
        if(a[0] > 0 && a[1] > 0 && a[2] > 0) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}