/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-12-01 22:21:56
 * SUST CSE '15
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
 
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif



int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int x : arr) {
            switch (x) {
                case 0:
                    dp[1][0] += (dp[1][0] + 1);
                    dp[1][0] %= mod;
                    break;
                case 1:
                    dp[0][1] += (dp[0][1] + 1);
                    dp[0][1] %= mod;
                    break;
                case 2:
                    dp[0][2] += (dp[0][1]);
                    dp[0][2] %= mod;
                    dp[1][2] += (dp[1][0]);
                    dp[1][2] %= mod;
                    break;
                default:
                    dp[0][x] += (dp[0][x - 1]);
                    dp[0][x] %= mod;
                    dp[1][x] += (dp[1][x - 1]);
                    dp[1][x] %= mod;
                    break;
            }
        }
        long long int ans = 0;
        for(int i = 0; i <= n; i++) {
            ans = (ans + dp[0][i]) % mod;
            ans = (ans + dp[1][i]) % mod;
        }
        debug(dp[0]);
        debug(dp[1]);
        debug("end");
        cout << ans << endl;
    }
    return 0;
}