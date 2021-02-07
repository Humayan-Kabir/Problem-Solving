/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-02-07 20:44:04
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
        LL a, b, n;
        cin >> a >> b >> n;

        vector<pair<int,int>> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i].first;
        for(int i = 0; i < n; i++) cin >> arr[i].second;
        sort(arr.begin(), arr.end());

        int lastposition = -1;

        for(int i = 0; i < n; i++) {
            if(b <= 0) break;
            LL m = arr[i].first, h = arr[i].second;
            LL d1 = (h + a - 1) / a;
            LL d2 = (b + m - 1) / m;
            LL d = min(d1, d2);
            b -= d * m;
            h -= d * a;
            if(h <= 0) {
                lastposition = i;
            } else {
                break;
            }
        }
        lastposition == n - 1 ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
