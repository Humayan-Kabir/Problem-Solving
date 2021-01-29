/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-29 21:42:31
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        vector<int> c(n + 1);
        vector<LL> pre(n + 1, 0);
        
        for(int i = 1; i <= n; i++) cin >> c[i];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        
        LL ans = 0;
        
        for(int i = 2; i <= n; i++) {
            pre[i] = 1LL * abs(a[i] - b[i]) + 2;
            if(a[i] != b[i] && pre[i - 1] != 0) {
                LL add = 1LL * pre[i - 1] + c[i - 1] - 1 - abs(a[i] - b[i]) + 2;
                pre[i] = max(pre[i], add);
            }
            ans = max(ans, pre[i] + c[i] - 1);
            //debug(pre[i], ans);
        }
        cout << ans << endl;

    }
    return 0;
}
