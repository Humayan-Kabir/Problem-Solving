/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-11-29 13:42:10
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 200007

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

int counter[mx], arr[mx];

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string str;
        cin >> str;
        for(int i = 0; i <= k; i++) {
            counter[i] = 0;
        }
        for(int i = p, modValue = 0; i <= n; i++) {
            int platform = str[i - 1] - '0';
            counter[modValue] += platform ^ 1;
            arr[i] = platform;
            modValue = (modValue + 1) % k;
        }
        int x, y;
        cin >> x >> y;
        int ans = counter[0] * x;
        for(int i = 1, modValue = 0; n - i >= p; i++) {
            
            counter[modValue] -= (arr[p + i - 1] ^ 1);
            modValue = (modValue + 1) % k;
            int cost = i * y + counter[modValue] * x;
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
    return 0;
}
