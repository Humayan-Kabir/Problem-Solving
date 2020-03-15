#include<bits/stdc++.h>
#define mx 100003
using namespace std;
int ara[mx], dp[mx];
vector<int> divisor[mx];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
        scanf("%d",&ara[i]);
    for(int i = 2; i<mx; i++)
    {
        for(int j = i; j<mx; j+=i)
        {
            divisor[j].push_back(i);
        }
    }
    for(int i = 1; i<=n; i++)
    {
        int now = 0;
        for(int f : divisor[ara[i]])
        {
            now = max(now, 1 + dp[f]);
        }
        for(int f : divisor[ara[i]])
        {
           dp[f] = now;
        }
    }
    int ans = 1;
    for(int i = 2; i<mx; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
