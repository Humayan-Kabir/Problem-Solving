/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-16 22:04:10
 * SUST CSE '15
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> timer(n);
        vector<int> health(n);
        vector<int> cost(n);
        for(int i = 0; i < n; i++) cin >> timer[i];
        for(int i = 0; i < n; i++) cin >> health[i];
        long long int dp[n] = {0};
        for(int i = 0; i < n; i++) {
            int start = timer[i] - health[i], prev = -1;
            for(int j = i; j >= 0; j--) {
                if (timer[j] > start) {
                    start = min(start, timer[j] - health[j]);
                } else {
                    dp[i] += dp[j];
                    break;
                }
            }
            int t = timer[i] - start;
            dp[i] += (1LL * t * (t + 1)) / 2LL;
        }
        cout << dp[n - 1] << endl;
    }   
    return 0;
}
