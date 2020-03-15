#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL isPrime[mx];
void sieve() {
    for(int i = 4; i < mx; i+=2) {
        isPrime[i] = 1;
    }
    int root = sqrt(mx);
    for(int i = 3; i <= root; i += 2) {
        if(!isPrime[i]) {
            for(int j = i + i; j < mx; j += i) {
                isPrime[j] = 1;
            }
        }
    } 
}
LL bigmod(LL a, LL p) {
    if(p == 0) {
        return 1LL;
    }
    LL x = bigmod(a, p/2) % mod;
    x = (x * x) % mod;
    if(p % 2 == 1) {
        x = (x * a) % mod;
    }
    return x;
}
LL ar[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    sieve();
    LL x, n;
    cin >> x >> n;
    vector<LL> vt;
    LL root = sqrt(x), temp = x;
    LL ans = 1;
    root = max(root, 2LL);
    for(LL i = 2; i <= root; i++) {
        if(isPrime[i] == 0) {
            int f = 0;
            while(temp > 0 && temp % i == 0) {
                temp = temp / i;
                f = 1;
            }
            if(f) {
                vt.push_back(i);
            }
        }
    }
    if(temp > 2) {
        vt.push_back(temp);
    }
    for(LL p : vt) {
        LL high = n, low = 1, cnt = 0;
        while(high >= p) {
            low = low * p;
            high = high / p;
            cnt++;
        }
        LL sum = 0;
        while(low > 0) {
            LL v = (n / low) - sum;
            sum += v;
            ans = ans * bigmod(p, cnt * v);
            low = low / p;
            ans = ans % mod;
            cnt--;
        }
    }
    cout << ans << endl;
    return 0;
}
