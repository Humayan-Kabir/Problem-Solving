#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL getSum(LL n) {
    return (n * (n + 1)) / 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    LL t; cin >> t;
    while(t--) {
        LL n; cin >> n;
        LL low = 1, high = n, foundAt;
        while(low <= high) {
            LL mid = (low + high) / 2;
            if (getSum(mid) >= n) {
               foundAt = mid;
               high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        LL rem = n - getSum(foundAt - 1);
        printf("%lld %lld\n", foundAt - rem + 1, rem);
    }
    return 0;
}