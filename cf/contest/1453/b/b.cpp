/* بسم الله الرحمن الرحيم
 * Author: ElderWand
 * Time: 2020-12-06 16:42:21
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

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int &x : arr) cin >> x;
        long long ans = 0, res = 1e16;
        for(int i = 0; i < n - 1; i++) {
            ans += abs(arr[i] - arr[i + 1]);
        }
        res = min(ans - abs(arr[0] - arr[1]), ans - abs(arr[n - 1] - arr[n - 2]));
        for(int i = 1; i < n - 1; i++) {
            long long need = abs(arr[i + 1] - arr[i - 1]);
            long long pre = abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]);
            res = min(res, ans + need - pre);
        }
        cout << res << endl;
    }
    return 0;
}
