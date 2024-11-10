/*
 * Author: M.Humayan
 * Time: 2024-10-05
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
typedef long long int LL;
const int N = 10000007;
bool is_prime[N];
void init() {
    for(int i = 0; i < N; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    vector<pair<int,int>> q;
    for(int test = 1; test <= t; test++) {
        int n; cin >> n;
        q.push_back({n, test});
    }
    sort(q.begin(), q.end());
    vector<int> result(t + 1);
    int cur = 2;
    int ans = 0;
    for(auto [n, q]: q) {
        while(cur + 2 <= n) {
            if (is_prime[cur] && is_prime[cur + 2]) {
                ans++;
            }
            cur++;
        }
        result[q] = ans;
    }
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << result[i] << endl;
    }
    return 0;
}