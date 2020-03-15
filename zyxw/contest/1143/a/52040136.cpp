#include <bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int n, root, ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x = 0, y = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(ara[i] == 0) x++;
        else y++;
    }
    int ans;
    for(int i = 1; i <= n; i++) {
        if(ara[i] == 0) x--;
        else y--;
        if(x == 0 || y == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
