#include<bits/stdc++.h>
using namespace std;
#define mx 200007
typedef long long int LL;
int ara[mx];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    sort(ara + 1, ara + n + 1);
    int pre = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ara[i] > pre) {
            pre++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
