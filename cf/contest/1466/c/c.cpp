/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-12-30 21:29:34
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        str = "#*" + str + "*#";
        int len = str.length(), ans = 0;
        for(int i = 2; i < len - 2; i++) {
            if(str[i] == str[i - 1] ||  str[i] == str[i - 2]) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch != str[i - 1] && ch != str[i - 2] && ch != str[i + 1] && ch != str[i + 2]) {
                        str[i] = ch;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
