/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-16 20:44:59
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

string getAns(string str, int pos) {
    string ans = "";
    int len = str.length();
    for(int i = 0; i < len; i++) {
        int x = str[i] - '0';
        int y = str[i + 1] - '0';
        if (i == pos) {
            int sum = (x + y);
            int v = sum % 10, u = ((sum / 10) % 10);
            char uu = '0' + u;
            char vv = '0' + v;
            if (sum >= 10) {
                ans += uu;
                ans += vv;
            } else {
                ans += vv;
            }
            continue;
        }
        if(i == pos + 1) continue;
        ans += str[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        int len = str.length();
        string ans = "";
        int greaterPos = -1, equalPos = -1, found = -1;
        for(int i = 0; i < len - 1; i++) {
            int x = str[i] - '0';
            int y = str[i + 1] - '0';
            if (x + y >= 10) {
                int sum = (x + y);
                int v = sum % 10, u = ((sum / 10) % 10);
                if (u > x || v > y) {
                    greaterPos = i;
                    break;
                }
                if (u >= x && v >= y) {
                    equalPos = i;
                }
                found = i;
            }
        }
        if (greaterPos == -1 && equalPos == -1 && found == -1) {
            for(int i = 0; i < len - 1; i++) {
                int x = str[i] - '0';
                int y = str[i + 1] - '0';
                if (x + y > x) {
                    greaterPos = i;
                    break;       
                }
                if (x + y >= x) {
                    equalPos = i;
                }
            }
        }
        if (greaterPos != -1) {
            cout << getAns(str, greaterPos) << endl;
        } else if (equalPos != -1) {
            cout << getAns(str, equalPos) << endl;
        } else if (found != -1) {
            cout << getAns(str, found) << endl;
        } else {
            cout << getAns(str, len - 2) << endl;
        }
    }    
    return 0;
}
