#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int p[10009],vis[100009];
void parent(int n)
{
    for (int i=1; i<=n ; i++ )
    {
        p[i]=i;
    }
}

int find_par(int r)
{
    if(p[r]==r) return r;
    p[r]=find_par(p[r]);
    return p[r];
}
void Union(int x,int y)
{
    int u,v;
    u=find_par(x);
    v=find_par(y);
    if(u!=v)
    p[u]=v;
}
int main()
{
    int i,j,k,n,flag=0;
    sf1(n);
    parent(n);
    for (i=1; i<=n ; i++ )
    {
        sf1(k);
        if(find_par(k)!=find_par(i))
        Union(k,i);
    }
    memset(vis,0,sizeof vis);
    for (i=1; i<=n ; i++ )
    {
        int u=find_par(i);
        if(vis[u]==0)
        {
            vis[u]=1;
            flag++;
        }
    }
    cout<<flag<<endl;
    return 0;
}
