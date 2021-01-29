/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-28 21:45:33
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
        vector<LL> vt(2 * n);
        vector<LL> arr(2 * n);
        for(int i = 0; i < 2 * n; i++) cin >> vt[i];
        sort(vt.rbegin(), vt.rend());
        int left = 0, right = 2 * n - 1;
        // debug(vt);
        for(int i = 0; i < n; i++) {
            arr[left++] = vt[2 * i];
            arr[right--] = vt[2 * i + 1];
        }
        vt = arr;
        int flag = 1;
        for(int i = 0, j = 2 * n - 1; i < n; i++, j--) {
            if(arr[i] != arr[j]) flag = 0;
        } 
        vector<LL> hudai;
        for(int i = 2; i <= n + 1; i++) {
            LL rem = (vt[i - 1] - vt[i - 2]);
            LL divide = -2 * (n - i + 1);
            LL x = (LL) rem / (LL)divide;
            debug(rem, divide, x);
            if((x * divide) == rem && x > 0) {
                hudai.push_back(x);
                continue;
            } else {
                flag = 0;
                break;
            }
        }
        if(n > 1) {
            for(int i = 1; i < n; i++) {
                hudai.push_back(vt[i - 1]);
            }
            LL sum = 0, total = 0;
            for(LL x : hudai) {
                sum += x;
                total += sum;
            }
            if(total != vt[0]) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
