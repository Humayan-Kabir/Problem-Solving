/* بسم الله الرحمن الرحيم
 * Author: ElderWand
 * Time: 2021-01-25 22:16:23
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> male(a + 1, 0);
        vector<int> female(b + 1, 0);
        LL totalWay = 1LL * k * (k - 1) / 2;
        for(int i = 1; i <= k; i++) {
            int foo; cin >> foo;
            male[foo]++;
        }
        for(int i = 1; i <= k; i++) {
            int foo; cin >> foo;
            female[foo]++;
        }
        for(int i = 1; i <= a; i++) {
            totalWay -= 1LL * male[i] * (male[i] - 1) / 2;
        }
        for(int i = 1; i <= b; i++) {
            totalWay -= 1LL * female[i] * (female[i] - 1) / 2;
        }
        cout << totalWay << endl;
    }
    return 0;
}
