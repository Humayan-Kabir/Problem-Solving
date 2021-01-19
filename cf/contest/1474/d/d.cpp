/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-19 21:55:32
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
        vector<int> a(n + 2, 0);
        vector<pair<int,int>> b(n + 2, {0, 0});
        vector<pair<int,int>> c(n + 2, {0, 0});
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        b[0] = {1, 0};
        b[1] = {1, a[1]};

        for(int i = 2; i <= n; i++) {
            if(b[i - 1].second <= a[i]) {
                b[i] = {b[i - 1].first & 1, a[i] - b[i - 1].second};
            } else {
                b[i] = {0, INT_MAX};
            }
        }

        c[n + 1] = {1, 0};
        c[n] = {1, a[n]};

        for(int i = n - 1; i >= 1; i--) {
            if(c[i + 1].second <= a[i]) {
                c[i] = {c[i + 1].first & 1, a[i] - c[i + 1].second};
            } else {
                c[i] = {0, INT_MAX};
            }
        }

        int found = 0;
        for(int i = 2; i <= n; i++) {
            if(b[i - 1].first && c[i].first && b[i - 1].second == c[i].second) {
                found = 1;
                break;
            } else {
                if(b[i - 2].first && c[i + 1].first) {
                    if(b[i - 2].second <= a[i] && c[i + 1].second <= a[i - 1]) {
                        if(abs(a[i] - b[i - 2].second) == abs(a[i - 1] - c[i + 1].second)) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}