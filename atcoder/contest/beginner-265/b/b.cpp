/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-08-21 18:06:57
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    LL n, m, t; cin >> n >> m >> t;
    vector<int> cost(n + 1);
    vector<int> extra(n + 1, 0);
    for(int i = 1; i < n; i++) cin >> cost[i];
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        extra[x] = y;
    }
    bool isValid = true;
    for(int i = 1; i < n; i++) {
        if(t > cost[i]) {
            t = t - cost[i] + extra[i + 1];
            continue;
        }
        isValid = false;
        break;
    }
    cout << (isValid == true ? "Yes" : "No") << endl;
    return 0;
}

/*
    5+10-7
*/