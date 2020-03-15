#include<bits/stdc++.h>
#define mod 1000000007
#define mx 150007
using namespace std;
typedef long long int LL;
int dp[mx][4][4], vis[mx][4][4], TImer = 0, len;
string str;
string a = "one";
string b = "two";
int ans;
int rec(int pos, int x, int y) {
    // cout << pos << " " << x << " " << y << endl;
    if(x == 3 || y == 3) {
        return len + 1;
    }
    if(pos == len) {
        return 0;
    }
    int &ret = dp[pos][x][y];
    int &vv = vis[pos][x][y];
    if(vv == TImer) return ret;
    vv = TImer;
    int now = 1e7;
    int u = 0, v = 0, m = 0, n = 0;
    if(str[pos] == 'o') u = 1;
    if(str[pos] == 't') v = 1;
    if(str[pos] == a[x]) m = 1;
    if(str[pos] == b[y]) n = 1;
    now = min(now, rec(pos + 1, ((x + m) * m) + (m == 0? u: 0), ((y + n) * n) + (n == 0? v: 0)));
    now = min(now, 1 + rec(pos + 1, x, y));
    return ret = now;
}
void solution(int pos, int x, int y) {
    // cout << pos << " " << x << " " << y << endl;
    if(x == 3 || y == 3) {
        return;
    }
    if(pos == len) {
        return;
    }
    if(ans == 0) {
        return;
    }
    int now = 1e7;
    int u = 0, v = 0, m = 0, n = 0;
    if(str[pos] == 'o') u = 1;
    if(str[pos] == 't') v = 1;
    if(str[pos] == a[x]) m = 1;
    if(str[pos] == b[y]) n = 1;
    now = min(now, rec(pos + 1, ((x + m) * m) + (m == 0? u: 0), ((y + n) * n) + (n == 0? v: 0)));
    if(now == ans) {
        solution(pos + 1, ((x + m) * m) + (m == 0? u: 0), ((y + n) * n) + (n == 0? v: 0));
        return;
    }
    now = min(now, 1 + rec(pos + 1, x, y));
    if(now == ans) {
        cout << pos + 1 << " ";
        ans--;
        solution(pos + 1, x, y);
        return;
    }
    return;
}
int main() { 
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        TImer++;
        cin >> str;
        len = str.length();
        int ret = rec(0,0,0);
        if(ret == 0) {
            cout << "0" << endl;
            cout << "\n" << endl;
        }
        else {
            cout << ret << endl;
            ans = ret;
            solution(0, 0, 0);
            cout << endl;
        }
    }
    return 0;
}