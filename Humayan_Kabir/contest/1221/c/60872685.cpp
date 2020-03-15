#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false);
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        LL a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        LL x = min(a, b);
        LL low = 0, high = x, ans = 0;
        while(low <= high) {
            LL mid = (low + high) / 2;
            LL baki = a - mid + b - mid;
            if(baki >= mid - c) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
