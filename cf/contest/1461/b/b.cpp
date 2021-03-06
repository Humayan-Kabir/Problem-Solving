/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-12-11 21:37:19
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

int sum[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            for(int j = 1, total = 0; j <= m; j++) {
                total += (str[j - 1] == '*');
                sum[i][j] = total;
            }
        }

        int result = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int l = j, r = j, row = i, need = 1;

                while(row <= n && (l >= 1 && r <= m) && (sum[row][r] - sum[row][l - 1] == need)) {
                    result++; row++;
                    need = need + 2;
                    l = l - 1;
                    r = r + 1;
                }
                // debug(i, j, result);
            }
        }
        cout << result << endl;
    }
    return 0;
}
