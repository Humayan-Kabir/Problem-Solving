/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-15 22:20:30
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
const int N = 1000007;

int mark[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num; cin >> num; mark[num] = 1;
    }
    int ans = 0;
    for(int i = 1; i < N; i++) {
        int g = 0;
        for(int j = i; j < N; j += i) {
            if (mark[j]) g = __gcd(g, j / i);
            if (g == 1) break;
        }
        ans += (g == 1);
    }
    cout << ans - n << endl;
    return 0;
}