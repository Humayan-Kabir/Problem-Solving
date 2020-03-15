#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL sum[12][120][120]= {0};
int main()
{
    // ios_base::sync_with_stdio(false);
    LL n,q,c;
    scanf("%lld %lld %lld",&n,&q,&c);
    for(int i=1; i<=n; i++)
    {
        LL u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        for(int i=0; i<=c; i++)
        {
            sum[i][u][v]+=((w+i)%(c+1));
        }
    }

    for(int i=0; i<=c; i++)
    {
        for(int j=1; j<=100; j++)
        {
            for(int k=1; k<=100; k++)
            {
                sum[i][j][k]+=sum[i][j][k-1];
            }
        }
    }

    while (q--)
    {
        LL ans=0;
        LL x1,x2,y1,y2,t1;
        scanf("%lld %lld %lld %lld %lld",&t1,&x1,&y1,&x2,&y2);
        LL v=(t1%(c+1));
        LL x=min(x1,x2);
        x1=max(x1,x2);
        LL y=min(y1,y2);
        y1=max(y1,y2);
        for(int i=x; i<=x1; i++)
        {
            ans+=(sum[v][i][y1]-sum[v][i][y-1]);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
