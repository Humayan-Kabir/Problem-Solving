/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-11-28 21:17:37
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
string str;
int n, q, counter = 0;
void update(int pos, int val) {
    if (pos < 0 || (pos + 2) >= n) return;
    if (str[pos] == 'a' && str[pos + 1] == 'b' && str[pos + 2] == 'c') {
        counter += val;
    }
}
int main() {
    cin >> n >> q >> str;
    for(int i = 0; i < n; i++) {
        update(i, 1);
    }
    while(q--) {
        char ch;
        int x;
        cin >> x >> ch;
        x--;
        for(int i = x - 2; i <= x; i++) {
            update(i, -1);
        }
        str[x] = ch;
        for(int i = x - 2; i <= x; i++) {
            update(i, 1);
        }
        cout << counter << endl;
    }
    return 0;
}