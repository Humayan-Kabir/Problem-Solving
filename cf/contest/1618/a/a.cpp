/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-12-14 21:02:04
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

vector<int> getSequence(vector<int> vt) {
    vector<int> ans;
    for(int i = 0; i < vt.size(); i++) {
        ans.push_back(vt[i]);
        for(int j = i + 1; j < vt.size(); j++) {
            ans.push_back(vt[i] + vt[j]);
        }
    }
    ans.push_back(vt[0] + vt[1] + vt[2]);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n = 7;
        vector<int> vt(n);
        for(int i = 0; i < n; i++) {
            cin >> vt[i];
        }
        int found = 0;
        for(int i = 0; i < 7 && !found; i++) {
            for(int j = i + 1; j < 7 && !found; j++) {
                for(int k = j + 1; k < 7 && !found; k++) {
                    if (vt == getSequence({vt[i], vt[j], vt[k]})) {
                        found = 1;
                        cout << vt[i] << " " << vt[j] <<" " << vt[k] << endl;
                    }
                }
            }
        }
    }
    return 0;
}