/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-03-17 21:28:17
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[2][201][5001], was = 0;
struct Solution {
    void solve() {  
        int n, k; 
        cin >> n >> k;
        pair<int,int> arr[201];
        for(int i = 1; i <= n; i++) {
            LL temp;
            cin >> temp;
            int cnt1 = 0, cnt2 = 0;
            while(temp > 0 && temp % 2 == 0) {
                cnt1++; temp /= 2;
            }
            while(temp > 0 && temp % 5 == 0) {
                cnt2++; temp /= 5;
            }
            arr[i] = {cnt1, cnt2};
        }
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= 5000; j++) {
                if(i == 0 && j == 0) continue;
                dp[0][i][j] = INT_MIN;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int l = 0; l <= 5000; l++) {
                    dp[was ^ 1][j][l] = dp[was][j][l];
                    if(l - arr[i].second >= 0 && j - 1 >= 0) {
                        dp[was ^ 1][j][l] = max(dp[was ^ 1][j][l], dp[was][j - 1][l - arr[i].second] + arr[i].first);
                    }
                }
            }
            was = was ^ 1;
        }
        int ans = 0;
        for(int i = 0; i <= 5000; i++) {
            ans = max(ans, min(i, dp[was][k][i]));
        }
        cout << ans << endl;
    }

};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution solver;
    solver.solve();
    return 0;
}