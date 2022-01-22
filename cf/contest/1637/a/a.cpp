/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-02-12 20:36:58
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
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> vt(n + 2);
        vector<int> pref(n + 2);
        vector<int> suff(n + 2);
        pref[0] = INT_MIN;
        suff[n + 1] = INT_MAX;
        for(int i = 1; i <= n; i++) cin >> vt[i];
        for(int i = 1; i <= n; i++) {
            pref[i] = max(pref[i - 1], vt[i]);
        }
        int flag = 0;
        for(int i = n; i >= 1; i--) {
            suff[i] = min(suff[i + 1], vt[i]);
        }
        for(int i = 1; i < n; i++) {
            if (pref[i] > suff[i + 1]) flag |= 1;
        }
        if (!flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}