/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-10 17:56:19
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 200007

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
map<LL,LL> dp;
LL rec(LL num, LL to) {
    if(dp.find(num) != dp.end()) return dp[num];
    LL way = abs(num - to);
    if(num >= to || num <= 0) {
        return way;
    }
    LL x = 2*num - 2, y = 2*num + 2;
    if(abs(x - to) <= abs(y - to)) {
        way = min(way, 2 + rec(2*num - 2, to));
    } else {
        way = min(way, 2 + rec(2*num + 2, to));
    }
    way = min(way, 1 + rec(2 * num, to));
    return dp[num] = way;
}
int main() {
    ios_base::sync_with_stdio(false);
    LL x, y;
    cin >> x >> y;
    cout << rec(x, y) << endl;
    return 0;
}
