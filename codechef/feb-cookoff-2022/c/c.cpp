/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-02-21 21:40:16
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
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        if (str[0] == '0' || str[n] == '0') {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            vector<int> ans;
            for(int i = 0; i < n; ) {
                if (str[i] == '1') {
                    ans.push_back(i);
                    i++;
                } else {
                    int temp = ans.back();
                    ans.pop_back();
                    while(str[i] == '0') {
                        ans.push_back(i);
                        i++;
                    }
                    ans.push_back(temp);
                }
            }
            for(int i = 0; i < ans.size(); i++) {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }

    }
    return 0;
}