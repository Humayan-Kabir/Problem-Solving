#include<bits/stdc++.h>
using namespace std;
long double ans=0.0;
vector<int> adj[100007];
void dfs(int u,int par,int len)
{
    ans+=(1.0/(long double)len);
    for(int v: adj[u])
    {
        if(v==par) continue;
        else dfs(v,u,len+1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,1);
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
