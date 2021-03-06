/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-10 17:56:19
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void __print(int x)
{
    cerr << x;
}
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

int MX = 1000007;

int tree[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    LL ans = 0;
    while(n--) {
        int x;
        cin >> x;
        int sum = 0;
        while(x > 0) {
            sum += tree[x];
            x -= (x & -x);
        }
        ans += sum;
        while(x < MX) {
            tree[x] += 1;
            x += (x & -x);
        }

    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) cout << ans << endl;
        else {
            ans = ans + (n - i) - (i - 1);
            cout << ans << endl;
        }
    }
    return 0;
}
