/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-08 21:11:10
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
int arr[300007];
int check(int i) {
    int contribution = 0;
    if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        contribution = 1;
    }
    if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
        contribution = 1;
    }
    return contribution;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> sum(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if(n < 3) {
            cout << 0 << endl;
            continue;
        }
        int total = 0;
        for(int i = 1; i < n - 1; i++) {
            sum[i] = check(i);
            total += sum[i];
        }

        int ans = total;

        for(int i  = 1; i < n - 1; i++) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            int add1 = 0, add2 = 0;
            for(int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
                add1 += check(j);
                add1 -= sum[j];
            }
            arr[i] = arr[i + 1];
            for(int j = max(1, i - 1); j <= min(n - 2, i + 1); j++) {
                add2 += check(j);
                add2 -= sum[j];
            }
            arr[i] = temp;
            
            ans = min(ans, min(total + add1, total + add2));
        }
        cout << ans << endl;
    }
    return 0;
}
