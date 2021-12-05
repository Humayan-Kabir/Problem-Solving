/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-12-01 20:36:19
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

const int MAX = 1000010;

vector<int> vt[2];

void assign(int idx, int x) {
    stack<int> stk;
    while(x > 0) {
        stk.push(x % 10);
        x /= 10;
    }
    while(!stk.empty()) {
        vt[idx].push_back(stk.top());
        stk.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        assign(0, x1);
        assign(1, x2);
        int len1 = vt[0].size() + p1;
        int len2 = vt[1].size() + p2;
        string ans;
        if (len1 == len2) {
            ans = "=";
          //  debug(len1, len2);
            for(int i = 0; i < len1; i++) {
                if (i > 10) break;
                int x = 0, y = 0;
                if (i < vt[0].size()) {
                    x = vt[0][i];
                }
                if (i < vt[1].size()) {
                    y = vt[1][i];
                }
                if (x < y) {
                    ans = "<";
                    break;
                }
                if (x > y) {
                    ans = ">";
                    break;
                }
               // debug(x, y);
            }
        } else {
            if (len1 > len2) {
                ans = ">";
            } else {
                ans = "<";
            }
        }
        vt[0].clear();
        vt[1].clear();
        cout << ans << endl;
    }
    return 0;
}