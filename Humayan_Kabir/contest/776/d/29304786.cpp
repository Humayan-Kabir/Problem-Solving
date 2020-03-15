#include<bits/stdc++.h>
#define mx 200007
using namespace std;
int status[mx],vis[mx],scc[mx];
vector<int> graph[mx],door[mx];
vector<int> topsort;

void DFS(int u)
{
    vis[u]=1;
    for(int v: graph[u])
        if(!vis[v])
            DFS(v);

    topsort.push_back(u);
}

int region=0;

void SCC(int u)
{
    scc[u]=region;
    for(int v: graph[u])
        if(!scc[v])
            SCC(v);
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) cin>>status[i];
    for(int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        while (k--)
        {
            int id;
            cin>>id;
            door[id].push_back(i);
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(!status[i])
        {
            int p=door[i][0];
            int q=door[i][1];

            graph[p+m].push_back(q);
            graph[q+m].push_back(p);
            graph[p].push_back(q+m);
            graph[q].push_back(p+m);
        }
        else
        {
            int p=door[i][0];
            int q=door[i][1];

            graph[p+m].push_back(q+m);
            graph[q+m].push_back(p+m);
            graph[p].push_back(q);
            graph[q].push_back(p);
        }
    }

    for(int i=1; i<=2*m; i++)
    {
        if(!vis[i]) DFS(i);
    }

    reverse(topsort.begin(),topsort.end());

    for(int i=0; i<topsort.size(); i++)
    {
        if(!scc[topsort[i]])
        {
            ++region;
            SCC(topsort[i]);
        }
    }

    int foo=0;

    for(int i=1; i<=m; i++)
    {
        if(scc[i]==scc[i+m])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    
    //"second submission"

    return 0;
}
