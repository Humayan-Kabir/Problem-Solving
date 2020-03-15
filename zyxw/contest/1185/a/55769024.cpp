#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    LL ara[5];
    cin >> ara[1] >> ara[2] >> ara[3];
    LL d, ans = 0;
    cin >> d;
    sort(ara + 1, ara + 1 + 3);
    LL left = ara[2] - ara[1], right = ara[3] - ara[2];
    if(left < d) {
        ans += (d - left);
    }
    if(right < d) {
        ans += (d - right);
    }
    cout << ans << endl;
    return 0;
}