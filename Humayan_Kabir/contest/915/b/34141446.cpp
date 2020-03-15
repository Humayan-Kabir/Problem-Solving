/*input
6 3 1 3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n,pos,l,r;
    cin >> n >> pos >> l >> r;
    int ans = 0;
    if(pos>=l && pos<=r)
    {
        int lbaki = l - 1;
        int rbaki = n - r;
        if(lbaki == 0 && rbaki == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if(lbaki == 0 && rbaki > 0)
        {
            ans = r - pos + 1;
            cout << ans << endl;
            return 0;
        }
        if(rbaki == 0 && lbaki > 0)
        {
            ans = pos - l + 1;
            cout << ans << endl;
            return 0;
        }
        if((pos - l <= r - pos))
        {
            ans = pos - l + 1;
            if(rbaki > 0) ans += (r - l + 1);
        }
        else
        {
            ans = r - pos + 1;
            if(lbaki > 0) ans += (r - l + 1);
        }
        cout << ans << endl;
        return 0;
    }
    else
    {
        if(pos < l)
        {
            ans = l - pos + 1;
            if(n - r > 0)
            {
                ans+=(r - l + 1); 
            }
        }
        else if(pos > r)
        {
            ans += (pos - r + 1);
            if(l - 1 > 0)
                ans+=(r - l + 1);
        }
        cout << ans << endl;
    }
    return 0;
}