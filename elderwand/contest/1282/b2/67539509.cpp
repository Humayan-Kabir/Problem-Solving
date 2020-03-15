#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int arr[mx];
LL dp[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(arr + 1, arr + n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i < k) {
                dp[i] = dp[i - 1] + arr[i];
            } else {
                dp[i] = min(dp[i - 1] + arr[i], dp[i - k] + arr[i]);
            }
            if(dp[i] <= p) {
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}