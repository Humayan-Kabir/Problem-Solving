#include<bits/stdc++.h>
using namespace std;
const int mx = 24;
typedef long long int LL;
int ara[1<<mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        int mask = 0;
        for(int i = 0; i < 3; i++) {
            mask = mask | (1 << (str[i] - 'a'));
        }
        ara[mask]++;
    }
    for(int i = 0; i < mx; i++) {
        for(int j = 0; j < (1<<mx); j++) {
            if(j & (1 << i)) {
                ara[j] += ara[j ^ (1 << i)];
            }
        }
    }
    LL ans = 0;
    for(int i = 0; i < (1 << 24); i++) {
       LL x = 1LL*n - 1LL * ara[(1 << 24) - 1 - i];
       x = x * x;
       ans = ans ^ x;
    }
    cout << ans << endl;
    return 0;
}
