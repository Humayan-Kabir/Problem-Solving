/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-29 21:19:51
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
        int n, k;
        cin >> n >> k;
        vector<LL> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        LL low = 0, high = (LL) 1e12;
        LL ans = high;

        while(low <= high) {
            LL mid = (low + high) / 2LL;
            LL total = arr[0] + mid, flag = 1;
            for(int i = 1; i < n; i++) {
                if(arr[i] * 100 <= total * k) {
                    total += arr[i];
                    continue;
                } else {
                    flag = 0; 
                    break;
                }
            }
            if(flag) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
