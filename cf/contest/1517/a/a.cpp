/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-04-23 20:38:33
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
    vector<LL> vt;
    for(LL i = 1, base = 1; i <= 16; i++) {
        vt.push_back(2050 * base);
        base = base * 10;
    }
    int t;
    cin >> t;
    while(t--) {
        LL num, base = 2050;
        cin >> num;
        int move = 0;
        while(num >= base) {
            for(int i = vt.size() - 1; i >= 0; i--) {
                if(num >= vt[i]) {
                    num -= vt[i];
                    move++;
                    debug(num, vt[i], move);
                    break;
                }
            }
        }
        if(num != 0) move = -1;
        cout << move << endl;
    }
    return 0;
}