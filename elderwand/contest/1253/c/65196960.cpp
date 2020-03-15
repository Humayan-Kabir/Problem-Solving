#include<bits/stdc++.h>
#define mx 300007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
LL c[mx], sum[mx], dp[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + c[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - m >= 0 ? i - m : 0] + sum[i];
        cout << dp[i] << " ";
    }
    cout << endl;  
    return 0;
}
