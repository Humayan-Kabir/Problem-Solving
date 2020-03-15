#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
string str;
LL ara[mx][2];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> str;
    LL lasta = 0, lastb = 0, aa = 0, bb = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(str[i - 1] == 'A') {
            str[i - 1] = 'a';
        }
        if(str[i - 1] == 'B') {
            str[i - 1] = 'b';
        }
        if(i == 1) {
            if(str[i - 1] == 'a') {
                lasta = i;
            }
            if(str[i - 1] == 'b') {
                lastb = i;
            }
            ara[i][0] = lasta;
            ara[i][1] = lastb;
            continue;
        }
        if(str[i - 1] == 'a') {
            lasta = i;
        }
        if(str[i - 1] == 'b') {
            lastb = i;
        }
        ara[i][0] = lasta;
        ara[i][1] = lastb;
        if(str[i - 1] == 'a' && str[i - 2] == 'a') {
            aa = i - 1;
        }
        if(str[i - 1] == 'b' && str[i - 2] == 'b') {
            bb = (i - 1);
        }
        LL to = min(aa, bb);
        if(str[i - 1] == 'a') {
            ans += max(0LL, (i - lastb - 1));
            LL now = ara[lastb][0];
            ans += max(0LL, max(to, now));
        }
        else {
            ans += max(0LL, (i - lasta - 1));
            LL now = ara[lasta][1];
            ans += max(0LL, max(to, now));
        }
       // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}