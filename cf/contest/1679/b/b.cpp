/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-05-14 16:16:23
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
    int n, q; cin >> n >> q;
    LL total = 0;
    vector<LL> vt(n + 1);
    vector<LL> updatedTime(n + 1, 0);
    for(LL i = 1; i <= n; i++) {
        cin >> vt[i];
        total += vt[i];
    }
    //debug("outside", vt);
    LL lazy = 0, lazyTime = INT_MIN;
    for(LL i = 0; i < q; i++) {
        LL t; cin >> t;
        if (t == 1) {
            LL x, y; cin >> x >> y;
            if (lazyTime > updatedTime[x]) {
                updatedTime[x] = i;
                vt[x] = lazy;
            }
            total += (y - vt[x]);
            vt[x] = y;
        } else {
            LL num; cin >> num;
            total = n * num;
            lazyTime = i;
            lazy = num;
        }
        cout << total << endl;
    }
    return 0;
}