#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL n, h, ara[2001], dp[2001][2001];
LL rec(LL pos, LL opened) {
    if(pos == n) {
        return opened == 0;
    }
    LL &ret = dp[pos][opened], now = 0;
    if(ret != -1) return ret;
    now = (now + rec(pos + 1, opened) * (ara[pos] + opened == h)) % mod;
    if(opened > 0)
    now = (now + 1LL * opened * rec(pos + 1, opened - 1) * (ara[pos] + opened == h)) % mod;
    if(opened > 0)
    now = (now + 1LL * opened * rec(pos + 1, opened) * (ara[pos] + opened == h - 1)) % mod;
    now = (now + rec(pos + 1, opened) * (ara[pos] + opened == h - 1)) % mod;
    now = (now + rec(pos + 1, opened + 1) * (ara[pos] + opened == h - 1)) % mod;
    return ret = now; 
}
int main(int argc, char const *argv[])
{
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0) << endl;
    return 0;
}
