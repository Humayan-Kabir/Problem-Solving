/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-14 21:09:25
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
        int n, q;
        cin >> n >> q;
        vector<int> sum(n + 2, 0);
        vector<pair<int,int>> fromLeft(n + 2, make_pair(INT_MAX, INT_MIN));
        vector<pair<int,int>> fromRight(n + 2, make_pair(INT_MAX, INT_MIN));
        string str;
        cin >> str;
        for(int i = 1; i <= n; i++) {
            if(str[i - 1] == '+') {
                sum[i] = sum[i - 1] + 1;
            } else {
                sum[i] = sum[i - 1] - 1;
            }
        }

        fromLeft[0] = {0, 0};
        fromRight[n + 1] = {sum[n], sum[n]};

        for(int i = 1; i <= n; i++) {
            fromLeft[i].first = min(fromLeft[i - 1].first, sum[i]);
            fromLeft[i].second = max(fromLeft[i - 1].second, sum[i]);
        }

        for(int i = n; i >= 1; i--) {
            fromRight[i].first = min(fromRight[i + 1].first, sum[i]);
            fromRight[i].second = max(fromRight[i + 1].second, sum[i]);
        }

        while(q--) {
            int l, r;
            cin >> l >> r;
            vector<int> res;
            res.push_back(fromLeft[l - 1].first);
            res.push_back(fromLeft[l - 1].second);
            int rightMin = fromRight[r + 1].first - sum[r] + sum[l - 1];
            int rightMax = fromRight[r + 1].second - sum[r] + sum[l - 1];
            // debug(res);
            res.push_back(rightMin);
            res.push_back(rightMax);
            // debug(res);
            sort(res.begin(), res.end());

            cout << res[3] -res[0] + 1 << endl;
        }
    }
    return 0;
}
