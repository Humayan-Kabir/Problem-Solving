#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
LL n, st[mx], en[mx], level[mx], treeA[4 * mx], treeB[4 * mx], lazyA[4 * mx], lazyB[4 * mx],Timer = 0;
void dfs(int u, int par)
{
    level[u] = level[par] + 1;
    st[u] = ++Timer;
    for(int v : graph[u])
        if(v != par)
            dfs(v,u);
    en[u] = Timer;
}
inline void push_downA(int node,int l,int r, int val)
{
    if(lazyA[node] == 0) return;
    treeA[node] = (treeA[node] + val + mod) % mod;
    lazyA[node] = 0;
    if(l != r)
    {
        lazyA[node + node] = (lazyA[node + node] + val + mod) % mod;
        lazyA[node + node + 1] = (lazyA[node + node + 1] + val + mod) % mod;
    }
    return;
}
void updateA(int node,int l,int r,int x, int y, int val)
{
    push_downA(node,l,r,lazyA[node]);
    if(l > y || r < x) return;
    if(l >= x && r <= y)
    {
        lazyA[node] = (lazyA[node] + val + mod) % mod;
        push_downA(node,l,r,lazyA[node]);
        return;
    }
    int mid = (l + r) / 2;
    updateA(2 * node, l, mid, x, y, val);
    updateA(2 * node + 1, mid + 1, r, x, y, val);
    treeA[node] = (treeA[node + node] + treeA[node + node + 1] + mod) % mod;
}
inline void push_downB(int node,int l,int r, int val)
{
    if(lazyB[node] == 0) return;
    treeB[node] = (treeB[node] + val + mod) % mod;
    lazyB[node] = 0;
    if(l != r)
    {
        lazyB[node + node] = (lazyB[node + node] + val + mod) % mod;
        lazyB[node + node + 1] = (lazyB[node + node + 1] + val + mod) % mod;
    }
    return;
}
void updateB(int node,int l,int r,int x, int y, int val)
{
    push_downB(node,l,r,lazyB[node]);
    if(l > y || r < x) return;
    if(l >= x && r <= y)
    {
        lazyB[node] = (lazyB[node] + val + mod) % mod;
        push_downB(node,l,r,lazyB[node]);
        return;
    }
    int mid = (l + r) / 2;
    updateB(2 * node, l, mid, x, y, val);
    updateB(2 * node + 1, mid + 1, r, x, y, val);
    treeB[node] = (treeB[node + node] + treeB[node + node + 1] + mod) % mod;
}

int queryA(int node,int l,int r, int x,int y)
{
    push_downA(node,l,r,lazyA[node]);
    if(l > y || r < x) return 0;
    if(l >= x && r <= y) return treeA[node];
    int mid = (l + r) / 2;
    int ret = (queryA(node + node, l, mid, x, y) + queryA(node + node + 1, mid + 1, r, x, y) + mod) % mod;
    treeA[node] = (treeA[node + node] + treeA[node + node + 1] + mod) % mod;
    return ret;
}
int queryB(int node,int l,int r, int x,int y)
{
    push_downB(node,l,r,lazyB[node]);
    if(l > y || r < x) return 0;
    if(l >= x && r <= y) return treeB[node];
    int mid = (l + r) / 2;
    int ret = (queryB(node + node, l, mid, x, y) + queryB(node + node + 1, mid + 1, r, x, y) + mod) % mod;
    treeB[node] = (treeB[node + node] + treeB[node + node + 1] + mod) % mod;
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i = 2; i<=n; i++)
    {
        int par;
        scanf("%d",&par);
        graph[par].push_back(i);
    }
    dfs(1,1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type == 1)
        {
            int node, x, k;
            scanf("%d %d %d",&node,&x,&k);
            LL val = (1LL*x + 1LL * level[node]*k + mod) % mod;
            updateA(1,1,n,st[node],en[node],val);
            updateB(1,1,n,st[node],en[node],k);
        }
        else
        {
            int node;
            scanf("%d",&node);
            LL ans = (1LL * queryA(1,1,n,st[node],st[node]) - 1LL * level[node] * queryB(1,1,n,st[node],st[node])) % mod;\
            ans = (ans + mod) % mod;
            printf("%lld\n",ans);
        }

    }
    return 0;
}
