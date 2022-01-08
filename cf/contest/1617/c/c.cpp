/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-12-16 21:36:55
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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> mark(n + 2, 0);
        unordered_set<int> myset;
        int counter = 0;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num <= n && myset.find(num) == myset.end()) {
                counter++;
                mark[num]++;
                mark[num + 1]--;
                myset.insert(num);
            } else {
                int right = min((num / 2) + 1, n + 1);
                mark[1]++;
                mark[right]--;
            }
        }
        bool isOk = true;
        for(int i = 1; i <= n; i++) {
            mark[i] += mark[i - 1];
            if (!mark[i]) {
                isOk = false;
            }
        }
        if (isOk) {
            cout << n - counter << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}