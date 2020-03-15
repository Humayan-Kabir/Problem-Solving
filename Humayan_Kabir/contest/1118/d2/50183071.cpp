#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
vector <LL> ara;
int main(int argc, char const *argv[])
{
    LL n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        LL num;
        cin >> num;
        ara.push_back(num);
    }
    sort(ara.rbegin(), ara.rend());
    LL low = 1, high = n, ans = n + 1;
    while(low <= high) {
        LL mid = (low + high) / 2;
        LL total = 0;
        for(int i = 1; i <= n; i++) {
            LL x = ara[i - 1];
            LL y = (i + mid - 1) / mid;
            y = y - 1;
            total += max(0LL, x - y);
        }
        if(total >= m) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    if(ans > n) ans = -1;
    cout << ans << endl;
    return 0;
}