/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-12-30 22:30:07
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
        vector<int> degree(n + 1, 0);
        vector<int> weight;
        LL total = 0;
        vector<pair<int,int>> tmp;
        for(int i = 1; i <= n; i++) {
            int w; 
            cin >> w; 
            total = total + w;
            weight.push_back(w);
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            degree[u] += 1;
            degree[v] += 1;
        }

        vector<int> add;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < degree[i]; j++) {
                add.push_back(weight[i - 1]);
            }
        }
        sort(add.rbegin(), add.rend());
        cout << total;
        for(int v : add) {
            total += v;
            cout <<  " " << total;
        }
        cout << endl;
        
    }
    return 0;
}
