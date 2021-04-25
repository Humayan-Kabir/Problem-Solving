/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-04-23 23:07:05
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

int grid[N][N][21], cost[N][N][4];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isValid(int x, int y, int n, int m) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= 20; k++) {
                grid[i][j][k] = INT_MAX;
            }
        }
    }
}
int main(){
    init();
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
            int val;
            cin >> val;
            cost[i][j][1] = val;
            cost[i][j + 1][0] = val;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            int val;
            cin >> val;
            cost[i][j][3] = val;
            cost[i + 1][j][2] = val;
        }
    }
    for(int x = 1; x <= k; x++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
               for(int l = 0; l < 4; l++) {
                   int go_x = i + dx[l];
                   int go_y = j + dy[l];
                 //  debug(go_x, go_y);
                   if(isValid(go_x, go_y, n, m) && grid[go_x][go_y][x] > (grid[i][j][x - 1] + cost[i][j][l])) {
                       grid[go_x][go_y][x] = grid[i][j][x - 1] + cost[i][j][l];
                   }
               }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j > 1) cout << " ";
            if(grid[i][j][k] == INT_MAX) grid[i][j][k] = -1;
            cout << grid[i][j][k];
        }
        cout << endl;
    }
    return 0;
}