/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-12-30 20:36:01
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
typedef long long int LL;
const int N = 100007;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
       int n; cin >> n;
       string str; cin >> str;
       vector<int> v[26];
       int max_char = 0;
       for(int i = 0; i < n; i++) {
            int id = str[i] - 'a';
            v[id].push_back(i);
            max_char = max(max_char, id);
       }
       int lp = -1;
       vector<int> s;
       for(char ch = 'z'; ch >= 'a'; ch--) {
            int id = ch - 'a';
            for(int p : v[id]) {
                if (p > lp) {
                    s.push_back(p);
                    lp = p;
                } 
            }
       } 
       int m = s.size();
       for(int i = 0, j = m - 1; i * 2 < m; i++, j--) {
            swap(str[s[i]], str[s[j]]);
       }
       int sorted = 1;
       for(int i = 1; i < n; i++) {
            if (str[i] < str[i - 1]) {
                sorted = 0;
                break;
            }
       }
       if (sorted) {
            cout << m - v[max_char].size() << endl;
       } else {
            cout << -1 << endl;
       }
    }
    return 0;
}