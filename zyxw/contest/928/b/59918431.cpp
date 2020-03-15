#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int pre;
        cin >> pre;
        if(pre == 0)
            dp[i] = 1 + dp[pre] + min(k, i - 1);
        else 
            dp[i] = 1 + dp[pre] + min(2 * k, i - pre - 1);
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i] + min(n - i, k) << " ";
    }
    cout << endl;
    return 0;
}
