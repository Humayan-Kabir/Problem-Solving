#include<bits/stdc++.h>
#define mx 100002
using namespace std;
typedef long long int LL;
vector<int> adj[mx];
vector<int> vt[102];
int vis[mx],dis[102][mx],n,m,k,s;
struct data
{
    int nd,weight;
    bool operator <(const data a) const
    {
        return weight > a.weight;
    }
};
inline void ini()
{
    for(int i = 1; i<=100; i++)
    {
        for(int j = 1; j<=100000; j++)
        {
            dis[i][j] = INT_MAX;
        }
    }
}
void dijkstra(int kk)
{
    priority_queue<data> Q;
    for(int s : vt[kk])
    {
        dis[kk][s] = 0;
        data from;
        from.nd = s;
        from.weight = 0;
        Q.push(from);
    }
    memset(vis,0,sizeof vis);
    while (!Q.empty())
    {
        data uu=Q.top();
        Q.pop();
        int u,w;
        u=uu.nd;
        w=uu.weight;
        if(vis[u]==0)
        {
            for (int v : adj[u])
            {
                if(vis[v]==0 && dis[kk][v] > w + 1)
                {
                    dis[kk][v] = w + 1;
                    data vv;
                    vv.nd = v;
                    vv.weight = w + 1;
                    Q.push(vv);
                }
            }
        }
        vis[u]=1;
    }
}
int main()
{
    ini();
    scanf("%d %d %d %d",&n,&m,&k,&s);
    for(int i = 1; i<=n; i++)
    {
        int id;
        scanf("%d",&id);
        vt[id].push_back(i);
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=k; i++)
    {
        dijkstra(i);
    }
    for(int i = 1; i<=n; i++)
    {
        vector<int> ans;
        for(int j = 1; j<=k; j++)
        {
            ans.push_back(dis[j][i]);
        }
        sort(ans.begin(),ans.end());
        LL total = 0;
        for(int i = 0; i < s; i++) total += ans[i];
        if(i == 1)
        printf("%lld", total);
        else
            printf(" %lld",total);
    }
    return 0;
}

