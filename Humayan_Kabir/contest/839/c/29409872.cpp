#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> adj[100007];
ll vis[100007],d[100007],level[100007],leaf[100007];

double ans=0.0;

void dfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u]=1;
    level[u]=0;
    d[u]=0;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        int foo=1;
        for(int i=0; i<adj[v].size(); i++)
        {
            int x=adj[v][i];
            if(!vis[x])
            {
                vis[x]=1;
                level[x]=level[v]+1;
                d[v]++;
                q.push(x);
                foo=0;
            }
        }
        if(foo)
        {
            leaf[v]=1;
        }
    }
}

void dfs2(int u,double pro)
{
   if(leaf[u]==1)
   {
       ans+=(double)level[u]*pro;
       return;
   }
   vis[u]=1;
   for(int i=0;i<adj[u].size();i++)
   {
       int v=adj[u][i];
       if(!vis[v])
       {
           double x=(1.0/(double)d[u]);
           dfs2(v,x*pro);
       }
   }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    memset(vis,0,sizeof vis);

    dfs2(1,1.0);

    cout<<setprecision(10)<<fixed<<ans<<endl;

    return 0;

}
