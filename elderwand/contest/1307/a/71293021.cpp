#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num; 
            if(i == 0) {
                ans += num;
            } else {
                int k = min(num, d / i);
                ans += k;
                d -= i * k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}