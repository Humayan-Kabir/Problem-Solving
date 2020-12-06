/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-11-29 14:35:35
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 200007

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
    int n; 
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n > 60) {
        cout << 1 << endl;
        return 0;
    }

    int ans = INT_MAX;
    for(int middle = 0; middle < n - 1; middle++) {
        int leftXor = 0;
        for(int j = middle; j >= 0; j--) {
            leftXor ^= arr[j];
            int rightXor = 0;
            for(int k = middle + 1; k < n; k++) {
                rightXor ^= arr[k];
                if(rightXor < leftXor) {
                    ans = min(ans, middle - j + k - middle - 1);
                    debug(j, middle, k);
                }
            }
        }
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}
