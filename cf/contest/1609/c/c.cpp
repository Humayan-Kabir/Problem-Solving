/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-11-28 21:49:34
 * SUST CSE '15
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const int MAX_NUM = 1000001;
const int MAX_N = 200007;

bool isPrime[MAX_NUM];

void init_prime() {
    isPrime[1] = true;
    for(int i = 4; i < MAX_NUM; i += 2) {
        isPrime[i] = true;
    }
    int sq = sqrt(MAX_NUM);
    for(int i = 3; i <= sq; i += 2) {
        if (!isPrime[i]) {
            for(int j = i * i; j < MAX_NUM; j += i) {
                if (j >= MAX_NUM) {
                    cout << i << " .... " << j << endl;
                    break;
                }
                isPrime[j] = true;
            }
        }
    }

}

int arr[MAX_N];
int dp[MAX_N];
int nextPrime[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    init_prime();
    int t;
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        dp[n + 1] = 0;
        nextPrime[n + 1] = n + 1;
        long long int ans = 0;
        for(int i = n; i >= 1; i--) {
            if (!isPrime[arr[i]]) {
                nextPrime[i] = i;
            } else if (arr[i] == 1){
                nextPrime[i] = nextPrime[(i + e) > n ? n + 1: i + e];
            } else {
                nextPrime[i] = n + 1;
            }
            if (arr[i] == 1) {
                dp[i] = 1 + dp[(i + e) > n ? n + 1: i + e];
            } else if (!isPrime[arr[i]]){
                dp[i] = 0;
            } else {
                dp[i] = 0;
            }
            if (!isPrime[arr[i]]) {
                ans += dp[(i + e) > n ? n + 1: i + e];
            } else if (arr[i] == 1){
                int idx = nextPrime[i];
                if (nextPrime[i] <= n) {
                    ans = ans + 1 + dp[(idx + e) > n ? n + 1: idx + e];
                }
            }
        }        
        cout << ans << endl;
    }
    return 0;
}