/*input
3 6
2 3 5
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    int ans = INT_MAX;
    for(int i = 1; i<=n; i++)
    {
        int a;
        cin >> a;
        if(k % a == 0)
        {
            ans = min(ans,k/a);
        }
    }   
    cout << ans << endl;
    return 0;
}