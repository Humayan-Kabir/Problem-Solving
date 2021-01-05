/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-05 21:15:41
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 300007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef long long int LL;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> choces(n);
        vector<int> cost(m);
        for(int i = 0; i < n; i++) {
            cin >> choces[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> cost[i];
        }
        sort(choces.rbegin(), choces.rend());
        LL given = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            // debug(choces[i], given, cost[choces[i]], cost[given]);
            if(choces[i] > given) {
                ans += cost[given];
                given++;
            } else {
                ans += cost[choces[i] - 1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
