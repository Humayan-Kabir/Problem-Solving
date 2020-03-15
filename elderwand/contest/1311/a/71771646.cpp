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
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a == b) {
            ans = 0;
        } else if(a < b) {
            if(abs(a - b) % 2 == 0) {
                ans = 2;
            } else {
                ans = 1;
            }
        } else {
             if(abs(a - b) % 2 == 0) {
                ans = 1;
            } else {
                ans = 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}