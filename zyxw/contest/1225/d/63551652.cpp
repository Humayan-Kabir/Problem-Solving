#include<bits/stdc++.h>
#define mod 1000000007
#define mx 100007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
LL isprime[mx], prime[mx][33], ara[mx], cnt[mx];
vector<int> factor[mx];
void fun() {
    memset(isprime, 1, sizeof isprime);
    for(int i = 4; i < mx; i+=2) {
        isprime[i] = 0;
    }
    for(int i = 3; i < mx; i += 2) {
        if(isprime[i]) {
            for(int j = i + i; j < mx; j+=i) {
                isprime[j] = 0;
            }
        }
    }
    for(int i = 2; i < mx; i++) {
        if(isprime[i]) {
            for(int j = i; j < mx; j+=i) {
                factor[j].push_back(i);
            }
        }
    }
}
int main() { 
    fun();
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        LL need = 1, actual = 1, temp = ara[i], INF = 1e5, flag = 0;
        for(int p : factor[ara[i]]) {
            int cnt = 0;
            while(temp % p == 0) {
                cnt++; temp /= p;
            }
            if(cnt % k == 0) continue;
            cnt = cnt % k;
            for(int j = 1; j <= cnt; j++) {
                actual *= p;
            }
            cnt = k - cnt;
            while(cnt--) {
                need *= p;
                if(need > INF) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0) {
            ans += cnt[need];
        }
        cnt[actual] += 1;
    }
    cout << ans << endl;
    return 0;
}