/* بسم الله الرحمن الرحيم
 * Author: ElderWand
 * Time: 2020-09-10 22:18:42
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

void NCR(int combination[11][11]) {
    combination[0][0] = 1;
    for(int i = 1; i <= 10; i++) {
        combination[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int combination[11][11] = {0};
    NCR(combination);

    string strA, strB;
    cin >> strA >> strB;
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < strA.length(); i++) {
        if(strA[i] == '+') x++;
        else x--;
        if(strB[i] == '+') y++;
        else if(strB[i] == '-') y--;
        else z++;
    }
    double ans = 0.0;
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            if(i + j == z && abs(i - j) == abs(x - y)) {
                ans = 1.0 * combination[z][i] / (1 << z);
                cout << setprecision(10) << fixed << ans << endl;
                return 0;
            }
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}
