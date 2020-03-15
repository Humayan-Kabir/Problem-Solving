#include<bits/stdc++.h>
#define pii pair<int,int>
#define mx 100005
using namespace std;
vector<pair<int,int> > adj[mx];
int dis[mx],p[mx],vis[mx],node,edge;

void a(){
 for (int i=0;i<=node ;i++ )
  dis[i]=INT_MAX;
}

struct data{
int nod,cost;
bool operator<(const data &x) const{
return cost>x.cost;
}
};

void dijkstra(int s){
dis[s]=0;
data u,v;
u.nod=s;
u.cost=0;
priority_queue<data> Q;
Q.push(u);
p[s]=0;
while (!Q.empty())
{
  v=Q.top();
  int pc=v.cost;
  Q.pop();
  if(vis[v.nod]==0){
    for (int i=0;i<adj[v.nod].size();i++ )
    {
       int nd=adj[v.nod][i].first;
       int c=adj[v.nod][i].second;
       if(dis[nd]>(pc+c) && vis[nd]==0){

        dis[nd]=pc+c;
        u.nod=nd;
        u.cost=dis[nd];
        Q.push(u);
        p[nd]=v.nod;
       }
    }
  }
  vis[v.nod]=1;

}
}

void path(int nd){
if(p[nd]==0) return;
path(p[nd]);
if(p[nd]==1)
    printf("%d",1);
else
   printf(" %d",p[nd]);

}


int main()
{
   int i,j,k,u,v,w;
   while (cin>>node>>edge)
   {
     for (i=1;i<=edge ;i++ )
     {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
     }
     memset(vis,0,sizeof vis);
     a();
     dijkstra(1);
     if(dis[node]==INT_MAX){
        cout<<-1<<endl;
     }
     else{
        path(node);
        printf(" %d\n",node);
     }
     for (i=0;i<=node ;i++ )
     {
        adj[i].clear();
     }

   }

   return 0;
}
