#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int sum[12][120][120]= {0};
void BIT_UPDATE(int c,int x,int idx,int val)
{
    while (idx<=100)
    {
        sum[c][x][idx]+=val;
        idx+=(idx&(-idx));
    }
}
int BIT_QUERY(int c,int x,int idx)
{
    int total=0;
    while (idx>0)
    {
        total+=(sum[c][x][idx]);
        idx-=(idx&(-idx));
    }
    return total;
}
int main()
{
    int n,q,c;
    scanf("%d %d %d",&n,&q,&c);
    for(int i=1; i<=n; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        for(int j=0; j<=c; j++)
        {
            int m=(w+j)%(c+1);
            BIT_UPDATE(j,u,v,m);
        }
    }

    while (q--)
    {
        int ans=0;
        int x1,x2,y1,y2,t1;
        scanf("%d %d %d %d %d",&t1,&x1,&y1,&x2,&y2);
        int v=(t1%(c+1));
        int x=min(x1,x2);
        x1=max(x1,x2);
        int y=min(y1,y2);
        y1=max(y1,y2);
        for(int i=x; i<=x1; i++)
        {
            ans+=BIT_QUERY(v,i,y1)-BIT_QUERY(v,i,y-1);
        }

        printf("%d\n",ans);
    }

    return 0;
}
