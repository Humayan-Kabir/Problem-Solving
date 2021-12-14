/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-12-14 21:21:33
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long int odd_gcd = 0, even_gcd = 0;
        vector<long long int> vt(n);
        for(int i = 0; i < n; i++) {
            cin >> vt[i];
            if (i & 1) {
                odd_gcd = __gcd(odd_gcd, vt[i]);
            } else {
                even_gcd = __gcd(even_gcd, vt[i]);
            }
        }
        for(int i = 0; i < n; i++) {
            if (i & 1) {
                if (vt[i] % even_gcd == 0) {
                    even_gcd /= __gcd(even_gcd, vt[i]);
                }
            } else {
                if (vt[i] % odd_gcd == 0) {
                    odd_gcd /= __gcd(odd_gcd, vt[i]);
                }
            }
        }
        if (odd_gcd == 1 && even_gcd == 1) {
            cout << 0 << endl;
        } else {
            cout << max(odd_gcd, even_gcd) << endl;
        }
    }
    
    return 0;
}