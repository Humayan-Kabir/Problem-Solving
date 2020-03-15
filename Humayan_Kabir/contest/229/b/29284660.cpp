#include<bits/stdc++.h>
#define mx 100007
using namespace std;
vector< pair<int,int> > graph[mx];
vector<int> s[mx];
int vis[mx],dist[mx],n,m;

struct edge
{
    int node,weight;
    bool operator< (const edge a) const
    {
        return weight>a.weight;
    }
};

void ini()
{
    for(int i=1; i<=n; i++) dist[i]=INT_MAX;
}

void dijkstra(int start)
{
    dist[start]=0;
    edge st;
    st.node=start;
    st.weight=0;
    priority_queue<edge> PQ;
    PQ.push(st);
    while (!PQ.empty())
    {
        edge x=PQ.top();
        int from=x.node;
        int cost=x.weight;
        PQ.pop();
        for(int i=0;i<s[from].size();i++)
        {
            if(cost==s[from][i]) cost++;
        }
        if(vis[from]==0)
        {
            for(auto u:graph[from])
            {
                int to=u.first;
                int weight=u.second;
                int dis=weight+cost;

                if(!vis[to] && dist[to]>=dis)
                {
                    dist[to]=dis;
                    edge xx;
                    xx.node=to;
                    xx.weight=dis;
                    PQ.push(xx);
                }
            }
        }

        vis[from]=1;

    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int time;
            cin>>time;
            s[i].push_back(time);
        }
    }

    ini();

    dijkstra(1);

    if(dist[n]==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<dist[n]<<endl;
    }

     // cout<<" input  ok "<<endl;
    return 0;
}
