#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[mx], cnt[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    dp[0] = 1;
    int ans = 0;
    for(int i = 1; i <= 150000; i++) {
        if(cnt[i] == 0) continue;
        if(cnt[i] > 0 && dp[i - 1] == 0) {
            dp[i - 1] = 1;
            ans++; cnt[i]--;
        }
        if(cnt[i] > 0 && dp[i] == 0) {
            dp[i] = 1;
            ans++; cnt[i]--;
        }
        if(cnt[i] > 0 && dp[i + 1] == 0) {
            dp[i + 1] = 1;
            ans++; cnt[i]--;
        }
    }
    if(cnt[150001] > 0 && dp[150001] == 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
 