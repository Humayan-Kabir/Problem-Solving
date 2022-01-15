/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-15 20:35:15
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
    while(t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        bool sameRowOrCol = false, isBlackExist = false, alreadyBlack = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char ch; cin >> ch;
                if (ch == 'B') {
                    isBlackExist = true;
                    if (i == r || j == c) sameRowOrCol = true;
                    if (i == r && j == c) alreadyBlack = true;
                }
            }
        }

        if (alreadyBlack) {
            cout << 0 << endl;
        } else if (sameRowOrCol) {
            cout << 1 << endl;
        } else if (isBlackExist) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}