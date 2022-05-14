/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-05-14 15:44:52
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
        LL n; cin >> n;
        LL minAns = -1, maxAns = -1;
        for(int i = 0; i <= 3; i++) {
            LL remainingForMin = n - i * 4;
            if (remainingForMin % 6 == 0 && minAns == -1) {
                minAns = i + (remainingForMin / 6);
            }
            LL remainingForMax = n - i * 6;
            if (remainingForMax % 4 == 0 && maxAns == -1) {
                maxAns = i + (remainingForMax / 4);
            }
        }
        //debug(minAns, maxAns);
        if (minAns > 0 && maxAns > 0) {
            cout << minAns << " " << maxAns << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}