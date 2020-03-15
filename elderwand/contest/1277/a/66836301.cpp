#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
int main() { 
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= 9; i++) {
            for(int j = 1, num = 0; j <= 9; j++) {
                num = num * 10 + i;
                if(num <= n) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}