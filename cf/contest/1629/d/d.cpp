/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-01-22 21:48:56
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

map<string, bool> hashMapLen1;
map<string, bool> hashMapLen2;
map<string, bool> hashMapLen3;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        hashMapLen1.clear();
        hashMapLen2.clear();
        hashMapLen3.clear();
        int flag = false;
        for(int i = 0; i < n; i++) {
            string str; cin >> str; 
            int len = str.length();
            if (len == 1) {
                flag = 1; 
                continue;
            }
            else if (len == 2) {
                hashMapLen2[str] = true;
                reverse(str.begin(), str.end());
                if (hashMapLen2.find(str) != hashMapLen2.end()) {
                    flag = 1; continue;
                } 
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    string key = str + ch;
                    if (hashMapLen3.find(key) != hashMapLen3.end()) {
                        flag = 1; continue;
                    } 
                }
            } else {
                hashMapLen3[str] = true;
                reverse(str.begin(), str.end());
                if (hashMapLen3.find(str) != hashMapLen3.end()) {
                    flag = 1; continue;
                } 
                string temp = str.substr(0, 2);
                if (hashMapLen2.find(temp) != hashMapLen2.end()) {
                    flag = 1; continue;
                } 
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}