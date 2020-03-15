#include<bits/stdc++.h>
using namespace std;
const int N=223456;
vector<int> adj[N];
int color[N];
int mxclr=-1;
int n;
void dfs(int u,int cl,int pr,int prcl)
{
    color[u]=cl;
    mxclr=max(cl,mxclr);
    int cntclr=1;
    for(int v:adj[u])
    {
        if(v==pr) continue;
        while(cntclr==cl || cntclr==prcl)
            cntclr++;
        dfs(v,cntclr,u,cl);
        cntclr++;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1,-1,0);

    cout<<mxclr<<endl;

    for(int i=1;i<=n;i++)
    {

        if(i==1) cout<<color[i];
        else cout<<" "<<color[i];
    }

    cout<<endl;

    return 0;
}
