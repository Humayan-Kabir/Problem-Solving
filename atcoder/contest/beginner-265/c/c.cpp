/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-08-21 18:56:16
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

const int N = 501;
char g[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> g[i][j];
        }
    }        
    int x = 1, y = 1;
    while(g[x][y] != '#') {
        int xN = x, yN = y;
        // debug("before",xN, yN);
        switch (g[x][y])
        {
            case 'U': {
                if(xN != 1) xN--;
                break;
            }
            case 'D': {
                if(xN != h) xN++;
                break;
            }
            case 'L': {
                if(yN != 1) yN--;
                break;
            }
            case 'R': {
                if(yN != w) yN++;
                break;
            }
            default:
                break;
        }
        // debug("after", xN, yN);
        g[x][y] = '#';
        if (xN == x && yN == y) {
            cout << xN << " " << yN << endl;
            return 0;
        }
        x = xN; y = yN;
    }
    cout << -1 << endl;
    return 0;
}