/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-02-22 20:56:02
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
        int n, x; cin >> n >> x;
        vector<int> prefix(n);
        long long ans = 0, minPrefix = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> prefix[i];
            if (i > 0) prefix[i] += prefix[i - 1];
            ans = max(ans, max(1LL * prefix[i], 1LL * prefix[i] - minPrefix));
            minPrefix = min(minPrefix, 1LL * prefix[i]);
        }
        for(int i = 0; i <= n; i++) {
            if (i > 0) {
                minPrefix = 0;
                for(int k = 0; k + i <= n; k++) {
                    ans = max(ans, 1LL * prefix[k + i - 1] - (k == 0 ? 0 : prefix[k - 1]) + i * x);
                    ans = max(ans, 1LL * prefix[k + i - 1] - minPrefix + i * x);
                    minPrefix = min(minPrefix, 1LL * prefix[k]);
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}