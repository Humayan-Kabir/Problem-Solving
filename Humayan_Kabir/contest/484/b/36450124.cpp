#include<bits/stdc++.h>
#define mx 1000007
using namespace std;
int ara[mx], mark[mx], kthElement[mx], vis[1000007];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
        mark[ara[i]]++;
    }
    for(int i = 1; i<=1000000; i++)
    {
        if(mark[i] == 0) mark[i] = mark[i-1];
        else mark[i] = mark[i - 1] + mark[i];
    }
    sort(ara + 1, ara + n + 1);
    int ans = 0;
    for(int i = 1; i<=n; i++)
    {
        if(vis[ara[i]] ) continue;
        vis[ara[i]] = 1;

        for(int j = ara[i]; j<=1000000; j+=ara[i])
        {
            if(ara[mark[j]] >= ara[i]) ans = max(ans, ara[mark[j]] % ara[i]);
            if(ara[mark[j] - 1] >= ara[i]) ans = max(ans, ara[mark[j] - 1] % ara[i]);
            if(ara[mark[j] + 1] >= ara[i]) ans = max(ans, ara[mark[j] + 1] % ara[i]);
        }
        ans = max(ans, ara[n] % ara[i]);
    }
    cout << ans << endl;
    return 0;
}
