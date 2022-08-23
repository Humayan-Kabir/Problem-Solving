/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-08-20 21:16:47
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
typedef long long int LL;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        LL n, k, b, s; cin >> n >> k >> b >> s;
        vector<LL> ans(n, 0LL); 
        LL minSum = b * k;
        LL maxSum = b * k + (k - 1) * n;
        if (s < minSum || s > maxSum) {
            cout << -1 << endl;
            continue;
        }
        ans[0] = minSum; s -= minSum;
        // debug(ans);
        for(int i = 0; i < n; i++) {
            LL extra = min(k - 1, s);
            // debug("extra", extra);
            ans[i] += extra; s -= extra;
        }
        for(int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}