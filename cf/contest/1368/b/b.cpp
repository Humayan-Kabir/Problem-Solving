/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-22 21:49:36
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void __print(int x)
{
    cerr << x;
}
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

int main()
{
    ios_base::sync_with_stdio(false);
    typedef long long int LL;
    LL k;
    cin >> k;
    string s = "codeforces";
    vector<int> count(s.length(), 1);
    LL product = 1;
    while(product < k) {
        for(int i = 0; i < count.size() && product < k; i++) {
            product /= count[i];
            count[i]++;
            product *= count[i];
        }
    }

    string ans = "";
    for(int i = 0; i < count.size(); i++) {
        while(count[i]--) ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
