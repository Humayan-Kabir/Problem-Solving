/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-14 20:48:20
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
        string a, b;
        cin >> a >> b;
        if(a.length() < b.length()) swap(a, b);
        string ans = a;
        int found = 0, limit = 400, x = 0, y = 0, len1 = a.length(), len2 = b.length();
        for(int i = 0; (i < ans.length()) && (limit > 0); i++, limit--) {
            if(ans[i] == a[x] && ans[i] == b[y]) {
                x = (x + 1) % len1;
                y = (y + 1) % len2;
            } else {
                break;
            }
            if(i == ans.length() - 1) {
                if(x == 0 && y == 0) {
                    found = 1;
                    break;
                } else {
                    ans = ans + a;
                }
            }
        }
        if(found) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
