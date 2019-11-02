#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
namespace numbers {
    const int modulo = 1e9 + 7;
    int ncr[102][102];
    void combination() {
        ncr[0][0] = 1;
        for(int i = 1; i <= 100; i++) {
            ncr[i][0] = 1;
            for(int j = 1; j <= 100; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % modulo;
            }
        }
    }
    void solve() {
        combination();
        int n, a[10];
        scanf("%d", &n);
        for(int i = 0; i < 10; i++) {
            scanf("%d", a + i);
        }
        int ans = 0;
        for(int firstDigit = 1; firstDigit <= 9; firstDigit++) {
            int change = (a[firstDigit] > 0);
            a[firstDigit] -= change;
            int ways[n] = {0};
            ways[0] = 1;
            for(int digit = 0; digit < 10; digit++) {
                int nways[n] = {0};
                for(int oldlen = 0; oldlen < n; oldlen++) {
                    if(ways[oldlen]) {
                        for(int use = a[digit]; use + oldlen < n; use++) {
                            nways[use + oldlen] = (int)(nways[use + oldlen] + 1LL * ways[oldlen] * ncr[use + oldlen][use] % modulo) % modulo;
                        }
                    }
                }
                for(int i = 0; i < n; i++) {
                    ways[i] = nways[i];
                }
            }
            for(int i = 0; i < n; i++) {
                ans = (ans + ways[i]) % modulo;
            }
            a[firstDigit] += change;
        }
        printf("%d\n", ans);
    }
}
int main() {
    numbers::solve();
    return 0;
}