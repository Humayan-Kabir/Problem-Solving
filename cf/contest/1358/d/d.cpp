/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-05-26 21:05:30
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 400007
using namespace std;
typedef long long int LL;
LL arr[mx], cost[mx], sum[mx];
LL fun(LL x) {
    return ((x * (x + 1)) / 2LL);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[n + i] = arr[i];
    } 
    for(int i = 1; i <= 2 * n; i++) {
        cost[i] = cost[i - 1] + (arr[i] * (arr[i] + 1)) / 2;
        sum[i] = sum[i - 1] + arr[i];
    }
    LL ans = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(arr[i] >= x) {
            LL curans = fun(arr[i]) - fun(arr[i] - x);
            ans = max(ans, curans);
        }
        int low = i, high = 2 * n, found = 0;
        while(low <= high) {
            int mid = (low + high) / 2LL;
            if(sum[mid] - sum[i - 1] >= x) {
                found = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(found != i && (found - i + 1) <= n) {
            if(sum[found] - sum[i - 1] == x) {
                ans = max(ans, cost[found] - cost[i - 1]);
            } else if(sum[found] - sum[i - 1] > x) {
                LL has = sum[found] - sum[i - 1] - x;
                LL cur = x - (sum[found - 1] - sum[i - 1]);
                LL cangive = arr[i] - 1;
                LL exch = min(has, cangive);
                LL res = fun(cur + exch) + fun(arr[i]) - fun(exch);
                if(found - 1 >= i) {
                    res += (cost[found - 1] - cost[i]);
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}