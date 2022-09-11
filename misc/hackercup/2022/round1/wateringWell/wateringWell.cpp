#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main() {
    freopen("watering_well_chapter_2_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        LL n; scanf("%lld", &n);
        LL tx = 0, txsq = 0, ty = 0, tysq = 0;
        for(int i = 0; i < n; i++) {
            LL px, py; scanf("%lld %lld", &px, &py);
            tx = (tx + px) % mod;
            ty = (ty + py) % mod;
            txsq = (txsq + (px * px) % mod) % mod;
            tysq = (tysq + (py * py) % mod) % mod;
        }
        auto calculateDist = [&](LL sqSum, LL sum, LL p)->LL {
            LL pSq = (p * p) % mod;
            LL middle = (pSq * n) % mod;
            LL add = (sqSum + middle) % mod;
            LL remove = (p * (2LL * sum) % mod) % mod;
            return (add - remove + mod) % mod;
        };
        int q; scanf("%d", &q);
        LL result = 0;
        for(int i = 0; i < q; i++) {
            LL px, py; scanf("%lld %lld", &px, &py);
            result = (result + calculateDist(txsq, tx, px)) % mod;
            result = (result + calculateDist(tysq, ty, py)) % mod;
        }
        printf("Case #%d: %lld\n", test, result);
    }
    return 0;
}
