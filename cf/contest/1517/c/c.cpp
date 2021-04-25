/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-04-23 21:41:10
 * SUST CSE '15
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 501 
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
int grid[N][N], need, limit;
bool isNotValid(int x, int y) {
    return x <= 0 || y <= 0 || x > limit || y > limit || y > x || grid[x][y] != 0;
}
void rec(int x, int y, int val) {
   // debug(x, y, val, "inside rec");
    if(need == 0 || isNotValid(x, y)) return;
    grid[x][y] = val;
    need--;
    rec(x - 1, y, val);
    rec(x, y - 1, val);
    rec(x + 1, y, val);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;    
    vector<int> diagonal(n);
    for(int i = 0; i < n; i++) cin >> diagonal[i];
    for(int i = 0; i < n; i++) {
        need = diagonal[i]; 
        limit = n;
        rec(i + 1, i + 1, diagonal[i]);
        if(need != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j > 1) cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}