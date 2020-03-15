#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int position[6][1002], ara[6][1002], dp[1002];
int main(int argc, char const *argv[])
{
int n, k;
cin >> n >> k;
for(int i = 1; i <= k; i++) {
    for(int j = 1; j <= n; j++) {
        int number;
        cin >> number;
        ara[i][j] = number;
        position[i][number] = j;
    }
}
int ans = 0;
for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    for(int j = 1; j < i; j++) {
        int cnt = 1;
        for(int l = 2; l <= k; l++) {
            if(position[l][ara[1][j]] < position[l][ara[1][i]]) cnt++;
        }
        if(cnt >= k) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    ans = max(ans, dp[i]);
}
cout << ans << endl;
return 0;
}