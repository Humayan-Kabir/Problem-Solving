#include<bits/stdc++.h>
using namespace std;
int dp[1 << 20];
int main() {
    string str;
    cin >> str;
    for(int i = 0, len = str.length(); i < len; i++) {
        int mask = 0;
        for(int j = i; j < len; j++) {
            int b = str[j] - 'a';
            if(mask & (1 << b)) break;
            mask = (mask | 1 << b);
            dp[mask] = j - i + 1;
        }
    }
    for(int j = 0; j < 20; j++) {
        for(int i = 0; i < (1 << 20); i++) {
            if(i & (1 << j)) {
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << 20); i++) {
        ans = max(ans, dp[i] + dp[(1 << 20) - 1 - i]);
    }
    cout << ans << endl;
    return 0;
}