/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-03-20 18:00:34
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

unordered_map<int, int> hashMap;
int n, counter, operation;

void rec(LL total) {
    if (hashMap.find(total) != hashMap.end() && hashMap[total] > 0) {
        counter += 1;
        hashMap[total] -= 1;
        return;
    }
    if (total == 1 || operation == n - 1) {
       return;
    }
    operation++;
    LL left = total / 2LL;
    LL right = (total + 1) / 2LL;
    rec(left); rec(right);
}

int main() {
    int t; cin >> t;
    while(t--) {
        hashMap.clear();
        LL total = 0; cin >> n;
        for(int i = 0; i < n; i++) {
            int num; cin >> num;
            total += num;
            hashMap[num]++;
        }
        counter = 0; operation = 0;
        rec(total);
        if (counter == n) {
            cout << "YES" << endl;
        } else {    
            cout << "NO" << endl;
        }
    }
    return 0;
}