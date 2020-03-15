#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100007],vt;
int initial[100007],now[100007],cnt;
void dfs(int u,int par,int e_flip,int level,int o_flip)
{
    for(int v: graph[u])
    {
        if(v==par) continue;
        if((level+1)&1)
        {

            if((o_flip && !initial[v]==now[v]) || (!o_flip && initial[v]==now[v])) dfs(v,u,e_flip,level+1,o_flip);
            else cnt++,vt.push_back(v),dfs(v,u,e_flip,level+1,!o_flip);
        }
        else
        {
            if((e_flip && !initial[v]==now[v]) || (!e_flip && initial[v]==now[v])) dfs(v,u,e_flip,level+1,o_flip);
            else cnt++,vt.push_back(v),dfs(v,u,!e_flip,level+1,o_flip);
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++) cin>>initial[i];
    for(int i=1; i<=n; i++) cin>>now[i];
    if(initial[1]!=now[1]) cnt++,vt.push_back(1),dfs(1,-1,1,0,0);
    else
    dfs(1,-1,0,0,0);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        if(!i) cout<<vt[i];
        else cout<<" "<<vt[i];
    }
    cout<<endl;
    return 0;
}
