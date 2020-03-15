#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n;  
    cin >> n;
    int ara[n + 2];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        ans += ara[i];
    }
    int total = ans;
    sort(ara + 1, ara + n + 1);
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= ara[i]; j++) {
            if(ara[i] % j == 0) {
                int temp = total - ara[i] - ara[1] + (ara[i] / j) + ara[1] * j;
                ans = min(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}