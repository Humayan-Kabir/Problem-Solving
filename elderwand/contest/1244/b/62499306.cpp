#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ans = n;
        for(int i = 1; i <= n; i++) {
            if(str[i - 1] == '1') {
                ans = max(ans, 2 * i);
                ans = max(ans, (n - i + 1) * 2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}