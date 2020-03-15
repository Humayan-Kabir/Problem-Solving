#include<bits/stdc++.h>
#define mx 100007
#define sq 320
using namespace std;
vector<int> graph[mx];
int timer,ans[mx],color[mx],st[mx],en[mx],color_cnt[mx],tree[mx],conv_ara[mx];

struct MO
{
    int l,r,id,k;
    inline bool operator<(const MO &a) const
    {
        int x=l/sq;
        int y=a.l/sq;
        if(x!=y) return x<y;
        if(x&1) return r<a.r;
        else return r>a.r;
    }
} query[mx];

void dfs(int u,int par)
{
    st[u]=++timer;

    for(int v: graph[u])
        if(v!=par)
            dfs(v,u);

    en[u]=timer;
}

inline void update(int idx,int val)
{
    if(idx<1) return;
    while (idx<mx)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

inline int Query(int idx)
{
    int sum=0;

    while (idx>=1)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }

    return sum;
}

inline void Add(int idx)
{
    int col=conv_ara[idx];

    color_cnt[col]++;

    if(color_cnt[col]>0)
    {
        update(color_cnt[col]-1,-1);
        update(color_cnt[col],1);
    }

}
inline void Remove(int idx)
{
    int col=conv_ara[idx];

    color_cnt[col]--;

    if(color_cnt[col]>=0)
    {
        update(color_cnt[col]+1,-1);
        update(color_cnt[col],1);
    }
}
int main()
{
    int node,que;

    scanf("%d %d",&node,&que);

    for(int i=1; i<=node; i++) 
     scanf("%d",color+i);

    for(int i=1; i<node; i++)
    {
        int u,v;

        scanf("%d %d",&u,&v);

        graph[u].push_back(v);

        graph[v].push_back(u);
    }

    dfs(1,-1);

    for(int i=1; i<=node; i++)
    {
        conv_ara[st[i]]=color[i];
    }

    for(int i=1; i<=que; i++)
    {
        int u,x;

        scanf("%d %d",&u,&x);

        query[i].id=i;
        query[i].l=st[u];
        query[i].r=en[u];
        query[i].k=x;
    }

    sort(query+1,query+que+1);

    int L=1,R=0;

    for(int i=1; i<=que; i++)
    {
        int l=query[i].l;
        int r=query[i].r;
        int k=query[i].k;
        while (L<l)
        {
            Remove(L);
            L++;
        }
        while (L>l)
        {
            L--;
            Add(L);
        }
        while (R<r)
        {
            R++;
           Add(R);
        }
        while (R>r)
        {
            Remove(R);
            R--;
        }

        ans[query[i].id]=Query(mx-1)-Query(k-1);

    }


    for(int i=1;i<=que;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}