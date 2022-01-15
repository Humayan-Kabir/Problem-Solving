/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-15 21:45:42
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

const int MAX = 100007;

int colorAns[MAX], OK;
vector<pair<int,int>> graph[MAX];

void dfs(int u, int pre, int prevColor) {
    int mark[4] = {0};
    for(auto it: graph[u]) {
        int v = it.first;
        int edgeNo = it.second;
        if (v != pre) {
            int given = false;
            for(int c = 2; c <= 3; c++) {
                if (c == prevColor || mark[c]) continue;
                given = true;
                colorAns[edgeNo] = c;
                mark[c] = 1;
                dfs(v, u, c);
                break;
            }
            OK = OK & given;
        } 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back({v, i});
            graph[v].push_back({u, i});
        }
        OK = true;
        dfs(1, -1, -1);
        if (OK) {
            for(int i = 1; i < n; i++) {
                if (i > 1) cout << " ";
                cout << colorAns[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }
    }
    return 0;
}