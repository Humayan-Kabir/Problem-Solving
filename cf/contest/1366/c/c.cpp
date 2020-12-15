/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-12-15 22:50:41
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
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> counter(n + m - 1, {0, 0});
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int value;
                cin >> value;
                if(value == 0)
                    counter[i + j].first++;
                else 
                    counter[i + j].second++;
            }
        }   
        int ans = 0;
        for(int i = 0, j = n + m - 2; i < j; i++, j--) {
            // debug(counter[i], counter[j]);
            int zero = counter[i].first + counter[j].first;
            int one = counter[i].second + counter[j].second;
            ans += min(zero, one);
        }
        cout << ans << endl;
    }
    return 0;
}
