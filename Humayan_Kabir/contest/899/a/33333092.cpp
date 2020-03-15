/*input
7
2 2 2 1 1 1 1
*/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int one = 0, two = 0;
    for(int i = 1; i<=n; i++)
    {
        int x;
        cin >> x;
        if(x == 1) one++;
        else two++;
    }
    int ans = min(one,two);
    one = one - ans;
    ans+=(one/3);
    cout << ans << endl;
    return 0;
}
