/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-04-23 21:03:49
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
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> vt;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int num;
                cin >> num;
                vt.push_back({num, i - 1});
            }
        }
        sort(vt.begin(), vt.end());
        for(int i = 0; i < vt.size(); i++) {
            //debug("actual", vt[i].first, vt[i].second);
            if(i < m) {
                ans[vt[i].second][i] = vt[i].first;
            } else {
                for(int j = 0; j < m; j++) {
                   // debug(j, ans[vt[i].second][j]);
                    if(ans[vt[i].second][j] == 0) {
                        ans[vt[i].second][j] = vt[i].first;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j > 0) cout << " ";
                cout << ans[i][j];
            }
            cout << endl;
        }
          
    }
    return 0;
}